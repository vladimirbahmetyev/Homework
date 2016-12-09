#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Tree
{
	Tree *leftSon;
	Tree *rightSon;
	int value;
	string stringInTree;
};

Tree zig(Tree  *&binaryTree)
{
	Tree * oldElement = binaryTree->leftSon;
	binaryTree->leftSon = binaryTree->leftSon->rightSon;
	oldElement->rightSon = binaryTree;
	return *oldElement;
}

Tree zag(Tree  *&binaryTree)
{
	Tree * oldElement = binaryTree->rightSon;
	binaryTree->rightSon = binaryTree->rightSon->leftSon;
	oldElement->leftSon = binaryTree;
	return *oldElement;
}

bool foundingOfNumber(Tree *&binaryTree, int value)
{
	while (binaryTree && (value != binaryTree->value))
	{
		if (value < binaryTree->value)
		{
			*binaryTree = zig(binaryTree);
		}
		else
		{
			*binaryTree = zag(binaryTree);
		}
	}
	return (binaryTree);
}

void addString(Tree *&binaryTree, int value, string inputString)
{	
	if (foundingOfNumber(binaryTree, value))
	{
		cout << "«начение данного ключа будет перезаписано" << endl;
		binaryTree->stringInTree = inputString;
	}
	else
	{
		binaryTree = new Tree{ nullptr, nullptr, value, inputString };
	}
}	

void deleteElementFromTree(Tree *&binaryTree, int value)
{
	if (foundingOfNumber(binaryTree, value))
	{
		Tree *oldTree = binaryTree;
		binaryTree = binaryTree;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	cout << "ƒерево пустое, введите элемент, который будет корнем дерева ";
	int numberInRoot = 0;
	cin >> numberInRoot;
	cout << endl;
	Tree *root = new Tree{ nullptr, nullptr, numberInRoot,{} };
	cout << "ƒерево успешно создано" << endl << endl;
	while (command != 0)
	{
		cout << "¬ведите 0 чтобы выйти" << endl;
		cout << "¬ведите 1 чтобы добавить строчку" << endl;
		cout << "¬ведите 3 чтобы проверить дерево на наличие данного ключа" << endl;
		cout << "¬ведите 2 чтобы удалить элемент строчку по заданному ключу" << endl;		
		cout << "¬ведите 4 чтобы распечатать значение по заданному ключу" << endl;
		cin >> command;
		switch (command)
		{
		case (1):
		{
			cout << "¬ведите новый ключ";
			int number = 0;
			cin >> number;
			cout << endl;
			cout << "¬ведите строчку" << endl;
			string inputString = {};
			cin >> inputString;
			addString(root, number, inputString);
			break;
		}
		case(2):
		{
			cout << "¬ведите элемент который нужно удалить: ";
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
			cout << "¬ведите элемент дл€ поиска ";
			int number = 0;
			cin >> number;
			cout << endl;
			foundingOfNumber(root, number);
			break;
		}
		case(4):
		{
			
			break;
		}
		}
	}
	return 0;
}