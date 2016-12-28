#include "splayTree.h"

struct Array
{
	string key;
	string value;
};

struct Tree
{
	Tree *leftSon;
	Tree *rightSon;
	Array chunk;
};

void zig(Tree  *&binaryTree)
{
	Tree *oldElement = binaryTree->leftSon;
	if (binaryTree->leftSon)
	{
		binaryTree->leftSon = binaryTree->leftSon->rightSon;
	}
	oldElement->rightSon = binaryTree;
	binaryTree = oldElement;
}

void zag(Tree  *&binaryTree)
{
	Tree *oldElement = binaryTree->rightSon;
	if (binaryTree->rightSon)
	{
		binaryTree->rightSon = binaryTree->rightSon->leftSon;
	}
	oldElement->leftSon = binaryTree;
	binaryTree = oldElement;
}

bool foundingOfNumber(Tree *&binaryTree, Array *value)
{
	if (!binaryTree)
	{
		return false;
	}
	if (binaryTree->chunk.key == value->key)
	{
		return true;
	}
	bool leftBranch = binaryTree->leftSon;
	bool rightBranch = binaryTree->rightSon;
	if (binaryTree->leftSon)
	{
		leftBranch = foundingOfNumber(binaryTree->leftSon, value);
	}
	if (binaryTree->rightSon)
	{
		rightBranch = foundingOfNumber(binaryTree->rightSon, value);
	}
	return leftBranch || rightBranch;
}

void splayToKey(Tree *&binaryTree, Array *value)
{
	if (binaryTree->chunk.key == value->key)
	{
		return;
	}
	if (binaryTree->leftSon)
	{
		if (foundingOfNumber(binaryTree->leftSon, value))
		{
			splayToKey(binaryTree->leftSon, value);
			zig(binaryTree);
		}
	}
	if (binaryTree->rightSon)
	{
		if (foundingOfNumber(binaryTree->rightSon, value))
		{
			splayToKey(binaryTree->rightSon, value);
			zag(binaryTree);
		}
	}
}

void addString(Tree *&binaryTree, Array *value)
{
	if (!binaryTree)
	{
		binaryTree = new Tree{ nullptr, nullptr, *value };
		return;
	}
	if (binaryTree->chunk.key == value->key)
	{
		binaryTree->chunk = *value;
		return;
	}
	else
	{
		if ( value->key < binaryTree->chunk.key)
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, nullptr, *value};
			}
			else
			{

				addString(binaryTree->leftSon, value);
			}
		}
		else
		{
			if (!binaryTree->rightSon)
			{
				binaryTree->rightSon = new Tree{ nullptr, nullptr, *value };
			}
			else
			{
				addString(binaryTree->rightSon, value);
			}
		}
	}
	splayToKey(binaryTree, value);
}

void deleteStringFromTree(Tree *&binaryTree, int value)
{
	if (!binaryTree)
	{
		return;
	}
	if (foundingOfNumber(binaryTree, value))
	{
		splayToKey(binaryTree, value);
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
}

void printStringFromTree(Tree *&binaryTree, Array *value)
{
	if (!binaryTree)
	{
		return;
	}
	if (foundingOfNumber(*&binaryTree, value))
	{
		splayToKey(binaryTree, value);
	}
}

void deleteSplayTree(Tree *&binaryTree)
{
	if (binaryTree->leftSon)
	{
		deleteSplayTree(binaryTree->leftSon);
	}
	if (binaryTree->rightSon)
	{
		deleteSplayTree(binaryTree->rightSon);
	}
	delete binaryTree;
	binaryTree = nullptr;
}

void test()
{
	Tree *testTree = new Tree{ nullptr, nullptr, 0, " " };
	for (int i = 1; i < 100; i++)
	{
		addString(*&testTree, i, " ");
	}
	bool resultOfTest = true;
	for (int i = 99; i > 0; i--)
	{
		splayToKey(*&testTree, (char)i);
		resultOfTest = resultOfTest && (i == testTree->chunk);
	}
	if (resultOfTest)
	{
		cout << "Тест пройден" << endl << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl << endl;
	}
	deleteSplayTree(*&testTree);
}