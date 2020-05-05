#include "QInt.h"
#include "Util.h"
#include "FileInteraction.h"
#include "FileInteraction_QFloat.h"
#include "Menu.h"

void main(int argc, char *argv[]) {
	// string inputFile = "input.txt";
	// string outputFile = "output.txt";
	if (argc != 1)
	{
		string inputFile = argv[1];
		string outputFile = argv[2];
		string type = argv[3];
		if (type=="1")
			processDataFromFile_QInt(inputFile, outputFile);
		if (type=="2")
			processDataFromFile_QFloat(inputFile, outputFile);
	}
	else
	{
		int choice;
		do
		{
			system("CLS");
			FancyWords();
			ThongTinDoAn();
			MainMenu();
			cout << "Select: "; cin >> choice;
			switch (choice)
			{
			case 1: MenuQInt();
				break;
			case 2: MenuQFloat();
				break;
			default:
				break;
			}
		} while (choice != 3);
	}
}