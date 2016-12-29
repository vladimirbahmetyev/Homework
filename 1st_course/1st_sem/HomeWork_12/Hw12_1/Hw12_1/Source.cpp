#include <iostream>
#include "KMP.h"
#include <fstream>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	ifstream inputFile("inputFile.txt");
	if (!inputFile.is_open())
	{
		cout << "Ошибка при открытии файла" << endl;
		return;
	}
	cout << "Введите строчку, которую вам нужно найти : ";
	string inputString = {};
	cin >> inputString;
	int position = KMP(inputFile, inputString);
	inputFile.close();
	if (position != -1)
	{
		cout << "Искомая строчка находится на позиции " << position << endl;
	}
	else
	{
		cout << "Искомой строчки нет в файле " << endl;
	}
	test1();
	test2();
	test3();
}