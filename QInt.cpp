#include "QInt.h"
#include "Util.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

QInt QInt::ConvertStringToQInt(string s) {
	QInt res;

	bool sign = 0;
	if (s[0] == '-') {
		sign = 1;
		s = s.substr(1, s.length() - 1);
	}

	bool bit;
	int index = 0;
	while (s != "") {
		bit = (s.back() - '0') % 2;
		SetBit(res, index, bit);
		Div2(s);
		++index;
	}

	if (sign == 1) {
		res = GetTwoComplement(res);
		SetBitSign(res);
	}

	return res;
}

istream& operator >>(istream& in, QInt& x) {
	string input;
	in >> input;

	try {
		if (!CheckInput(input))
			throw  exception("Sorry, this type dosen't support that value");
	}
	catch (const exception& exp) {
		cerr << exp.what() << endl;
	}

	x = ConvertStringToQInt(input);

	return in;
}

ostream& operator << (ostream& out, const QInt& x) {
	out << GetQIntValue(x);

	return out;
}

bool* DecToBin(QInt x) {
	bool* arrBits = new bool[128];

	int index = 0;
	for (int byteIndex = 0; byteIndex < 16; ++byteIndex) {
		for (int bitIndex = 7; bitIndex >= 0; --bitIndex)
			arrBits[index++] = GetBit(x.arrBits[byteIndex], bitIndex);
	}

	return arrBits;
}

QInt BinToDec(bool* bit) {
	QInt res;

	int byteIndex = 0;
	int bitIndex = 7;

	for (int i = 0; i < 128; ++i) {
		if (bit[i])
			OnBit(res.arrBits[byteIndex], bitIndex);
		else
			OffBit(res.arrBits[byteIndex], bitIndex);

		--bitIndex;

		if (bitIndex == -1) {
			bitIndex = 7;
			++byteIndex;
		}
	}

	return res;
}

char* BinToHex(bool* bit) {
	static const string hexChar = "0123456789ABCDEF";
	char* res = new char[32];

	for (int i = 0; i < 128; i += 4) {
		char number = 0;
		for (int j = 0; j < 4; ++j) {
			if (bit[i + j])
				number += pow(2, 3 - j);
		}

		res[i / 4] = hexChar[number];	
	}

	return res;
}

char* DecToHex(QInt x) {
	static const string hexChar = "0123456789ABCDEF";
	char* res = new char[32];

	for (int i = 0; i < 32; ++i) {
		res[i] = '0';
	}

	string QIntvalue = GetQIntValue(x);
	 
	if (GetBitSign(x) == 0) {
		int surplus;
		int index = 31;

		while (QIntvalue != "") {
			surplus = Div16(QIntvalue);
			res[index--] = hexChar[surplus];
		}
	}
	else {
		res = BinToHex(DecToBin(x));
	}
	
	return res;
}

QInt QInt::operator+(const QInt& a) {
	QInt res;

	bool surplus = 0;
	for (int byteIndex = 15; byteIndex >= 0; --byteIndex) 
		for (int bitIndex = 0; bitIndex < 8; ++bitIndex) {
			char sum = GetBit(this->arrBits[byteIndex], bitIndex) + GetBit(a.arrBits[byteIndex], bitIndex) + surplus;

			if (sum % 2 == 0) 
				OffBit(res.arrBits[byteIndex], bitIndex);
			else
				OnBit(res.arrBits[byteIndex], bitIndex);

			surplus = sum / 2;
		}
	
	return res;
}

QInt QInt::operator-(const QInt& a) {
	QInt aTwoComplement = GetTwoComplement(a);

	return *this + aTwoComplement;
}

QInt QInt::operator *(const QInt& a) {
	QInt M = *this;
	QInt Q = a;
	QInt A;
	bool Q0;
	bool Q_1 = 0;

	int count = 128;
	while (count > 0) {
		Q0 = GetBit(Q.arrBits[15], 0);
		
		if (Q0 == 0 && Q_1 == 1) {
			A = A + M;	
		}
		else if (Q0 == 1 && Q_1 == 0) {
			A = A - M;
		}

		bool A0 = GetBit(A.arrBits[15], 0);
		A >> 1;
		Q >> 1;

		if (A0)
			OnBit(Q.arrBits[0], 7);
		else
			OffBit(Q.arrBits[0], 7);

		Q_1 = Q0;
		--count;
	}

	return Q;
}

QInt QInt::operator /(const QInt& a) {
	QInt Q = *this;
	QInt M = a;
	QInt A = 0;

	bool QSign = GetBitSign(Q);
	bool MSign = GetBitSign(M);
	bool flag = QSign == MSign;

	Q = GetABS(Q);
	M = GetABS(M);

	int count = 128;
	while (count > 0) {
		QSign = GetBitSign(Q);

		A << 1;
		if (QSign)
			OnBit(A.arrBits[15], 0);
		else
			OffBit(A.arrBits[15], 0);
		Q << 1;
		
		A = A - M;
		if (A < 0) {
			A = A + M;
		}
		else
			OnBit(Q.arrBits[15], 0);

		--count;
	}

	if (!flag)
		Q = GetTwoComplement(Q);

	return Q;
}

