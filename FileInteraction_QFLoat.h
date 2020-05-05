#pragma once

#include"Qfloat.h"
#include<sstream>
#include<fstream>

using namespace std;

void processDataFromFile_QFloat(string inputFile, string outputFile);
string CalculateData_QFloat(string p1, string p2, string n);
//
bool* stringToBool(string s);
string boolToString(bool* bin);
string charHexToString(char *hex);
string boolToString2(bool flag);
//
void writeDataToFile_QFloat(string n, string outputFile);

