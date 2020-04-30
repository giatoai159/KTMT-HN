#include "QInt.h"
#include "UtilQInt.h"
#include "FileInteraction.h"
#include "FileInteraction_QFloat.h"

void main(int argc, char *argv[]) {
	init();
	// string inputFile = "input.txt";
	// string outputFile = "output.txt";
	if (argc != 1)
	{
		string inputFile = argv[1];
		string outputFile = argv[2];
		string type = argv[3];
		if (type=="0")
			processDataFromFile_QInt(inputFile, outputFile);
		if (type=="1")
			processDataFromFile_QFloat(inputFile, outputFile);
	}
	else
	{
		// menu
	}
}