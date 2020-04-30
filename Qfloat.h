#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Qfloat
{
	char arrBits[16];
};
void init(Qfloat&);
std::string AddBigInt_float(std::string, std::string);
std::string SubBigInt_float(std::string, std::string);
std::string stringDecToBin(string s);
string convertAfterComma(string s);
string subStringBit(string b1, string b2);


//bool CheckInput(std::string&); ///????


void Div2_float(std::string&);
void Div2ToPrint(std::string&);

void SetBitSign(Qfloat &);
bool GetBit_float(char, int);
bool GetBitSign(const Qfloat& x);
void OnBit_float(char&, int);
void OffBit_float(char&, int);
void SetBit(Qfloat&, int, bool);
bool GetBit_float(Qfloat, int);

string QfloatToStringBin(string s); //(*)
Qfloat ConvertStringToQfloat(string s);
void ScanQfloat(Qfloat&); //(*)

string x5(string str);
string Pow5(int x);
string PowNegativeTwo(int x);
string AddBigIntAfterComma(string A, string B);
void PrintQfloat(Qfloat&); //(*)
string QfloatBitToString(string bit); //(*)