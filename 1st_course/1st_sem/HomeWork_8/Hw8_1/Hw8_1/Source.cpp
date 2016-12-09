#include <cstdio>
#include <cstdlib>
#include "splayTree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	cout << "ƒерево пустое, введите элемент, который будет корнем дерева ";
	int numberInRoot = 0;
	cin >> numberInRoot;
	cout << "¬ведите первую строку вашего дерева ";
	string firstString = {};
	cin >> firstString;
	cout << endl;
	Tree *root = new Tree{ nullptr, nullptr, numberInRoot,firstString };
	cout << "ƒерево успешно создано" << endl << endl;
	while (command != 0)
	{
		cout << "¬ведите 0 чтобы выйти" << endl;
		cout << "¬ведите 1 чтобы добавить строчку" << endl;		
		cout << "¬ведите 2 чтобы удалить элемент строчку по заданному ключу" << endl;		
		cout << "¬ведите 3 чтобы проверить дерево на наличие данного ключа" << endl;
		cout << "¬ведите 4 чтобы распечатать значение по заданному ключу" << endl;
		cin >> command;
		switch (command)
		{
		case (1):
		{
			cout << "¬ведите новый ключ ";
			int number = 0;
			cin >> number;
			cout << endl;
			cout << "¬ведите строчку " << endl;
			string inputString = {};
			cin >> inputString;
			addString(root, number, inputString);
			break;
		}
		case(2):
		{
			cout << "¬ведите ключ строки, которую нужно удалить ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				deleteStringFromTree(root, number);
			}
			cout << "—трока успешно удалена" << endl << endl;
			break;
		}
		case(3):
		{
			cout << "¬ведите ключ дл€ поиска ";
			int number = 0;
			cin >> number;
			cout << endl;
			foundingOfNumber(root, number);
			break;
		}
		case(4):
		{
			cout << "¬ведите ключ строки, которую нужно распечатать ";
			int number = 0;
			cin >> number;
			printStringFromTree(root, number);
			break;
		}
		}
	}
	return 0;
}