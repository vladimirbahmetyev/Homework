#include "Graph.h"
#include "stack.h"
#include <iostream>

using namespace std;

void deleteMatrix(int **matrix, int sizeOfMatrix)
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		delete matrix[i];
	}
	delete matrix;
	matrix = nullptr;
}

int **createMatrix(int sizeOfMatrix)
{
	int **matrix = new int*[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		matrix[i] = new int[sizeOfMatrix] {0};
	}
	return matrix;
}

int **loadMatrixFromFile(ifstream &inputFile, int sizeOfMatrix)
{
	int **matrix = createMatrix(sizeOfMatrix);
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			inputFile >> matrix[i][j];
		}
	}
	return matrix;
}

int foundingOfMinDistance(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix)
{
	int minDistance = INT_MAX;
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		if (!isRootUsed[i] && matrix[i][nameOfRoot] < minDistance && matrix[i][nameOfRoot] != 0)
		{
			minDistance = matrix[i][nameOfRoot];
		}
	}
	if (minDistance != INT_MAX)
	{
		return minDistance;
	}
	else
	{
		return -1;
	}
}

int foundingTheNearestRoot(Stack *&stackOfRoots, bool isRootUsed[], int **matrix, int sizeOfMatrix)
{
	Stack *cursor = stackOfRoots;
	int minDistance = INT_MAX;
	int theNearestRoot = -1;
	while (cursor)
	{
		int checkDistance = foundingOfMinDistance(valueFromHead(cursor), isRootUsed, matrix, sizeOfMatrix);
		if (minDistance > checkDistance && checkDistance != -1)
		{
			minDistance = checkDistance;
			theNearestRoot = valueFromHead(cursor);
		}
		cursor = nextHead(cursor);
	}
	if (minDistance != INT_MAX)
	{
		return theNearestRoot;
	}
	else
	{
		return -1;
	}
}

int foundingRoot(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix, int minDistance)
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		if (matrix[i][nameOfRoot] == minDistance && !isRootUsed[i])
		{
			return i;
		}
	}
}

int **transFormingGraphToStack(ifstream &inputFile, int sizeOfMatrix)
{
	int **matrix = loadMatrixFromFile(inputFile, sizeOfMatrix);
	bool *isRootUsed = new bool[sizeOfMatrix] {false};
	Stack *stackOfRoots = nullptr;
	push(0, stackOfRoots);
	isRootUsed[0] = true;
	int **minOstTreeMatrix = createMatrix(sizeOfMatrix);
	for (int i = 1; i < sizeOfMatrix; i++)
	{
		int theNearestRoot = foundingTheNearestRoot(stackOfRoots, isRootUsed, matrix, sizeOfMatrix);
		int minDistance = foundingOfMinDistance(theNearestRoot, isRootUsed, matrix, sizeOfMatrix);
		int newRoot = foundingRoot(theNearestRoot, isRootUsed, matrix, sizeOfMatrix, minDistance);
		minOstTreeMatrix[theNearestRoot][newRoot] = minDistance;
		push(newRoot, stackOfRoots);
		isRootUsed[newRoot] = true;
	}
	deleteMatrix(matrix, sizeOfMatrix);
	return minOstTreeMatrix;
}

bool checkingForTest(Stack *&testStack, Stack *&keyStack)
{
	bool flag = true;
	while (nextHead(testStack))
	{
		flag = flag && (pop(testStack) == pop(keyStack));
	}
	return flag;
}

void printMatrix(int **matrix, int sizeOfMatrix)
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl << endl;
	}
}