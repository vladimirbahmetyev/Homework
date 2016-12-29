#include "stack.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void main()
{
	ifstream inputFile("inputFile.txt");
	int sizeOfMatrix = 0;
	inputFile >> sizeOfMatrix;
	int **ostTree = transFormingGraphToStack(inputFile, sizeOfMatrix);
	inputFile.close();
	cout << "Min ost tree :" << endl;
	printMatrix(ostTree, sizeOfMatrix);
	deleteMatrix(ostTree, sizeOfMatrix);
}