#pragma once

#include"QInt.h"
#include"Util.h"
#include<sstream>
#include<fstream>

using namespace std;

void processDataFromFile_QInt(string inputFile,string outputFile); // Đọc file từng dòng và lưu dữ liệu vào các biến phù hợp theo thứ tự và cách nhau bằng khoảng cách
string CalculateData_QInt(string p1,string p2,string n1,string oper,string n2); // Sử dụng các biến đưa vào, xác định yêu cầu tính qua sự hiện diện của các biến và bắt đầu tính toán
//
bool* stringToBool(string s); 
string boolToString(bool* bin);
string charHexToString(char *hex);
string boolToString2(bool flag);
//
void writeDataToFile_QInt(string n, string outputFile);

