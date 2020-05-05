#pragma once

#include <typeinfo>
#include <string>
#include <iostream>

#define MAX_QINT "170141183460469231731687303715884105727"
#define MIN_QINT "-170141183460469231731687303715884105728" 

/*
	QInt 16 bytes.  Like Big Endian
	[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15]

	in 1 byte
	bit:   [00000000]
	index: [76543210]
*/

class QInt {
public:
	char arrBits[16];
	
	// Set all bit is zero
	QInt() {
		for (int i = 0; i < 16; ++i)
			arrBits[i] = 0;
	}

	//using template class so cannot write this code in file .cpp
	template <class T>
	QInt(const T& x) {
		std::string number;

		if (typeid(T) == typeid(int))
			number = std::to_string((int)x);
		else if (typeid(T) == typeid(__int64))
			number = std::to_string((__int64)x);
		else
			number = x;
		*this = ConvertStringToQInt(number);
	}

	template <class T>
	QInt& operator=(const T& x) {
		std::string number;

		if (typeid(x) == typeid(int))
			number = std::to_string((int)x);
		else if (typeid(x) == typeid(__int64))
			number = std::to_string((__int64)x);
		else
			number = x;

		*this = ConvertStringToQInt(number);
		return *this;
	}

	QInt ConvertStringToQInt(std::string);

	QInt operator +(const QInt& a);
	QInt operator -(const QInt& a);
	QInt operator *(const QInt& a);
	QInt operator /(const QInt& a);
	bool operator >(const QInt& a);
	bool operator <(const QInt& a);
	bool operator ==(const QInt& a);
	bool operator !=(const QInt& a);
	bool operator <=(const QInt& a);
	bool operator >=(const QInt& a);
	QInt& operator &(const QInt& a);
	QInt& operator |(const QInt& a);
	QInt& operator ^(const QInt& a);
	QInt& operator ~();

	QInt& operator >>(int count);
	QInt& operator <<(int count);

	friend std::istream& operator >>(std::istream& in, QInt& x);
	friend std::ostream& operator <<(std::ostream& out, const QInt& x);
};

bool* DecToBin(QInt);
QInt BinToDec(bool*);
char* BinToHex(bool*);
char* DecToHex(QInt x);
QInt HexToDec(char*);
bool* HexToBin(char*);

//rotate right QInt x count bit
void ror(QInt& x, int count);

//rotate left QInt x count bit
void rol(QInt& x, int count);


