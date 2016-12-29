#include "KMP.h"
#include <iostream>

using namespace std;

int KMP(ifstream &inputFile, const string &inputString)
{
	setlocale(LC_ALL, "Russian");
	int neededPrefixFunction = inputString.size();
	int position = 1;
	int preferPrefixFunction = 0;
	while (neededPrefixFunction != preferPrefixFunction && !inputFile.eof())
	{
		string stringFromFile = {};
		getline(inputFile, stringFromFile);
		for (int i = 0; i < inputString.size(); i++)
		{
			position++;
			if (stringFromFile[i] == inputString[preferPrefixFunction])
			{
				preferPrefixFunction++;
				if (preferPrefixFunction == neededPrefixFunction)
				{
					return position - preferPrefixFunction;
				}
			}
			else
			{
				if (preferPrefixFunction == 1 && inputString[0] == stringFromFile[i])
				{
					preferPrefixFunction = 1;

				}
				else
				{
					preferPrefixFunction = 0;
				}
			}
		}
	}
	if (preferPrefixFunction == 0)
	{
		return -1;
	}
}

void test1()
{
	ifstream inputFile("inputFile.txt");
	if (KMP(inputFile, "o w") == 5)
	{
		cout << "Тест 1 пройден" << endl;
	}
	else
	{
		cout << "Тест 1 не пройден" << endl;
	}
	inputFile.close();
}

void test2()
{
	ifstream inputFile("inputFile.txt");
	if (KMP(inputFile, "lo") == 4)
	{
		cout << "Тест 2 пройден" << endl;
	}
	else
	{
		cout << "Тест 2 не пройден" << endl;
	}
	inputFile.close();
}

void test3()
{
	ifstream inputFile("inputFile.txt");
	if (KMP(inputFile, ")") == 26)
	{
		cout << "Тест 3 пройден" << endl;
	}
	else
	{
		cout << "Тест 3 не пройден" << endl;
	}
	inputFile.close();
}