#include"FileInteraction.h"

void processDataFromFile_QInt(string inputFile,string outputFile)
{
	ifstream inputStream(inputFile);
	string p1, p2, n1, n2, oper;
	string readingLine;
	int i = 0;
	// Clear exisiting output file
	ofstream outputStream(outputFile, ios::trunc);
	outputStream.close();
	//
	while (getline(inputStream, readingLine))
	{
		p1 = ""; p2 = ""; n1 = ""; n2 = ""; oper = "";
		i++;
		stringstream ss(readingLine);
		getline(ss, p1, ' ');
		/* Using goto, it's bad, don't use it
		getline(ss, p2, ' ');
		if (p2 != "2" && p2 != "10" && p2 != "16" && p2 != "ror" && p2 != "rol" && p2 != "~")
		{
			n1 = p2;
			p2 = "";
			goto readOper;
		}
		else goto readN1;
	readN1:
		getline(ss, n1, ' ');
		goto endRead;
	readOper:
		getline(ss, oper, ' ');
		if (oper != "+" && oper != "-" && oper != "*" && oper != "/")
			goto endRead;
		else goto  readN2;
	readN2:
		getline(ss, n2, ' ');
		goto endRead;
	endRead:
		cout << "p1: " << p1 << " p2: " << p2 << " n1: " << n1 << " oper: " << oper << " n2: " << n2 << endl;
		continue;
		*/
		getline(ss, p2, ' ');
		if (p2 != "2" && p2 != "10" && p2 != "16" && p2 != "~")
		{
			n1 = p2;
			p2 = "";
			getline(ss, oper, ' ');
			if (oper == "+" || oper == "-" || oper == "*" || oper == "/" || oper == "&" || oper == "|" || oper == "^" ||
				oper == ">" || oper == "<" || oper == "==" || oper == "!=" || oper == "<=" || oper == ">=" || oper == "<<" || oper == ">>" || oper == "ror" || oper == "rol")
				getline(ss, n2, ' ');
		}
		else
			getline(ss, n1, ' ');
		cout << p1 << " " << p2 << " " << n1 << " " << oper << " " << n2 << " --> " << CalculateData_QInt(p1, p2, n1, oper, n2) << endl;
		writeDataToFile_QInt(CalculateData_QInt(p1, p2, n1, oper, n2), outputFile);
	}
	inputStream.close();
}

bool* stringToBool(string s)
{
	bool* result = new bool[128];
	while (s.length() < 128)
		s = '0' + s;
	for (int i = 0; i < 128; i++)
		result[i] = s[i] - '0';
	/* IGNORE THIS :3
	int n = s.length();
	for (int i = 0; i < 128 - n; i++)
		s.insert(s.begin(), '0');
	char* char_array = new char[128];
	strcpy(char_array, s.c_str());
	for (int i = 0; i < 128; ++i)
	{
		if (char_array[i] == '1') result[i] = 1;
		else result[i] = 0;
	}
	*/
	return result;
}

string boolToString(bool* bin)
{
	string str = "";
	bool flag = false;
	for (int i = 0; i < 128; ++i) 
	{
		if (bin[i] == 0 && !flag) continue;
		else
		{
			str += bin[i] + '0';
			flag = true;
		}
	}
	return str;
}

string charHexToString(char *hex)
{
	string str = "";
	bool flag = false;
	for (int i = 0; i < 32; ++i)
	{
		if (hex[i] == '0' && !flag)
			continue;
		else {
			str += hex[i];
			flag = true;
		}
	}
	return str;
}

string boolToString2(bool flag)
{
	if (flag)
		return "1";
	else return "0";
}

