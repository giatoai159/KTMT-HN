
#pragma once
#include "QInt.h"
#include "Qfloat.h"
#include <string>

QInt ConvertStringToQInt(std::string s);

/*
	Add two big number ex: 1324578974516541321310 + 485679846516532131486
	return result
*/
std::string AddBigInt(std::string A, std::string B);

std::string AddBigIntAfterComma(std::string A, std::string B);

/*
	this function use for -2^128. ex : -2^128 + 1324564897611314984651
*/
std::string SubBigInt(std::string A, std::string B);

/*
	check input if it has character != [0..9] at [1..length() - 1] return false.
	only '-' at(0)
*/
bool CheckInput(std::string& input);

/*
	index of bit: [0..127]
	bit at 0..7 belong to byte [15]
		   8..15 belong to byte [14]
		   ....
		   120..127 belong to byte [0]
	=> bit index belong to byte [15 - index / 8]
	ex: set bit 1 at index 5 of byte [14] => bit index = 15: 00x0000 [14] |= 0010000
	0010000 = 1000000 >> 2
	1000000bin = 128dec
	2 = (7 - 13 % 8)
*/
void SetBit(QInt& x, int index, bool bit);

void Div2(std::string&);
int Div16(std::string&); // return number % 16
void SetBitSign(QInt&);

std::string GetQIntValue(const QInt&);

/*
	Get bit at index of byte
*/
bool GetBit(char byte, int index);

/*
	bit [7] of byte [0]. => Most Significant Bit
*/
bool GetBitSign(const QInt& x);

/*
	Set bit at index to 1
*/
void OnBit(char& byte, int index);

/*
	Set bit at index to 0
*/
void OffBit(char& byte, int index);

QInt GetOneComplement(const QInt& x);
QInt GetTwoComplement(const QInt& x);
QInt GetABS(const QInt& x);

std::string _2PowN(int);

char ComparePositive(const QInt&, const QInt&);
char CompareNegative(const QInt&, const QInt&);

bool GetBitSign_Float(const Qfloat& x);
void SetBit_Float(Qfloat&, int, bool);
bool GetBit_Float(Qfloat, int);
void SetBitSign_Float(Qfloat& x);

