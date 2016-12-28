#include <cstdio>
#include <iostream>
#include "Tree.h"

using namespace std;

void main()
{
	Tree *root = nullptr;
	loadFromFileToTree(root);
	printTree(root);
	int result = resultOfTree(root);
	cout << endl << endl;
	cout << "Result of operations is " << result << endl;
	deleteTree(root);
}