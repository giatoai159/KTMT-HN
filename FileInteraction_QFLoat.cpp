#include"FileInteraction_QfLoat.h"

void processDataFromFile_QFloat(string inputFile, string outputFile)
{
	ifstream inputStream(inputFile);
	string p1, p2, n;
	string readingLine;
	int i = 0;
	// Clear exisiting output file
	ofstream outputStream(outputFile, ios::trunc);
	outputStream.close();
	//
	while (getline(inputStream, readingLine))
	{
		p1 = ""; p2 = ""; n = "";
		i++;
		stringstream ss(readingLine);
		getline(ss, p1, ' ');
		getline(ss, p2, ' ');
		getline(ss, n, ' ');
		cout << p1 << " " << p2 << " " << n << " " << " --> " << CalculateData_QFloat(p1, p2, n) << endl;
		writeDataToFile_QFloat(CalculateData_QFloat(p1, p2, n), outputFile);
	}
	inputStream.close();
}

string CalculateData_QFloat(string p1, string p2, string n)
{
	if (p1 == "10")
		return QfloatToStringBin(n);
	else
		return QfloatBitToString(n);
}

void writeDataToFile_QFloat(string n, string outputFile)
{
	ofstream outputStream(outputFile, ios::app);
	outputStream << n << endl;
	outputStream.close();
}