#include "stack.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void main()
{
	ifstream inputFile("inputFile.txt");
	List *ostTree = transFormingGraphToList(inputFile);
	inputFile.close();
	cout << "Min ost tree :" << endl;
	ostTree = transformList(ostTree);
	printList(ostTree);
	deleteList(ostTree);
	test1();
	test2();
	system("pause");
}