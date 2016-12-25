#include <iostream>
#include "Tree.h"

using namespace std;

struct Tree
{
	Tree *leftSon;
	Tree *rightSon;
	int value;
};

void addNumber(Tree *&binaryTree, int value)
{
	if (!binaryTree)
	{
		binaryTree = new Tree{ nullptr, nullptr, value };
		return;
	}
	if (value == binaryTree->value)
	{
		return;
	}
	else
	{
		if (value < binaryTree->value)
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, nullptr, value };
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
				binaryTree->rightSon = new Tree{ nullptr, nullptr, value };
			}
			else
			{
				addNumber(binaryTree->rightSon, value);
			}
		}
	}
}

bool foundingOfNumber(Tree *&binaryTree, int value)
{
	if (!binaryTree)
	{
		return false;
	}
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
				return false;
			}
		}
	}
	else
	{
		return true;
	}
}

void printBinaryTreeIncrease(Tree *&binaryTree)
{
	if (!binaryTree)
	{
		return;
	}
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

void printBinaryTreeDecrease(Tree *&binaryTree)
{
	if (!binaryTree)
	{
		return;
	}
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

void deleteElementFromTree(Tree *&binaryTree, int value)
{
	if (!binaryTree)
	{
		return;
	}
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
	deleteElementFromTree(newElement, newElement->value);
}

void deleteTree(Tree *&binaryTree)
{
	if (!binaryTree)
	{
		return;
	}
	deleteTree(binaryTree->leftSon);
	deleteTree(binaryTree->rightSon);
	delete binaryTree;
	binaryTree = nullptr;
}