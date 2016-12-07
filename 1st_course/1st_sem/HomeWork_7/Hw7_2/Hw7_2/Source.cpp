#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Tree
{
	Tree *leftSon;
	char value;
	Tree *rightSon;
};

bool isTreeFinish(Tree *&binaryTree)
{
	if (!binaryTree)
	{
		return binaryTree;
	}
	if (('0' <= (binaryTree->value)) && ('9' >= (binaryTree->value)))
	{
		return true;
	}
	if (!(binaryTree->leftSon) && (binaryTree->rightSon))
	{
		return false;
	}
	return ((isTreeFinish(binaryTree->leftSon)) && (isTreeFinish(binaryTree->rightSon)));
}

void printTree(Tree *&binaryTree)
{
	cout << binaryTree->value << ' ';
	if (binaryTree->leftSon)
	{
		printTree(binaryTree->leftSon);
	}	
	if (binaryTree->rightSon)
	{
		printTree(binaryTree->rightSon);
	}
}

void pushToTree(Tree *&binaryTree, char symbol)
{
	if (((symbol == '*') || (symbol == '/') || (symbol == '-') || (symbol == '+')) && (binaryTree->value == 'e'))
	{
		binaryTree->value = symbol;
		return;
	}
	if (((symbol == '*') || (symbol == '/') || (symbol == '-') || (symbol == '+')))
	{
		if (!isTreeFinish(binaryTree->leftSon))
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, 'e', nullptr };
			}			
			pushToTree(binaryTree->leftSon, symbol);
			return;
		}
		else
		{
			if (!binaryTree->rightSon)
			{
				binaryTree->rightSon = new Tree{ nullptr, 'e', nullptr };
			}
			pushToTree(binaryTree->rightSon, symbol);
			return;
		}
	}
	if ('0' <= symbol && '9' >= symbol)
	{
		if (!isTreeFinish(binaryTree->leftSon))
		{
			if (!binaryTree->leftSon)
			{
				binaryTree->leftSon = new Tree{ nullptr, symbol, nullptr };
			}
			else
			{
				pushToTree(binaryTree->leftSon, symbol);
			}
			return;
		}
		else
		{
			if (!binaryTree->rightSon)
			{
				binaryTree->rightSon = new Tree{ nullptr, symbol, nullptr };
			}
			else
			{
				pushToTree(binaryTree->rightSon, symbol);
			}
			return;
		}
	}
}

void loadFromFileToTree(Tree *&binaryTree)
{
	char symbol = {};
	ifstream file("file.txt");
	while (!file.eof())
	{
		file >> symbol;
		pushToTree(binaryTree, symbol);
	}
}

int resultOfTree(Tree *&binaryTree)
{
	if ('0' <= (binaryTree->value) && '9' >= binaryTree->value)
	{
		return ((int)binaryTree->value - 48);
	}
	if ('-' == binaryTree->value)
	{
		return (resultOfTree(binaryTree->leftSon) - resultOfTree(binaryTree->rightSon));
	}
	if ('*' == binaryTree->value)
	{
		return (resultOfTree(binaryTree->leftSon) * resultOfTree(binaryTree->rightSon));
	}
	if ('/' == binaryTree->value)
	{
		return (resultOfTree(binaryTree->leftSon) / resultOfTree(binaryTree->rightSon));
	}
	if ('+' == binaryTree->value)
	{
		return (resultOfTree(binaryTree->leftSon) + resultOfTree(binaryTree->rightSon));
	}
}

void deleteTree(Tree *&binaryTree)
{
	if (!binaryTree)
	{
		return;
	}
	deleteTree(binaryTree->leftSon);
	deleteTree(binaryTree->rightSon);
	if (!(binaryTree->leftSon || binaryTree->rightSon))
	{
		delete binaryTree;
		binaryTree = nullptr;
		return;
	}
}

int main()
{
	Tree *root = new Tree{ nullptr, 'e', nullptr };
	loadFromFileToTree(root);
	printTree(root);
	int result = resultOfTree(root);
	cout << endl << endl;
	cout << "Result of operations is " << result << endl;
	deleteTree(root);
}