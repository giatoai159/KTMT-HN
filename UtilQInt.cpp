#include "UtilQInt.h"

using namespace std;

std::string _2powN[129];

void init() {
	for (int i = 0; i <= 128; ++i) {
		_2powN[i].assign(_2PowN(i));
	}
}

QInt ConvertStringToQInt(string s) {
	QInt res;

	//check s is negative or positive
	bool sign = 0;
	if (s[0] == '-') {
		sign = 1;
		s = s.substr(1, s.length() - 1);
	}

	bool bit;
	int index = 0;
	while (s != "") {
		bit = (s.back() - '0') % 2; // "749846516461641679 % 2 = 1, 16579848984812 % 2 = 0"
		SetBit(res, index, bit);
		Div2(s); // s /= 2
		++index;
	}

	//if it is a negative number => GetTwoComplement
	if (sign == 1) {
		res = GetTwoComplement(res);
		SetBitSign(res);
	}

	return res;
}

string AddBigInt(string A, string B) {
	string res = "";

	while (A.length() < B.length()) A = "0" + A;
	while (B.length() < A.length()) B = "0" + B;

	bool surplus = 0;
	for (int i = A.length() - 1 ; i >= 0 ; --i)
	{
		int sum = (A[i] - '0') + (B[i] - '0') + surplus;

		surplus = sum / 10;

		sum = sum % 10;
		res += sum + '0';
	}

	if (surplus > 0) res += '1';

	return string(res.rbegin(), res.rend());
}

string SubBigInt(string A, string B) {
	string res = "";

	while (B.length() < A.length()) B = "0" + B;

	bool surplus = 0;
	for (int i = A.length() - 1; i >= 0; --i)
	{
		int sub;

		char chA = A[i] - '0';
		char chB = B[i] - '0' + surplus;

		if (chA < chB) {
			sub = ((chA + 10) - (chB % 10)) % 10;
			surplus = 1;
		}
		else {
			sub = chA - chB;
			surplus = 0;
		}
			
		res += sub + '0';
	}

	int countZeroAtBack = 0;
	int index = res.length() - 1;
	while (res[index] == '0') {
		++countZeroAtBack;
		--index;
	}

	res = res.substr(0, res.length() - countZeroAtBack);
	res += '-';

	return string(res.rbegin(), res.rend());
}

bool GetBit(char byte, int index) {
	return (byte >> index) & 1;
}

bool GetBitSign(const QInt& x) {
	return GetBit(x.arrBits[0], 7);
}

void OnBit(char& byte, int index) {
	byte |= (1 << index);
}

void OffBit(char& byte, int index) {
	byte &= 255 - (int)(pow(2, index));
}

bool CheckInput(string& input) {
	int start = 0;

	if (input[0] == '-') {
		start = 1;
	}

	for (int i = start; i < input.length(); ++i) {
		if (input[i] < '0' || input[i] > '9') {
			return false;
		}
	}

	/*
		0000012164 => 12164 
	*/

	int countZeroAtBegin = 0;
	int index = start;

	while (input[index] == '0') {
		++countZeroAtBegin;
		++index;
	}

	if (countZeroAtBegin != 0)
		input = input.substr(index, input.length() - countZeroAtBegin);

	return true;
}

void SetBit(QInt& x, int index, bool bit) {
	if (bit)
		x.arrBits[15 - index / 8] |= 128 >> (7 - index % 8);
}

void SetBitSign(QInt& x) {
	OnBit(x.arrBits[0], 7);
}

void Div2(string& strNumbers) {
	string res = "";
	bool surplus = 0;
	int strNumbersLen = strNumbers.length();

	for (int i = 0; i < strNumbersLen; ++i) {
		int devidend = surplus * 10 + strNumbers[i] - '0';

		res += devidend / 2 + '0';

		surplus = devidend - (res.back() - '0') * 2;
	}

	if (res[0] == '0')
		res = res.substr(1, res.length() - 1);
	strNumbers = res;
}

int Div16(string& strNumbers) {
	string res = "";
	int surplus = 0;
	int strNumbersLen = strNumbers.length();

	for (int i = 0; i < strNumbersLen; ++i) {
		int devidend = surplus * 10 + strNumbers[i] - '0';

		res += devidend / 16 + '0';

		surplus = devidend - (res.back() - '0') * 16;
	}

	if (res[0] == '0')
		res = res.substr(1, res.length() - 1);
	strNumbers = res;

	return surplus;
}

string GetQIntValue(const QInt& x) {
	string res = "";
	bool bitSign = GetBit(x.arrBits[0], 7);

	int bitIndex = 127;
	for (int byteIndex = 0; byteIndex < 16; ++byteIndex) {
		for (int i = 7; i >= 0; --i) {
			bool bit = GetBit(x.arrBits[byteIndex], i);

			if (bit && bitIndex != 127)
				res = AddBigInt(res, _2powN[bitIndex]);

			--bitIndex;
		}
	}

	if (bitSign) {
		res = SubBigInt(_2powN[127], res);
	}

	if (res.empty())
		res = "0";

	return res;
}

string _2PowN(int n) {
	if (n == 0)
		return "1";
	
	string res = "";

	string _2powN_1(_2powN[n - 1]);
	bool surplus = 0;

	for (int j = _2powN_1.length() - 1; j >= 0; --j) {
		char multiplicationRes = 2 * (_2powN_1[j] - '0') + surplus;
		surplus = multiplicationRes / 10;
		res += multiplicationRes % 10 + '0';
	}

	if (surplus)
		res += '1';

	return string(res.rbegin(), res.rend());
}

QInt GetOneComplement(const QInt& x) {
	QInt res = x;

	return ~res;
}

QInt GetTwoComplement(const QInt& x) {
	QInt res = GetOneComplement(x);

	bool surplus = 1;

	int byteIndex = 15, bitIndex = 0;
	while (surplus) {
		bool bit = GetBit(res.arrBits[byteIndex], bitIndex);
		
		char sumBit = surplus + bit;

		if (sumBit % 2 == 0)
			OffBit(res.arrBits[byteIndex], bitIndex);
		else
			OnBit(res.arrBits[byteIndex], bitIndex);

		surplus = sumBit / 2;

		++bitIndex;
		if (bitIndex == 8) {
			bitIndex = 0;
			--byteIndex;

			if (byteIndex == -1)
				break;
		}
	}

	return res;
}

QInt GetABS(const QInt& x) {
	bool sign = GetBitSign(x);

	if (sign)
		return GetTwoComplement(x);
	else
		return x;
}

char ComparePositive(const QInt& a, const QInt& b) {
	string aValue = GetQIntValue(a);
	string bValue = GetQIntValue(b);

	if (aValue.length() > bValue.length())
		return 1;
	else if (aValue.length() < bValue.length())
		return 0;
	else {
		for (int i = 0; i < aValue.length(); ++i)
			if (aValue[i] != bValue[i])
				return aValue[i] > bValue[i];
	}

	return -1;
}

char CompareNegative(const QInt& a, const QInt& b) {
	string aValue = GetQIntValue(a);
	string bValue = GetQIntValue(b);

	if (aValue.length() < bValue.length())
		return 1;
	else if (aValue.length() > bValue.length())
		return 0;
	else {
		for (int i = 0; i < aValue.length(); ++i)
			if (aValue[i] != bValue[i])
				return aValue[i] < bValue[i];
	}

	return -1;
}