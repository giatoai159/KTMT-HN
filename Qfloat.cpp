﻿#include "Qfloat.h"
#include "Util.h"

using namespace std;

void init(Qfloat& q) {
	for (int i = 0; i < 16; ++i)
		q.arrBits[i] = 0;
}

string stringDecToBin(string s)
{
	string res = "";
	while (!s.empty())
	{
		if ((s.back() - '0') % 2 == 0)
			res = "0" + res;
		else if ((s.back() - '0') % 2 == 1)
			res = "1" + res;
		Div2(s);
	}
	return res;
}

string convertAfterComma(string s)  //Ham doi string sau dau phay thanh string bit
{
	//Y tuong:
	//VD: 0.84375 => string 84375
	//Neu string x2 co so 1 o dau va co lenght gap doi ban dau thi loai bot so 1 o dau
	//Neu string co so 0 o sau thi loai so 0
	string res = "";
	int count = 0;
	while (1)
	{
		string temp = s;
		s = AddBigInt(s, s);
		if (s.length() - 1 == temp.length() && s[0] == '1')
		{
			res += '1';
			if (s[s.length() - 1] == '0')
				s.pop_back();
			s.erase(0, 1);
		}
		else
			res += '0';
		if (s == "1" || s.empty() || s == "0" || count > 16383)
			break;
		count++;
	}
	return res;
}

string subStringBit(string b1, string b2)
{
	string res = "";
	while (b1.length() < b2.length())
		b1 = "0" + b1;
	while (b1.length() > b2.length())
		b2 = "0" + b2;
	bool miss = 0;
	int len = b1.length();
	while (!b1.empty() && !b2.empty())
	{
		int sum = b1.back() - '0' + b2.back() - '0' + miss;
		if (sum == 2)
		{
			res = "0" + res;
			miss = 1;
		}
		else if (sum == 1)
		{
			res = "1" + res;
			miss = 0;
		}
		else if (sum == 0)
		{
			res = "0" + res;
			miss = 0;
		}
		else if (sum == 3)
		{
			res = "1" + res;
			miss = 1;
		}
		b1.pop_back();
		b2.pop_back();
	}
	return res;
}


bool GetBitSign_Float(const Qfloat& x) {
	return GetBit(x.arrBits[0], 7);
}

//bool CheckInput(string& input) {
//	int start = 0;
//
//	if (input[0] == '-') {
//		start = 1;
//	}
//
//	for (int i = start; i < input.length(); ++i) {
//		if (input[i] < '0' || input[i] > '9') {
//			return false;
//		}
//	}
//
//	int countZeroAtBegin = 0;
//	int index = start;
//
//	while (input[index] == '0') {
//		++countZeroAtBegin;
//		++index;
//	}
//
//	if (countZeroAtBegin != 0)
//		input = input.substr(index, input.length() - countZeroAtBegin);
//
//	return true;
//}

void SetBit_Float(Qfloat& x, int index, bool bit) {
	if (bit)
		//x.arrBits[15 - index / 8] |= 128 >> (7 - index % 8);
		OnBit(x.arrBits[15 - index / 8], index - (index / 8) * 8);
}

void SetBitSign_Float(Qfloat& x) {
	OnBit(x.arrBits[0], 7);
}

bool GetBit_Float(Qfloat q, int index)
{
	return GetBit(q.arrBits[15 - index / 8], index - (index / 8) * 8);
}


void Div2ToPrint(string& strNumbers) {
	string res = "";
	bool surplus = 0;
	int strNumbersLen = strNumbers.length();

	for (int i = 0; i < strNumbersLen; ++i) {
		int devidend = surplus * 10 + strNumbers[i] - '0';

		res += devidend / 2 + '0';

		surplus = devidend - (res.back() - '0') * 2;
	}
	strNumbers = res;
}