bool QInt::operator >(const QInt& a) {
	bool Sign = GetBitSign(*this);
	bool aSign = GetBitSign(a);

	if (Sign != aSign) {
		if (Sign == 0)
			return true;
		else
			return false;
	}
	else {
		if (Sign == 0) 
			return ComparePositive(*this, a) == 1;
		else
			return CompareNegative(*this, a) == 1;
	}
}

bool QInt::operator <(const QInt& a) {
	bool Sign = GetBitSign(*this);
	bool aSign = GetBitSign(a);

	if (Sign != aSign) {
		if (Sign == 1)
			return true;
		else
			return false;
	}
	else {
		if (Sign == 0)
			return ComparePositive(*this, a) == 0;
		else
			return CompareNegative(*this, a) == 0;
	}
}

bool QInt::operator ==(const QInt& a) {
	for (int i = 0; i < 16; ++i)
		if (arrBits[i] != a.arrBits[i])
			return false;

	return true;
}

bool QInt::operator !=(const QInt& a) {
	return !(*this == a);
}

bool QInt::operator <=(const QInt& a) {
	bool equal = *this == a;
	bool smaller = *this < a;

	return (equal || smaller);
}

bool QInt::operator >=(const QInt& a) {
	bool equal = *this == a;
	bool greater = *this > a;

	return (equal || greater);
}

QInt& QInt::operator&(const QInt& a) {
	for (int i = 0; i < 16; ++i) {
		this->arrBits[i] &= a.arrBits[i];
	}

	return *this;
}

QInt& QInt::operator|(const QInt& a) {
	for (int i = 0; i < 16; ++i) {
		this->arrBits[i] |= a.arrBits[i];
	}

	return *this;
}

QInt& QInt::operator^(const QInt& a) {
	for (int i = 0; i < 16; ++i) {
		this->arrBits[i] ^= a.arrBits[i];
	}

	return *this;
}

QInt& QInt::operator~() {
	for (int i = 0; i < 16; ++i) {
		this->arrBits[i] = ~this->arrBits[i];
	}

	return *this;
}

QInt& QInt::operator >>(int count) {
	bool* bits = DecToBin(*this);

	for (int i = 127; i >= count; --i) {
		bits[i] = bits[i - count];
	}

	for (int i = 0; i < count; ++i) {
		bits[i] = 0;
	}

	*this = BinToDec(bits);
	return *this;
}

QInt& QInt::operator <<(int count) {
	bool* bits = DecToBin(*this);

	for (int i = 0; i < 128 - count; ++i) {
		bits[i] = bits[i + count];
	}

	for (int i = 128 - count; i < 128; ++i) {
		bits[i] = 0;
	}

	*this = BinToDec(bits);

	return *this;
}

void ror(QInt& x, int count) {
	bool* bits = DecToBin(x);

	bool* rotateBits = new bool[count];

	for (int i = 0; i < count; ++i)
		rotateBits[i] = bits[128 - count + i];

	for (int i = 127; i >= count; --i)
		bits[i] = bits[i - count];

	for (int i = 0; i < count; ++i)
		bits[i] = rotateBits[i];

	x = BinToDec(bits);

	delete bits;
}

void rol(QInt& x, int count) {
	bool* bits = DecToBin(x);

	bool* rotateBits = new bool[count];

	for (int i = 0; i < count; ++i)
		rotateBits[i] = bits[i];

	for (int i = 0; i < 128 - count; ++i)
		bits[i] = bits[i + count];

	for (int i = 128 - count; i < 128; ++i)
		bits[i] = rotateBits[i - (128 - count)];

	x = BinToDec(bits);

	delete bits;
}

bool* HexToBin(char* hex) {
	static map<char, string> HexCharToBin;

	HexCharToBin['0'] = "0000";
	HexCharToBin['1'] = "0001";
	HexCharToBin['2'] = "0010";
	HexCharToBin['3'] = "0011";
	HexCharToBin['4'] = "0100";
	HexCharToBin['5'] = "0101";
	HexCharToBin['6'] = "0110";
	HexCharToBin['7'] = "0111";
	HexCharToBin['8'] = "1000";
	HexCharToBin['9'] = "1001";
	HexCharToBin['A'] = "1010";
	HexCharToBin['B'] = "1011";
	HexCharToBin['C'] = "1100";
	HexCharToBin['D'] = "1101";
	HexCharToBin['E'] = "1110";
	HexCharToBin['F'] = "1111";

	bool* res = new bool[128];
	int index = 0;

	for (int i = 0; i < 32; ++i)
		for (int j = 0; j < 4; ++j)
			res[index++] = HexCharToBin[hex[i]][j] - '0';

	return res;
}

QInt HexToDec(char* hex) {
	return BinToDec(HexToBin(hex));
}