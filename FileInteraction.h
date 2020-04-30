#pragma once

#include"QInt.h"
#include"UtilQInt.h"
#include<sstream>
#include<fstream>

using namespace std;

void processDataFromFile_QInt(string inputFile,string outputFile);
string CalculateData_QInt(string p1,string p2,string n1,string oper,string n2);
//
bool* stringToBool(string s);
string boolToString(bool* bin);
string charHexToString(char *hex);
string boolToString2(bool flag);
//
void writeDataToFile_QInt(string n, string outputFile);

