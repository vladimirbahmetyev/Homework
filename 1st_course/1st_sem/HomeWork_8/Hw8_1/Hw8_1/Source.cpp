#include <cstdio>
#include <cstdlib>
#include "splayTree.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	cout << "Дерево пустое, введите элемент, который будет корнем дерева ";
	int numberInRoot = 0;
	cin >> numberInRoot;
	cout << "Введите первую строку вашего дерева ";
	string firstString = {};
	cin >> firstString;
	cout << endl;
	Tree *root = new Tree{ nullptr, nullptr, numberInRoot,firstString };
	cout << "Дерево успешно создано" << endl << endl;
	while (command != 0)
	{
		cout << "Введите 0 чтобы выйти" << endl;
		cout << "Введите 1 чтобы добавить строчку" << endl;
		cout << "Введите 2 чтобы удалить элемент строчку по заданному ключу" << endl;
		cout << "Введите 3 чтобы проверить дерево на наличие данного ключа" << endl;
		cout << "Введите 4 чтобы распечатать значение по заданному ключу" << endl << endl;
		cin >> command;
		cout << endl;
		switch (command)
		{
		case (1):
		{
			cout << "Введите новый ключ ";
			int number = 0;
			cin >> number;
			cout << endl;
			cout << "Введите строчку ";
			string inputString = {};
			cin >> inputString;
			cout << endl;
			addString(root, number, inputString);
			break;
		}
		case(2):
		{
			cout << "Введите ключ строки, которую нужно удалить ";
			int number = 0;
			cin >> number;
			cout << endl;
			deleteStringFromTree(root, number);
			cout << "Строка успешно удалена" << endl << endl;
			break;
		}
		case(3):
		{
			cout << "Введите ключ для поиска ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "Данный ключ содержится в дереве" << endl << endl;
			}
			else
			{
				cout << "Данного ключа нет в дереве" << endl << endl;
			}
			break;
		}
		case(4):
		{
			cout << "Введите ключ строки, которую нужно распечатать ";
			int number = 0;
			cin >> number;
			cout << endl;
			printStringFromTree(root, number);
			break;
		}
		}
	}
	deleteSplayTree(root);
	test();
}