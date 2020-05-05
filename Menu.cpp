#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
void FancyWords()
{
	cout << "     ____                                                           " << endl;
	cout << "    / __ \\_________  ____ __________ _____ ___  ____ ___  ___  _____" << endl;
	cout << "   / /_/ / ___/ __ \\/ __ `/ ___/ __ `/ __ `__ \\/ __ `__ \\/ _ \\/ ___/" << endl;
	cout << "  / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / / / / / / /  __/ /    " << endl;
	cout << " /_/   /_/   \\____/\\__, /_/   \\__,_/_/ /_/ /_/_/ /_/ /_/\\___/_/     " << endl;
	cout << "                  /____/                                            " << endl;
	cout << "             ______      __           __      __            " << endl;
	cout << "            / ____/___ _/ /______  __/ /___ _/ /_____  _____" << endl;
	cout << "           / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/" << endl;
	cout << "          / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /    " << endl;
	cout << "          \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/     " << endl;
}

void ThongTinDoAn()
{
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "|              Mon: Kien truc may tinh va hop ngu             |" << endl;
	cout << "|                 Giao vien: Thay Le Viet Long                |" << endl;
	cout << "|                          PROJECT 1                          |" << endl;
	cout << "|                  18120632 - Le Nhat Tuan                    |" << endl;
	cout << "|                  18120650 - Nguyen Tan Vinh                 |" << endl;
	cout << "|                  18120598 - Huynh Gia Toai                  |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
}

void MainMenu()
{
	cout << "|                            MENU                             |" << endl;
	cout << "|                          1. QInt                            |" << endl;
	cout << "|                          2. QFloat                          |" << endl;
	cout << "|                          3. Exit                            |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
}

void MenuQInt()
{
	int choice;
	do
	{
		system("CLS");
		FancyWords();
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "|    Ban muon hoat dong tren: Binary, Hexadecimal, Decimal?   |" << endl;
		cout << "|                        1. Binary                            |" << endl;
		cout << "|                        2. Hexadecimal                       |" << endl;
		cout << "|                        3. Decimal                           |" << endl;
		cout << "|                        4. Exit                              |" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "Select: "; cin >> choice;
		switch (choice)
		{
		case 1: MenuQIntBinary();
			break;
		case 2: MenuQIntHexadecimal();
			break;
		case 3: MenuQIntDecimal();
			break;
		default:
			break;
		}
	} while (choice != 4);
}

