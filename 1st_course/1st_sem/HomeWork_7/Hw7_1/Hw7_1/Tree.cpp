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
	Tree *newElement = binaryTree->leftSon;
	while (newElement->rightSon)
	{
		newElement = newElement->rightSon;
	}
	binaryTree->value = newElement->value;
	deleteElementFromTree(binaryTree->leftSon, newElement->value);
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

bool isTreeTrue(Tree *root)
{
	if (!root)
	{
		return true;
	}
	bool flag = true;
	if (root->leftSon)
	{
		flag = root->value > root->leftSon->value;
	}
	if (root->rightSon)
	{
		flag = root->value < root->rightSon->value;
	}
	return (flag && isTreeTrue(root->leftSon) && isTreeTrue(root->rightSon));
}

bool test1()
{
	Tree *root = nullptr;
	addNumber(root, 4);
	addNumber(root, 2);
	addNumber(root, 1);
	addNumber(root, 3);
	addNumber(root, 6);
	addNumber(root, 5);
	addNumber(root, 7);
	deleteElementFromTree(root, 4);
	return (isTreeTrue(root));
}

bool test2()
{
	Tree *root = nullptr;
	addNumber(root, 4);
	addNumber(root, 4);
	addNumber(root, 4);
	return isTreeTrue(root);
}

bool test3()
{
	Tree *root = nullptr;
	return isTreeTrue(root);
}