string QfloatToStringBin(string s)
{
	bool sign = 0;
	if (s[0] == '-') {
		sign = 1;
		s = s.substr(1, s.length() - 1);
	}
	int indexComma = 0;
	bool checkComma = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '.' || s[i] == ',')
		{
			indexComma = i;
			checkComma = 1;
		}
	string frontComma = "";
	string afterComma = "";
	if (checkComma)
	{
		frontComma = s.substr(0, indexComma);
		afterComma = s.substr(indexComma + 1, s.length() - 1);
	}
	else
	{
		frontComma = s;
		afterComma = "0";
		indexComma = frontComma.length();
	}

	// loai so 0 thua o truoc va sau input. VD: 0003.500000 => 3.5
	// neu truong hop 00000.50, frontComma rong thi gan frontComma = 0. Tuong tu voi afterComma
	int index = 0;
	while (frontComma[0] == '0')
	{
		frontComma = frontComma.substr(1, frontComma.length() - 1);
		index++;
	}
	while (!afterComma.empty())
	{
		if (afterComma.back() == '0')
			afterComma.pop_back();
		else break;
	}
	if (frontComma.empty())
		frontComma = "0";
	if (afterComma.empty())
		afterComma = "0";

	// is zero
	if (frontComma == "0" && afterComma == "0")
		return "0.0";

	string binFrontComma = stringDecToBin(frontComma);
	string binAfterComma = convertAfterComma(afterComma);

	bool check = 0;
	for (int i = 0; i < binFrontComma.length(); i++)
		if (binFrontComma[i] == '1')
			check = 1;
	// xác định exp bằng cách kiểm tra xem phần nguyên có số 1 nào không
	// - không: dịch sang phải
	// - có: dịch sang trái
	// cộng exp với 16383
	string exp = "";
	int e = 0;
	if (check == 1)
	{
		e = binFrontComma.length() - 1;
		binFrontComma = binFrontComma.substr(1, binFrontComma.length() - 1);
		binAfterComma = binFrontComma + binAfterComma;
		if (e >= -16382 && e <= 16383)
		{
			int temp = e;
			while (temp > 0)
			{
				exp = (char)((temp % 10) + '0') + exp;
				temp /= 10;
			}
			exp = AddBigInt(exp, "16383");
		}
	}
	else if (check == 0)
	{
		int i = 0;
		while (binAfterComma[i] == '0')
		{
			e++;
			i++;
			if (binAfterComma[i] == '1')
				break;
		}
		e++;
		while (i >= 0)
		{
			binAfterComma = binAfterComma.substr(1, binAfterComma.length() - 1);
			i--;
		}
		if (e <= 16383) {
			int temp = e;
			while (temp > 0)
			{
				exp = (char)((temp % 10) + '0') + exp;
				temp /= 10;
			}
			exp = SubBigInt("16383", exp);
			exp = exp.substr(1, exp.length() - 1);
		}
	};
	// is denormalized
	if (e < -16382)
	{
		int distance = -16382 - e;
		for (int i = 0; i < distance; i++)
			if (i == 0)
				binAfterComma = "1" + binAfterComma;
			else
				binAfterComma = "0" + binAfterComma;
		exp = "0";
	}
	string bit112ToBit126 = stringDecToBin(exp);
	while (bit112ToBit126.length() < 15)
		bit112ToBit126 = "0" + bit112ToBit126;
	string bit0ToBit111 = binAfterComma;
	while (bit0ToBit111.length() < 113)
		bit0ToBit111 += "0";
	while (bit0ToBit111.length() > 113)
		bit0ToBit111.pop_back();

	// is infinity
	if (e >= 16383)
	{
		bit112ToBit126 = "";
		while (bit112ToBit126.length() < 15)
			bit112ToBit126.push_back('1');
		exp = "0";
		while (bit0ToBit111.length() < 113)
			bit0ToBit111 += "0";
		while (bit0ToBit111.length() > 113)
			bit0ToBit111.pop_back();
	}

	// lam tron
	if (bit0ToBit111[112] == '1')
	{
		bit0ToBit111 = subStringBit(bit0ToBit111, "1");
		bit0ToBit111.pop_back();
	}
	else if (bit0ToBit111[112] == '0')
		bit0ToBit111.pop_back();

	string finalStringBit = "";
	if (sign)
		finalStringBit += '1';
	else finalStringBit += '0';
	finalStringBit += bit112ToBit126;
	finalStringBit += bit0ToBit111;
	return finalStringBit;
}

