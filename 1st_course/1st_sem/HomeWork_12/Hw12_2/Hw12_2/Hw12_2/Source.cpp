#include "stack.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void main()
{
	ifstream inputFile("inputFile.txt");
	List *ostTree = transFormingGraphToList(inputFile);
	cout << "Min ost tree :" << endl;
	printList(ostTree);
	system("pause");
}