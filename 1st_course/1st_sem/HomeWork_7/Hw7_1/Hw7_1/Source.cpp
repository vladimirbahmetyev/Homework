#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct tree
{
	tree *leftSon;
	tree *rightSon;
	int value;
};

void addNumber(tree *binaryTree, int value)
{
	if (value == binaryTree->value)
	{
		cout << "Данный элемент уже есть в дереве" << endl;
		return;
	}
	else
	{
		if (value < binaryTree->value)
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new tree{ nullptr, nullptr, value };
			}
			else
			{
				addNumber(binaryTree->leftSon, value);
			}
		}
		else
		{
			if (!binaryTree->rightSon)
			{
				binaryTree->rightSon = new tree{ nullptr, nullptr, value };
			}
			else
			{
				addNumber(binaryTree->rightSon), value);
			}
		}
	}
}

bool foundingOfNumber(tree *binaryTree, int value)
{
	if (binaryTree->value != value)
	{
		if (binaryTree->value > value)
		{
			if (binaryTree->leftSon)
			{
				return foundingOfNumber(binaryTree->leftSon, value);
			}
			else
			{
				cout << "Такого элемента нет в дереве" << endl << endl;
				return false;
			}
		}
		if (binaryTree->value < value)
		{
			if (binaryTree->rightSon)
			{
				return foundingOfNumber(binaryTree->rightSon, value);
			}
			else
			{
				cout << "Такого элемента нет в дереве" << endl << endl;
				return false;
			}
		}
	}
	else
	{
		cout << "Данный элемент есть в дереве" << endl << endl;
		return true;
	}
}

void printBinaryTreeIncrease(tree *binaryTree)
{
	if (binaryTree->leftSon)
	{
		printBinaryTreeIncrease(binaryTree->leftSon);
	}
	cout << binaryTree->value << " ";
	if (binaryTree->rightSon)
	{
		printBinaryTreeIncrease(binaryTree->rightSon);
	}
}

void printBinaryTreeDecrease(tree *binaryTree)
{
	if (binaryTree->rightSon)
	{
		printBinaryTreeDecrease(binaryTree->rightSon);
	}
	cout << binaryTree->value << " ";
	if (binaryTree->leftSon)
	{
		printBinaryTreeDecrease(binaryTree->leftSon);
	}
}

void deleteElementFromTree(tree *binaryTree, int value)
{
	if ((binaryTree->value > value) || (binaryTree->value < value))
	{
		if (binaryTree->value > value)
		{
			deleteElementFromTree(binaryTree->leftSon, value);
			return;
		}
		else
		{
			deleteElementFromTree(binaryTree->rightSon, value);
			return;
		}
	}
	if (!(binaryTree->leftSon || binaryTree->rightSon))
	{
		delete binaryTree;
		binaryTree = nullptr;
		return;
	}
	if ((!binaryTree->leftSon) && binaryTree->rightSon)
	{
		tree **oldElement = binaryTree;
		binaryTree->rightSon = binaryTree->rightSon;
		delete oldElement;
		return;
	}
	if (binaryTree->leftSon && (!binaryTree->rightSon))
	{
		tree **oldElement = binaryTree;
		binaryTree->rightSon = binaryTree->leftSon;
		delete oldElement;
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	cout << "Дерево пустое, введите элемент, который будет корнем дерева ";
	int numberInRoot = 0;
	cin >> numberInRoot;
	cout << endl;
	tree *root = new tree{ nullptr, nullptr, numberInRoot };
	cout << "Дерево успешно создано" << endl << endl;
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
		case (1):
		{
			cout << "Введите число, которое нужно добавить в дерево ";
			int number = 0;
			cin >> number;
			cout << endl;
			addNumber(root, number);
			break;
		}
		case(2):
		{
			cout << "Введите элемент который нужно удалить: ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (foundingOfNumber(root, number))
			{
				deleteElementFromTree(root, number);
			}
			break;
		}
		case(3):
		{
			cout << "Введите элемент для поиска ";
			int number = 0;
			cin >> number;
			cout << endl;
			foundingOfNumber(root, number);
			break;
		}
		case(4):
		{
			printBinaryTreeIncrease(root);
			cout << endl;
			break;
		}
		case(5):
		{
			printBinaryTreeDecrease(root);
			cout << endl;
			break;
		}
		}
	}
	return 0;
}