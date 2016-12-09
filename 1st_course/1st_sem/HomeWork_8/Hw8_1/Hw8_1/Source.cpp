#include <cstdio>
#include <cstdlib>
#include "splayTree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	cout << "������ ������, ������� �������, ������� ����� ������ ������ ";
	int numberInRoot = 0;
	cin >> numberInRoot;
	cout << "������� ������ ������ ������ ������ ";
	string firstString = {};
	cin >> firstString;
	cout << endl;
	Tree *root = new Tree{ nullptr, nullptr, numberInRoot,firstString };
	cout << "������ ������� �������" << endl << endl;
	while (command != 0)
	{
		cout << "������� 0 ����� �����" << endl;
		cout << "������� 1 ����� �������� �������" << endl;		
		cout << "������� 2 ����� ������� ������� ������� �� ��������� �����" << endl;		
		cout << "������� 3 ����� ��������� ������ �� ������� ������� �����" << endl;
		cout << "������� 4 ����� ����������� �������� �� ��������� �����" << endl;
		cin >> command;
		switch (command)
		{
		case (1):
		{
			cout << "������� ����� ���� ";
			int number = 0;
			cin >> number;
			cout << endl;
			cout << "������� ������� " << endl;
			string inputString = {};
			cin >> inputString;
			addString(root, number, inputString);
			break;
		}
		case(2):
		{
			cout << "������� ���� ������, ������� ����� ������� ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				deleteStringFromTree(root, number);
			}
			cout << "������ ������� �������" << endl << endl;
			break;
		}
		case(3):
		{
			cout << "������� ���� ��� ������ ";
			int number = 0;
			cin >> number;
			cout << endl;
			foundingOfNumber(root, number);
			break;
		}
		case(4):
		{
			cout << "������� ���� ������, ������� ����� ����������� ";
			int number = 0;
			cin >> number;
			printStringFromTree(root, number);
			break;
		}
		}
	}
	return 0;
}