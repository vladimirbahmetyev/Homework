#include "splayTree.h"

void zig(Tree  *&binaryTree)
{
	Tree * oldElement = binaryTree->leftSon;
	binaryTree->leftSon = binaryTree->leftSon->rightSon;
	oldElement->rightSon = binaryTree;
	binaryTree = oldElement;
}

void zag(Tree  *&binaryTree)
{
	Tree * oldElement = binaryTree->rightSon;
	binaryTree->rightSon = binaryTree->rightSon->leftSon;
	oldElement->leftSon = binaryTree;
	binaryTree = oldElement;
}

void splayToKey(Tree *&binaryTree, int value)
{
	while (binaryTree->value != value)
	{
		if (binaryTree->value > value)
		{
			zig(binaryTree);
		}
		else
		{
			zag(binaryTree);
		}
	}
}

bool foundingOfNumber(Tree *&binaryTree, int value)
{
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
					cout << "Данного ключа нет в дереве" << endl << endl;
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
					cout << "Данного ключа нет в дереве" << endl << endl;
					return false;
				}
			}
		}
		else
		{
			cout << "Данный ключ содержится в дереве" << endl << endl;
			return true;
		}
	}
}

void addString(Tree *&binaryTree, int value, string inputString)
{
	if (value == binaryTree->value)
	{
		cout << "Значение данного ключа будет перезаписано" << endl << endl;
		binaryTree->stringInTree = inputString;
		return;
	}
	else
	{
		if (value < binaryTree->value)
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, nullptr, value, inputString };
				cout << "Данная строка успешно добавлена" << endl << endl;
			}
			else
			{

				addString(binaryTree->leftSon, value, inputString);
			}
		}
		else
		{
			if (!binaryTree->rightSon)
			{
				binaryTree->rightSon = new Tree{ nullptr, nullptr, value , inputString };
				cout << "Данная строка успешно добавлена" << endl << endl;
			}
			else
			{
				addString(binaryTree->rightSon, value, inputString);
			}
		}
	}
	splayToKey(binaryTree, value);
}

void deleteStringFromTree(Tree *&binaryTree, int value)
{
	if ((binaryTree->value > value) || (binaryTree->value < value))
	{
		if (binaryTree->value > value)
		{
			deleteStringFromTree(binaryTree->leftSon, value);
			return;
		}
		else
		{
			deleteStringFromTree(binaryTree->rightSon, value);
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
		Tree *oldElement = binaryTree;
		binaryTree = binaryTree->rightSon;
		delete oldElement;
		oldElement = nullptr;
		return;
	}
	if (binaryTree->leftSon && (!binaryTree->rightSon))
	{
		Tree *oldElement = binaryTree;
		binaryTree = binaryTree->leftSon;
		delete oldElement;
		oldElement = nullptr;
		return;
	}
	Tree *&newElement = binaryTree->leftSon;
	while (newElement->rightSon)
	{
		newElement = newElement->rightSon;
	}
	binaryTree->value = newElement->value;
	deleteStringFromTree(newElement, newElement->value);
}

void printStringFromTree(Tree *&binaryTree, int value)
{
	if (foundingOfNumber(binaryTree, value))
	{
		splayToKey(binaryTree, value);
		cout << "Искомая строчка " << binaryTree->stringInTree << endl << endl;
	}
}