#include <cstdio>
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	if (!test1() && test2() && test3())
	{
		cout << "������" << endl;
		return 0;
	}
	int command = -1;
	Tree *root = nullptr;
	while (command != 0)
	{
		cout << "������� 0 ����� �����" << endl;
		cout << "������� 1 ����� �������� �������" << endl;
		cout << "������� 2 ����� ������� �������" << endl;
		cout << "������� 3 ����� ��������� ������ �� ������� ��������" << endl;
		cout << "������� 4 ����� ����������� �������� ������ � ������� �����������" << endl;
		cout << "������� 5 ����� ����������� �������� ������ � ������� ��������" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
		{
			cout << "������� �����, ������� ����� �������� � ������ ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "������ ������� ��� ���� � ������ " << endl;
			}
			else
			{
				addNumber(root, number);
				cout << "����� ������� ��������� " << endl;
			}
			break;
		}
		case 2:
		{
			cout << "������� ������� ������� ����� �������: ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				deleteElementFromTree(root, number);
				cout << "����� ������� ������� " << endl;
			}
			else
			{
				cout << "������� ����� ��� � ������ " << endl;
			}
			break;
		}
		case 3:
		{
			cout << "������� ������� ��� ������ ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "������ ������� ���� � ������" << endl;
			}
			else
			{
				cout << "������� �������� ��� � ������ " << endl;
			}
			break;
		}
		case 4:
		{
			if (root)
			{
				printBinaryTreeIncrease(root);
				cout << endl;
			}
			else
			{
				cout << "������ ������" << endl;
			}
			break;
		}
		case 5:
		{
			if (root)
			{
				printBinaryTreeDecrease(root);
				cout << endl;
			}
			else
			{
				cout << "������ ������" << endl;
			}
			break;
		}
		default: cout << "������������ ����" << endl;
		}
	}
	deleteTree(root);
	return 0;
}