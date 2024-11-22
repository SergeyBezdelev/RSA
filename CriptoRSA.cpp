#include <windows.h>
#include <iostream>
#include <fstream >
#include <string>
#include <random>
#include <cmath>
#include "BigInt.h"

using namespace std;

string message, cod, decod;
BigInt* C;
struct Key {
	long pow;
	long mod;
};
Key Open, Close;
void Menu();
void MakeKeys();
unsigned long Get_E(long m);
unsigned long Get_D(unsigned long d, long m);
char GetNumSymbol(char Mes);
void Coder();
void Decoder();
BigInt MyPow(char Baza, long Stepen);


int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	return 1;
};

//����� ��������
void Menu() {
	int M0 = 0, M1 = 0, M2 = 0, M3 = 0;
	bool Exit = true;
	string key = "";
	while (Exit)
	{
		M0 = 0;
		cout << endl;
		cout << "1.������� ����" << endl;
		cout << "2.������� �����" << endl;
		cout << "3.���������� �����" << endl;
		cout << "4.����� �� ���������" << endl ;
		cout << endl;
		cout << "������� ����� ������ : ";
		cin >> M0;
		cout << endl;
		cin.ignore(1);
		switch (M0)
		{
		case 1://---�������� ������---
			MakeKeys();
			break;
		case 2://---����� ������---
			cout << endl;
			cout << "������� ����� ��� ���������" << endl;
			cout << "1.������ ����� �� ����" << endl;
			cout << "2.����� �� ������" << endl;
			cout << endl;
			cout << "������� ����� ������ : ";
			cin >> M1;
			cin.ignore(1);
			switch (M1)
			{
			case 1:
				message.clear();
				getline(cin, message);
				break;
			case 2:
				break;
			default:
				cout << "�������� ����� ����!" << endl;
				break;
			}
			M1 = 0;
			break;

		case 3://---��������� ������----
			Coder();
			Decoder();
			break;
		case 4://---����� �� ���������---
			Exit = false;
			break;
		default:
			cout << "�������� ����� ����!" << endl;
			Exit = true;
			break;
		}
		M0 = 0;
	}
	return;
}

void MakeKeys() {
	long p = 97;
	long q = 83;
	Open.mod = Close.mod = p * q;
	long m = (p - 1) * (q - 1);
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "m = " << m << endl;
	Open.pow = Get_E(m);
	Close.pow = Get_D(Open.pow, m);
	//����� e � n � ��� �������� ����, � ����� d � n � ��� �������� ����;
	cout << "�������� ���� : � = " << Open.pow << ",  N = " << Open.mod << endl;
	cout << "�������� ���� : D = " << Close.pow << ",  N = " << Close.mod << endl;
	return;
}

unsigned long Get_E(long m)
{
	long e = 257;
	bool DivIs = false;
	while (true) {
		for (long i = 2; i < m; i++)
			if ((m % i == 0) && (e % i == 0)) //���� ����� ����� ��������
			{
				DivIs = true;
				break;
			}
		if (DivIs) {
			e = e - 1;
			DivIs = false;
		}
		else
			break;
	}
	return e;
}

unsigned long Get_D(unsigned long e, long m)
{
	unsigned long d = 25;
	while (true)
	{
		if ((d * e) % m == 1)
			break;
		else
			d++;
	}
	return d;
}


void Coder() {
	string Azbuka = "�����Ũ���������������������������������������������������������� ,.:;!";
	C = new BigInt[message.length()];
	char ch = 0;
	cod.clear();
	for (int i = 0; i < message.length(); i++) {
		ch = GetNumSymbol(message.at(i));
		BigInt tmp(to_string(ch));
		C[i] = tmp;
		tmp = C[i].pow(Open.pow);
		C[i] = tmp % Open.mod;
		cout << C[i].getValue() << " , ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << cod << endl;
}

void Decoder() {
	string Azbuka = "�����Ũ���������������������������������������������������������� ,.:;!";
	decod.clear();
	cout << endl << endl;
	cout << "����������" << endl;
	for (int i = 0; i < message.length(); i++) {
		BigInt tmp = C[i].pow(Close.pow);
		C[i] = tmp % Close.mod;
		unsigned short result = strtol(C[i].getValue().c_str(), NULL, 10);
		decod.push_back(Azbuka.at(result));
		cout << Azbuka.at(result) ;
	}
}

char GetNumSymbol(char Mes) {
	string Azbuka = "�����Ũ���������������������������������������������������������� ,.:;!";
	for (char i = 0; i < 72; i++)
		if (Mes == Azbuka.at(i))
			return i;
	cout << "������ �� ��������� �� ������ � ����������� ��� ������������� ����� ��������" << endl;
	return -1;
}
string MakeNumber(const int size) {
	random_device rd;
	mt19937 gen(rd());
	char a;
	string param;
	param.clear();
	for (int i = 1; i <= size; i++) {
		uniform_int_distribution<int> dist(0, 255);
		a = dist(gen);
		param.push_back(a);
	}
	return param;
}


BigInt MyPow(char Baza, long Stepen) {
	BigInt tmp = Baza;
	for (long i = 2; i <= Stepen; i++) {
		tmp = tmp * Baza;
	}
	return tmp;
}