#include <cstdio>
#include <cstdlib>
#include "splayTree.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	Tree *root = nullptr;
	int command = -1;
	while (command != 0)
	{
		cout << "������� 0 ����� �����" << endl;
		cout << "������� 1 ����� �������� �������" << endl;
		cout << "������� 2 ����� ������� ������� ������� �� ��������� �����" << endl;
		cout << "������� 3 ����� ��������� ������ �� ������� ������� �����" << endl;
		cout << "������� 4 ����� ����������� �������� �� ��������� �����" << endl << endl;
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:
		{
			Array *newElement = new Array{"",""};
			cout << "������� ����� ���� ";
			int number = 0;
			cin >> number;
			cout << endl;
			cout << "������� ������� ";
			string inputString = {};
			cin >> inputString;
			cout << endl;
			addString(root, number, inputString);
			cout << "������ ������� ������� ��������� " << endl << endl;
			break;
		}
		case 2:
		{
			cout << "������� ���� ������, ������� ����� ������� ";
			int number = 0;
			cin >> number;
			cout << endl;
			deleteStringFromTree(root, number);
			cout << "������ ������� �������" << endl << endl;
			break;
		}
		case 3:
		{
			cout << "������� ���� ��� ������ ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "������ ���� ���������� � ������" << endl << endl;
			}
			else
			{
				cout << "������� ����� ��� � ������" << endl << endl;
			}
			break;
		}
		case 4:
		{
			cout << "������� ���� ������, ������� ����� ����������� ";
			int number = 0;
			cin >> number;
			cout << endl;
			printStringFromTree(root, number);
			break;
		}
		default: cout << "������������ ���� " << endl;
		}
	}
	deleteSplayTree(root);
	test();
}