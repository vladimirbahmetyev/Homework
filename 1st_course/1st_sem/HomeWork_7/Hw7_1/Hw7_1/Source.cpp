#include <cstdio>
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	if (!test1() && test2() && test3())
	{
		cout << "Ошибка" << endl;
		return 0;
	}
	int command = -1;
	Tree *root = nullptr;
	while (command != 0)
	{
		cout << "Введите 0 чтобы выйти" << endl;
		cout << "Введите 1 чтобы добавить элемент" << endl;
		cout << "Введите 2 чтобы удалить элемент" << endl;
		cout << "Введите 3 чтобы проверить дерево на наличие элемента" << endl;
		cout << "Введите 4 чтобы распечатать бинарное дерево в порядке возрастания" << endl;
		cout << "Введите 5 чтобы распечатать бинарное дерево в порядке убывания" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
		{
			cout << "Введите число, которое нужно добавить в дерево ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "Данный элемент уже есть в дереве " << endl;
			}
			else
			{
				addNumber(root, number);
				cout << "Число успешно добавлено " << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Введите элемент который нужно удалить: ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				deleteElementFromTree(root, number);
				cout << "Число успешно удалено " << endl;
			}
			else
			{
				cout << "Данного числа нет в дереве " << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите элемент для поиска ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				cout << "Данный элемент есть в дереве" << endl;
			}
			else
			{
				cout << "Данного элемента нет в дереве " << endl;
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
				cout << "Дерево пустое" << endl;
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
				cout << "Дерево пустое" << endl;
			}
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
		}
	}
	deleteTree(root);
	return 0;
}