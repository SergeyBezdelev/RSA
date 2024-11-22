#pragma once

#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>

class BigInt {
	std::string value; // �������� �����
	bool isNeg; // ���� ���������������

	static BigInt karatsuba_mul(const BigInt& a, const BigInt& b); // ��������� ������� ��������

public:
	BigInt(); // ����������� ��������� (����� ����� ����)
	BigInt(long x); // ����������� �������������� �� �������� ������ �����
	BigInt(const std::string& value); // ����������� �������������� �� ������
	BigInt(const BigInt& bigInt); // ����������� �����������

	const std::string& getValue() const; // ��������� ����������� ������ (������ ������ �����)

	const bool getIsNeg() const; // ��������� ����� ��������������� �����
	void setIsNeg(bool isNeg); // ��������� ����� ��������������� �����

	int sign() const; // ��������� ����� �����
	const bool isEven() const; // �������� �� ��������

	BigInt abs() const; // ��������� ������ �����
	BigInt pow(long n) const; // ��������� ����� � ������� n
	BigInt sqrt(long n = 2) const; // ���������� ����� n-�� ������� �� �����

	// �������� ���������
	const bool operator==(const BigInt& bigInt) const;
	const bool operator!=(const BigInt& bigInt) const;

	const bool operator<(const BigInt& bigInt) const;
	const bool operator>(const BigInt& bigInt) const;
	const bool operator<=(const BigInt& bigInt) const;
	const bool operator>=(const BigInt& bigInt) const;

	// �������� ������������
	BigInt& operator=(const BigInt& bigInt);

	// ������� ���� � �����
	BigInt operator+() const&&;
	BigInt operator-() const&&;

	// �������������� ��������
	BigInt operator+(const BigInt& bigInt) const;
	BigInt operator-(const BigInt& bigInt) const;
	BigInt operator*(const BigInt& bigInt) const;
	BigInt operator/(const BigInt& bigInt) const;
	BigInt operator%(const BigInt& bigInt) const;
	BigInt operator<<(size_t n) const;
	BigInt operator>>(size_t n) const;

	// ������� ����� ��������
	BigInt& operator+=(const BigInt& bigInt);
	BigInt& operator-=(const BigInt& bigInt);
	BigInt& operator*=(const BigInt& bigInt);
	BigInt& operator/=(const BigInt& bigInt);
	BigInt& operator%=(const BigInt& bigInt);
	BigInt& operator<<=(size_t n);
	BigInt& operator>>=(size_t n);

	// ���������� �����
	BigInt& operator++(); // ++v
	BigInt& operator--(); // --v

	// ����������� �����
	BigInt operator++(int); // v++
	BigInt operator--(int); // v--


	friend std::ostream& operator<<(std::ostream& stream, const BigInt& bigInt); // ����� ����� � �������� �����
	friend std::istream& operator>>(std::istream& stream, BigInt& bigInt); // ���� ����� �� �������� ������
};

#endif
