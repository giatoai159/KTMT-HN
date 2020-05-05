#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Qfloat
{
	char arrBits[16];
};
void init(Qfloat&);




std::string stringDecToBin(string s);

string convertAfterComma(string s);
string subStringBit(string b1, string b2);

void Div2ToPrint(std::string&);


string QfloatToStringBin(string s); //(*)
Qfloat ConvertStringToQfloat(string s);
void ScanQfloat(Qfloat&); //(*)

string x5(string str);
string Pow5(int x);
string PowNegativeTwo(int x);

void PrintQfloat(Qfloat&); //(*)
string QfloatBitToString(string bit); //(*)