void MenuQIntBinary()
{
	int choice = 0;
	do
	{
		system("CLS");
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "|               Nhap thao tac ban muon thuc hien:             |" << endl;
		cout << "|                         1. 2 --> 10                         |" << endl;
		cout << "|                         2. 2 --> 16                         |" << endl;
		cout << "|                         3. AND                              |" << endl;
		cout << "|                         4. OR                               |" << endl;
		cout << "|                         5. XOR                              |" << endl;
		cout << "|                         6. NOT                              |" << endl;
		cout << "|                         7. Add                              |" << endl;
		cout << "|                         8. Subtract                         |" << endl;
		cout << "|                         9. Multiply                         |" << endl;
		cout << "|                        10. Divide                           |" << endl;
		cout << "|                        11. Shift left                       |" << endl;
		cout << "|                        12. Shift right                      |" << endl;
		cout << "|                        13. Rotate left                      |" << endl;
		cout << "|                        14. Rotate right                     |" << endl;
		cout << "|                        15. Greater than                     |" << endl;
		cout << "|                        16. Less than                        |" << endl;
		cout << "|                        17. Equal to                         |" << endl;
		cout << "|                        18. Not equal to                     |" << endl;
		cout << "|                        19. Greater or equal                 |" << endl;
		cout << "|                        20. Less or equal                    |" << endl;
		cout << "|                        21. Exit                             |" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "Select: "; cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 2 SANG HE 10                   |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 2 --> 10: " << BinToDec(stringToBool(input));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 2:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                  CHUYEN TU HE 2 SANG HE 16                  |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 2 --> 16: " << charHexToString(BinToHex(stringToBool(input)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 3:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                            AND                              |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result AND: " << boolToString(DecToBin(input1_QInt & input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 4:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              OR                             |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result OR: " << boolToString(DecToBin(input1_QInt | input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 5:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              XOR                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result XOR: " << boolToString(DecToBin(input1_QInt ^ input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 6:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              NOT                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			QInt input_QInt = BinToDec(stringToBool(input));
			cout << "Result NOT: " << boolToString(DecToBin(~input_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 7:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              ADD                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result ADD: " << boolToString(DecToBin(input1_QInt + input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 8:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           SUBTRACT                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result SUBTRACT: " << boolToString(DecToBin(input1_QInt - input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 9:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           MULTIPLY                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result MULTIPLY: " << boolToString(DecToBin(input1_QInt * input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 10:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           DIVIDE                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result DIVIDE: " << boolToString(DecToBin(input1_QInt / input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 11:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT LEFT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Shift left x times: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			cout << "                   Result SHIFT LEFT: " << boolToString(DecToBin(input1_QInt << stoi(input2)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 12:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT RIGHT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Shift right x times: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			cout << "                   Result SHIFT RIGHT: " << boolToString(DecToBin(input1_QInt >> stoi(input2)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 13:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          ROTATE LEFT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Rotate left x times: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			rol(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE LEFT: " << boolToString(DecToBin(input1_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 14:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                         ROTATE RIGHT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Rotate right x times: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			ror(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE RIGHT: " << boolToString(DecToBin(input1_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 15:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        GREATER THAN                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result GREATER THAN: ";
			if (input1_QInt > input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 16:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          LESS THAN                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result LESS THAN: ";
			if (input1_QInt < input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 17:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          EQUAL TO                           |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result EQUAL TO: ";
			if (input1_QInt == input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 18:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        NOT EQUAL TO                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result NOT EQUAL TO: ";
			if (input1_QInt != input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 19:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                       GREATER OR EQUAL                      |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result GREATER OR EQUAL: ";
			if (input1_QInt >= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 20:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        LESS OR EQUAL                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = BinToDec(stringToBool(input1));
			QInt input2_QInt = BinToDec(stringToBool(input2));
			cout << "                   Result LESS OR EQUAL: ";
			if (input1_QInt <= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		default:
			break;
		}
	} while (choice != 21);
}

void MenuQIntHexadecimal()
{
	int choice = 0;
	do
	{
		system("CLS");
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "|               Nhap thao tac ban muon thuc hien:             |" << endl;
		cout << "|                         1. 16 --> 10                        |" << endl;
		cout << "|                         2. 16 --> 2                         |" << endl;
		cout << "|                         3. AND                              |" << endl;
		cout << "|                         4. OR                               |" << endl;
		cout << "|                         5. XOR                              |" << endl;
		cout << "|                         6. NOT                              |" << endl;
		cout << "|                         7. Add                              |" << endl;
		cout << "|                         8. Subtract                         |" << endl;
		cout << "|                         9. Multiply                         |" << endl;
		cout << "|                        10. Divide                           |" << endl;
		cout << "|                        11. Shift left                       |" << endl;
		cout << "|                        12. Shift right                      |" << endl;
		cout << "|                        13. Rotate left                      |" << endl;
		cout << "|                        14. Rotate right                     |" << endl;
		cout << "|                        15. Greater than                     |" << endl;
		cout << "|                        16. Less than                        |" << endl;
		cout << "|                        17. Equal to                         |" << endl;
		cout << "|                        18. Not equal to                     |" << endl;
		cout << "|                        19. Greater or equal                 |" << endl;
		cout << "|                        20. Less or equal                    |" << endl;
		cout << "|                        21. Exit                             |" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "Select: "; cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 16 SANG HE 10                  |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			int n = input.length();
			while (n < 32)
			{
				input = '0' + input;
				++n;
			}
			char* input_hex = new char[n];
			strcpy(input_hex, input.c_str());
			cout << "                   Result 16 --> 10: " << HexToDec(input_hex);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 2:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 16 SANG HE 2                   |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			int n = input.length();
			while (n < 32)
			{
				input = '0' + input;
				++n;
			}
			char* input_hex = new char[n];
			strcpy(input_hex, input.c_str());
			cout << "                   Result 16 --> 2: " << boolToString(HexToBin(input_hex));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 3:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                            AND                              |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result AND: " << charHexToString(DecToHex(input1_QInt & input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 4:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                             OR                              |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result OR: " << charHexToString(DecToHex(input1_QInt | input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 5:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              XOR                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result XOR: " << charHexToString(DecToHex(input1_QInt ^ input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 6:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              NOT                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			int n = input.length();
			while (n < 32)
			{
				input = '0' + input;
				++n;
			}
			char* input_hex = new char[n];
			strcpy(input_hex, input.c_str());
			QInt input_QInt = HexToDec(input_hex);
			cout << "                   Result NOT: " << charHexToString(DecToHex(~input_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 7:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              ADD                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result ADD: " << charHexToString(DecToHex(input1_QInt + input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 8:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           SUBTRACT                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result SUBTRACT: " << charHexToString(DecToHex(input1_QInt - input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 9:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           MULTIPLY                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result MULTIPLY: " << charHexToString(DecToHex(input1_QInt * input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 10:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           DIVIDE                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result DIVIDE: " << charHexToString(DecToHex(input1_QInt / input2_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 11:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT LEFT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Shift left x times: "; cin >> input2;
			QInt input1_QInt = HexToDec(input1_hex);
			cout << "                   Result SHIFT LEFT: " << charHexToString(DecToHex(input1_QInt << stoi(input2)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 12:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT RIGHT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Shift right x times: "; cin >> input2;
			QInt input1_QInt = HexToDec(input1_hex);
			cout << "                   Result SHIFT RIGHT: " << charHexToString(DecToHex(input1_QInt >> stoi(input2)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 13:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          ROTATE LEFT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Rotate left x times: "; cin >> input2;
			QInt input1_QInt = HexToDec(input1_hex);
			rol(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE LEFT: " << charHexToString(DecToHex(input1_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 14:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                         ROTATE RIGHT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Rotate right x times: "; cin >> input2;
			QInt input1_QInt = HexToDec(input1_hex);
			ror(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE RIGHT: " << charHexToString(DecToHex(input1_QInt));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 15:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        GREATER THAN                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result GREATER THAN: ";
			if (input1_QInt > input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 16:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          LESS THAN                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result LESS THAN: ";
			if (input1_QInt < input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 17:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          EQUAL TO                           |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result EQUAL TO: ";
			if (input1_QInt == input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 18:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        NOT EQUAL TO                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result NOT EQUAL TO: ";
			if (input1_QInt != input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 19:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                       GREATER OR EQUAL                      |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result GREATER OR EQUAL: ";
			if (input1_QInt >= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 20:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        LESS OR EQUAL                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			int n = input1.length();
			while (n < 32)
			{
				input1 = '0' + input1;
				++n;
			}
			char* input1_hex = new char[n];
			strcpy(input1_hex, input1.c_str());
			cout << "                   Type second input: "; cin >> input2;
			n = input2.length();
			while (n < 32)
			{
				input2 = '0' + input2;
				++n;
			}
			char* input2_hex = new char[n];
			strcpy(input2_hex, input2.c_str());
			QInt input1_QInt = HexToDec(input1_hex);
			QInt input2_QInt = HexToDec(input2_hex);
			cout << "                   Result LESS OR EQUAL: ";
			if (input1_QInt <= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		default:
			break;
		}
	} while (choice != 21);
}

void MenuQIntDecimal()
{
	int choice = 0;
	do
	{
		system("CLS");
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "|               Nhap thao tac ban muon thuc hien:             |" << endl;
		cout << "|                         1. 10 --> 2                         |" << endl;
		cout << "|                         2. 10 --> 16                        |" << endl;
		cout << "|                         3. AND                              |" << endl;
		cout << "|                         4. OR                               |" << endl;
		cout << "|                         5. XOR                              |" << endl;
		cout << "|                         6. NOT                              |" << endl;
		cout << "|                         7. Add                              |" << endl;
		cout << "|                         8. Subtract                         |" << endl;
		cout << "|                         9. Multiply                         |" << endl;
		cout << "|                        10. Divide                           |" << endl;
		cout << "|                        11. Shift left                       |" << endl;
		cout << "|                        12. Shift right                      |" << endl;
		cout << "|                        13. Rotate left                      |" << endl;
		cout << "|                        14. Rotate right                     |" << endl;
		cout << "|                        15. Greater than                     |" << endl;
		cout << "|                        16. Less than                        |" << endl;
		cout << "|                        17. Equal to                         |" << endl;
		cout << "|                        18. Not equal to                     |" << endl;
		cout << "|                        19. Greater or equal                 |" << endl;
		cout << "|                        20. Less or equal                    |" << endl;
		cout << "|                        21. Exit                             |" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "Select: "; cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 10 SANG HE 2                   |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 10 --> 2: " << boolToString(DecToBin(ConvertStringToQInt(input)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 2:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                  CHUYEN TU HE 10 SANG HE 16                  |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 10 --> 16: " << charHexToString(DecToHex(ConvertStringToQInt(input)));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 3:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                            AND                              |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result AND: " << (input1_QInt & input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 4:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              OR                             |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result OR: " << (input1_QInt | input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 5:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              XOR                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result XOR: " << (input1_QInt ^ input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 6:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              NOT                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			QInt input_QInt = ConvertStringToQInt(input);
			cout << "Result NOT: " << ~input_QInt;
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 7:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                              ADD                            |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result ADD: " << (input1_QInt + input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 8:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           SUBTRACT                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result SUBTRACT: " << (input1_QInt - input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 9:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           MULTIPLY                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result MULTIPLY: " << (input1_QInt * input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 10:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                           DIVIDE                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result DIVIDE: " << (input1_QInt / input2_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 11:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT LEFT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Shift left x times: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			cout << "                   Result SHIFT LEFT: " << (input1_QInt << stoi(input2));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 12:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          SHIFT RIGHT                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Shift right x times: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			cout << "                   Result SHIFT RIGHT: " << (input1_QInt >> stoi(input2));
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 13:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          ROTATE LEFT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Rotate left x times: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			rol(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE LEFT: " << (input1_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 14:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                         ROTATE RIGHT                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input1;
			cout << "                   Rotate right x times: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			ror(input1_QInt, stoi(input2));
			cout << "                   Result ROTATE RIGHT: " << (input1_QInt);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 15:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        GREATER THAN                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result GREATER THAN: ";
			if (input1_QInt > input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 16:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          LESS THAN                          |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result LESS THAN: ";
			if (input1_QInt < input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 17:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                          EQUAL TO                           |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result EQUAL TO: ";
			if (input1_QInt == input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 18:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        NOT EQUAL TO                         |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result NOT EQUAL TO: ";
			if (input1_QInt != input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 19:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                       GREATER OR EQUAL                      |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result GREATER OR EQUAL: ";
			if (input1_QInt >= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 20:
		{
			system("CLS");
			string input1, input2;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                        LESS OR EQUAL                        |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type first input: "; cin >> input1;
			cout << "                   Type second input: "; cin >> input2;
			QInt input1_QInt = ConvertStringToQInt(input1);
			QInt input2_QInt = ConvertStringToQInt(input2);
			cout << "                   Result LESS OR EQUAL: ";
			if (input1_QInt <= input2_QInt) cout << "True";
			else cout << "False";
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		default:
			break;
		}
	} while (choice != 21);
}

void MenuQFloat()
{
	int choice;
	do
	{
		system("CLS");
		FancyWords();
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "|                 Ban muon su dung chuc nang nao?             |" << endl;
		cout << "|                        1. 10 --> 2                          |" << endl;
		cout << "|                        2. 2 --> 10                          |" << endl;
		cout << "|                        3. Exit                              |" << endl;
		cout << "+-------------------------------------------------------------+" << endl;
		cout << "Select: "; cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 10 SANG HE 2                   |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 10 --> 2: " << QfloatToStringBin(input);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		case 2:
		{
			system("CLS");
			string input;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|                 CHUYEN TU HE 2 SANG HE 10                   |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "                   Type: "; cin >> input;
			cout << "                   Result 2 --> 10: " << QfloatBitToString(input);
			cout << "\nPress any key to continue...";
			_getch();
		}
			break;
		default:
			break;
		}
	} while (choice != 3);
}