#pragma once
#include <iostream>
#include <string>
#include "Util.h"

using namespace std;
struct Qfloat
{
	char arrBits[16];
};
void init(Qfloat&);

std::string stringDecToBin(string s);

string convertAfterComma(string s);
string subStringBit(string b1, string b2);


//bool CheckInput(std::string&); ///????

void Div2ToPrint(std::string&);

bool GetBitSign_Float(const Qfloat& x);
void SetBit_Float(Qfloat&, int, bool);
bool GetBit_Float(Qfloat, int);
void SetBitSign_Float(Qfloat& x);

string QfloatToStringBin(string s); //(*)
Qfloat ConvertStringToQfloat(string s);
void ScanQfloat(Qfloat&); //(*)

string x5(string str);
string Pow5(int x);
string PowNegativeTwo(int x);

void PrintQfloat(Qfloat&); //(*)
string QfloatBitToString(string bit); //(*)