string CalculateData_QInt(string p1, string p2, string n1, string oper, string n2)
{
	if (p1 == "10")
	{
		QInt n1_QInt = ConvertStringToQInt(n1);
		if (n2 == "")
		{
			if (p2 == "10") return GetQIntValue(n1_QInt);
			if (p2 == "2")
			{
				bool* bin = DecToBin(n1_QInt);
				return boolToString(bin);
			}
			if (p2 == "16")
			{
				char* hex = DecToHex(n1_QInt);
				return charHexToString(hex);
			}
			if (p2 == "~") return GetQIntValue(~n1_QInt);
		}
		else
		{
			QInt n2_QInt = ConvertStringToQInt(n2);
			if (oper == "+") return GetQIntValue(n1_QInt + n2_QInt);
			if (oper == "-") return GetQIntValue(n1_QInt - n2_QInt);
			if (oper == "*") return GetQIntValue(n1_QInt * n2_QInt);
			if (oper == "/") return GetQIntValue(n1_QInt / n2_QInt);

			if (oper == "&") return GetQIntValue(n1_QInt & n2_QInt);
			if (oper == "|") return GetQIntValue(n1_QInt | n2_QInt);
			if (oper == "^") return GetQIntValue(n1_QInt ^ n2_QInt);

			if (oper == ">") return boolToString2(n1_QInt > n2_QInt);
			if (oper == "<") return boolToString2(n1_QInt < n2_QInt);
			if (oper == "==") return boolToString2(n1_QInt == n2_QInt);
			if (oper == "!=") return boolToString2(n1_QInt != n2_QInt);
			if (oper == "<=") return boolToString2(n1_QInt <= n2_QInt);
			if (oper == ">=") return boolToString2(n1_QInt >= n2_QInt);

			if (oper == "<<") return GetQIntValue(n1_QInt << stoi(n2));
			if (oper == ">>") return GetQIntValue(n1_QInt >> stoi(n2));

			if (oper == "ror")
			{
				ror(n1_QInt, stoi(n2));
				return GetQIntValue(n1_QInt);
			}
			if (oper == "rol")
			{
				rol(n1_QInt, stoi(n2));
				return GetQIntValue(n1_QInt);
			}
		}
	}
	else if (p1 == "2")
	{
		bool* n1_bool = stringToBool(n1);
		if (n2 == "")
		{
			if (p2 == "2") return boolToString(n1_bool);
			if (p2 == "10") return GetQIntValue(BinToDec(n1_bool));
			if (p2 == "16")
			{
				char* hex = BinToHex(n1_bool);
				string result = "";
				bool flag = false;
				for (int i = 0; i < 32; ++i)
					if (hex[i] == '0' && !flag)
						continue;
					else
					{
						result += hex[i];
						flag = true;
					}
				return result;
			}
			if (p2 == "~")
			{
				QInt n1_QInt = BinToDec(n1_bool);
				bool *bin = DecToBin(~n1_QInt);
				return boolToString(bin);
			}
		}
		else
		{
			bool* n2_bool = stringToBool(n2);
			QInt n1_QInt = BinToDec(n1_bool);
			QInt n2_QInt = BinToDec(n2_bool);
			if (oper == "+") return boolToString(DecToBin(n1_QInt + n2_QInt));
			if (oper == "-") return boolToString(DecToBin(n1_QInt - n2_QInt));
			if (oper == "*") return boolToString(DecToBin(n1_QInt * n2_QInt));
			if (oper == "/") return boolToString(DecToBin(n1_QInt / n2_QInt));

			if (oper == "&") return boolToString(DecToBin(n1_QInt & n2_QInt));
			if (oper == "|") return boolToString(DecToBin(n1_QInt | n2_QInt));
			if (oper == "^") return boolToString(DecToBin(n1_QInt ^ n2_QInt));

			if (oper == ">") return boolToString2(n1_QInt > n2_QInt);
			if (oper == "<") return boolToString2(n1_QInt < n2_QInt);
			if (oper == "==") return boolToString2(n1_QInt == n2_QInt);
			if (oper == "!=") return boolToString2(n1_QInt != n2_QInt);
			if (oper == "<=") return boolToString2(n1_QInt <= n2_QInt);
			if (oper == ">=") return boolToString2(n1_QInt >= n2_QInt);

			if (oper == "<<") return boolToString(DecToBin(n1_QInt << stoi(n2)));
			if (oper == ">>") return boolToString(DecToBin(n1_QInt >> stoi(n2)));

			if (oper == "ror")
			{
				ror(n1_QInt, stoi(n2));
				return boolToString(DecToBin(n1_QInt));
			}
			if (oper == "rol")
			{
				rol(n1_QInt, stoi(n2));
				return boolToString(DecToBin(n1_QInt));
			}
		}
	}
	else
	{
		int n = n1.length();
		while (n < 32)
		{
			n1 = '0' + n1;
			++n;
		}
		char* n1_hex = new char[n];
		strcpy(n1_hex, n1.c_str());
		if (n2 == "")
		{
			if (p2 == "16") return charHexToString(n1_hex);
			if (p2 == "2") return boolToString(HexToBin(n1_hex));
			if (p2 == "10") return GetQIntValue(HexToDec(n1_hex));
			if (p2 == "~")
			{
				QInt n1_QInt = HexToDec(n1_hex);
				char* hex = DecToHex(~n1_QInt);
				return charHexToString(hex);
			}
		}
		else
		{
			n = n2.length();
			while (n < 32)
			{
				n2 = '0' + n2;
				++n;
			}
			char* n2_hex = new char[n];
			strcpy(n2_hex, n2.c_str());
			QInt n1_QInt = HexToDec(n1_hex);
			QInt n2_QInt = HexToDec(n2_hex);
			if (oper == "+") return charHexToString(DecToHex(n1_QInt + n2_QInt));
			if (oper == "-") return charHexToString(DecToHex(n1_QInt - n2_QInt));
			if (oper == "*") return charHexToString(DecToHex(n1_QInt * n2_QInt));
			if (oper == "/") return charHexToString(DecToHex(n1_QInt / n2_QInt));

			if (oper == "&") return charHexToString(DecToHex(n1_QInt & n2_QInt));
			if (oper == "|") return charHexToString(DecToHex(n1_QInt | n2_QInt));
			if (oper == "^") return charHexToString(DecToHex(n1_QInt ^ n2_QInt));

			if (oper == ">") return boolToString2(n1_QInt > n2_QInt);
			if (oper == "<") return boolToString2(n1_QInt < n2_QInt);
			if (oper == "==") return boolToString2(n1_QInt == n2_QInt);
			if (oper == "!=") return boolToString2(n1_QInt != n2_QInt);
			if (oper == "<=") return boolToString2(n1_QInt <= n2_QInt);
			if (oper == ">=") return boolToString2(n1_QInt >= n2_QInt);

			if (oper == "<<") return charHexToString(DecToHex(n1_QInt << stoi(n2)));
			if (oper == ">>") return charHexToString(DecToHex(n1_QInt >> stoi(n2)));

			if (oper == "ror")
			{
				ror(n1_QInt, stoi(n2));
				return charHexToString(DecToHex(n1_QInt));
			}
			if (oper == "rol")
			{
				rol(n1_QInt, stoi(n2));
				return charHexToString(DecToHex(n1_QInt));
			}
		}
	}
}

void writeDataToFile_QInt(string n, string outputFile)
{
	ofstream outputStream(outputFile, ios::app);
	outputStream << n << endl;
	outputStream.close();
}