Qfloat ConvertStringToQfloat(string s) {
	Qfloat res;
	init(res);
	bool sign = 0;
	if (s[0] == '-') {
		sign = 1;
		s = s.substr(1, s.length() - 1);
	}
	// dua bit vao Qfloat
	if (sign)
		SetBitSign_Float(res);
	string finalStringBit = QfloatToStringBin(s);
	for (int i = 0; i < 127; i++)
		SetBit_Float(res, i, finalStringBit[127 - i] - '0');
	//cout << finalStringBit << endl;
	return res;
}

void ScanQfloat(Qfloat& q)
{
	string str;
	cin >> str;
	q = ConvertStringToQfloat(str);
}

string x5(string str)
{
	string res = str;
	res.push_back('0');
	Div2(res);
	return res;
}

string Pow5(int x)
{
	if (x == 1)
		return "5";
	return x5(Pow5(x - 1));
}

string PowNegativeTwo(int x)
{
	string res = "";
	res = Pow5(x);
	while (res.length() < x)
		res = "0" + res;
	return res;
}

void PrintQfloat(Qfloat& q)
{
	string res;
	// xu ly phan nguyen
	int exp = 0;
	for (int i = 126; i > 111; i--)
		if (GetBit_Float(q, i))
			exp += pow(2, i - 112);
	exp -= 16383;
	//xu ly phan thap phan
	string afterComma = "0";
	for (int i = 0; i < 112; i++)
		if (GetBit_Float(q, i))
			afterComma = AddBigInt(afterComma, PowNegativeTwo(112 - i));
	int indexComma = afterComma.length();
	afterComma = "1" + afterComma;
	if (exp >= 0 && exp <= 16383)
	{
		for (int i = 0; i < exp; i++)
			afterComma = AddBigInt(afterComma, afterComma);
		res = afterComma;
		res = res.insert(res.length() - indexComma, ".");
		if (GetBitSign_Float(q))
			res = "-" + res;
		cout << res;
	}
	else if (exp < 0)
	{
		string temp = afterComma;
		for (int i = 0; i < abs(exp); i++)
			Div2ToPrint(temp);
		res = temp.insert(temp.length() - indexComma, ".");
		if (GetBitSign_Float(q))
			res = "-" + res;
		cout << res;
	}
	else if (exp > 16383)
		cout << "inf";
}

string QfloatBitToString(string bit)
{
	string res;
	// xu ly phan nguyen
	int exp = 0;
	for (int i = 1; i < 16; i++)
		if (bit[i] == '1')
			exp += pow(2, 15 - i);
	exp -= 16383;
	//xu ly phan thap phan
	string afterComma = "0";
	for (int i = 16; i < 128; i++)
		if (bit[i] == '1')
			afterComma = AddBigInt(afterComma, PowNegativeTwo(i - 15));
	int indexComma = afterComma.length();
	afterComma = "1" + afterComma;
	if (exp >= 0 && exp <= 16383)
	{
		for (int i = 0; i < exp; i++)
			afterComma = AddBigInt(afterComma, afterComma);
		res = afterComma;
		res = res.insert(res.length() - indexComma, ".");
		if (bit[0] == '1')
			res = "-" + res;
	}
	else if (exp < 0)
	{
		string temp = afterComma;
		for (int i = 0; i < abs(exp); i++)
			Div2ToPrint(temp);
		res = temp.insert(temp.length() - indexComma, ".");
		if (bit[0] == '1')
			res = "-" + res;
	}
	else if (exp > 16383)
		res = "inf";
	return res;
}