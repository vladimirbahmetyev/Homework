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
			Array *newElement = {};
			cout << "������� ����� ���� ";
			string newKey = {};
			cin >> newKey;
			cout << endl;
			cout << "������� ������� ";
			string inputString = {};
			cin >> inputString;
			cout << endl;
			addString(root, newKey, inputString);
			cout << "������ ������� ������� ��������� " << endl << endl;
			break;
		}
		case 2:
		{
			cout << "������� ���� ������, ������� ����� ������� ";
			string number = {};
			cin >> number;
			cout << endl;
			deleteStringFromTree(root, number);
			cout << "������ ������� �������" << endl << endl;
			break;
		}
		case 3:
		{
			cout << "������� ���� ��� ������ ";
			string key = {};
			cin >> key;
			cout << endl;
			if (foundingOfNumber(root, key))
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
			string key = {};
			cin >> key;
			cout << endl;
			printStringFromTree(root, key);
			break;
		}
		default: cout << "������������ ���� " << endl;
		}
	}
	deleteSplayTree(root);
}