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

bool foundingOfNumber(Tree *&binaryTree, const string &key)
{
	if (!binaryTree)
	{
		return false;
	}
	if (binaryTree->chunk.key == key)
	{
		return true;
	}
	bool leftBranch = binaryTree->leftSon;
	bool rightBranch = binaryTree->rightSon;
	if (binaryTree->leftSon)
	{
		leftBranch = foundingOfNumber(binaryTree->leftSon, key);
	}
	if (binaryTree->rightSon)
	{
		rightBranch = foundingOfNumber(binaryTree->rightSon, key);
	}
	return leftBranch || rightBranch;
}

void splayToKey(Tree *&binaryTree, const string &key)
{
	if (binaryTree->chunk.key == key)
	{
		return;
	}
	if (binaryTree->leftSon)
	{
		if (foundingOfNumber(binaryTree->leftSon, key))
		{
			splayToKey(binaryTree->leftSon, key);
			zig(binaryTree);
		}
	}
	if (binaryTree->rightSon)
	{
		if (foundingOfNumber(binaryTree->rightSon, key))
		{
			splayToKey(binaryTree->rightSon, key);
			zag(binaryTree);
		}
	}
}

void addString(Tree *&binaryTree, const string &key, const string &newString)
{
	Array value = {key, newString};
	if (!binaryTree)
	{
		binaryTree = new Tree{ nullptr, nullptr, value };
		return;
	}
	if (binaryTree->chunk.key == value.key)
	{
		binaryTree->chunk = value;
		return;
	}
	else
	{
		if ( value.key < binaryTree->chunk.key)
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, nullptr, value};
			}
			else
			{

				addString(binaryTree->leftSon, key, newString);
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
				addString(binaryTree->rightSon, key, newString);
			}
		}
	}
	splayToKey(binaryTree, value.key);
}

void deleteStringFromTree(Tree *&binaryTree, const string &key)
{
	if (!binaryTree)
	{
		return;
	}
	if (foundingOfNumber(binaryTree, key))
	{
		splayToKey(binaryTree, key);
		if ((binaryTree->chunk.key > key) || (binaryTree->chunk.key < key))
		{
			if (binaryTree->chunk.key > key)
			{
				deleteStringFromTree(binaryTree->leftSon, key);
				return;
			}
			else
			{
				deleteStringFromTree(binaryTree->rightSon, key);
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
		binaryTree->chunk = newElement->chunk;
		deleteStringFromTree(newElement, newElement->chunk.key);
	}
}

void printStringFromTree(Tree *&binaryTree, const string &key)
{
	if (!binaryTree)
	{
		return;
	}
	if (foundingOfNumber(*&binaryTree, key))
	{
		splayToKey(binaryTree, key);
	}
	cout << binaryTree->chunk.value << endl;
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