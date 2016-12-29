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
		cout << "������ ��� �������� �����" << endl;
		return;
	}
	cout << "������� �������, ������� ��� ����� ����� : ";
	string inputString = {};
	cin >> inputString;
	int position = KMP(inputFile, inputString);
	inputFile.close();
	if (position != -1)
	{
		cout << "������� ������� ��������� �� ������� " << position << endl;
	}
	else
	{
		cout << "������� ������� ��� � ����� " << endl;
	}
	test1();
	test2();
	test3();
}