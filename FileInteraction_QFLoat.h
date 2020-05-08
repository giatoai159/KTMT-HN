#pragma once

#include"Qfloat.h"
#include<sstream>
#include<fstream>

using namespace std;

void processDataFromFile_QFloat(string inputFile, string outputFile); // Đọc file từng dòng và lưu dữ liệu vào các biến phù hợp theo thứ tự và cách nhau bằng khoảng cách
string CalculateData_QFloat(string p1, string p2, string n); // Sử dụng các biến đưa vào, xác định yêu cầu tính qua sự hiện diện của các biến và bắt đầu tính toán
void writeDataToFile_QFloat(string n, string outputFile);

