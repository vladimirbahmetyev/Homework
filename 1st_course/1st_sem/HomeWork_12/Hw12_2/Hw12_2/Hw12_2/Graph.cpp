#include "Graph.h"
#include "stack.h"

using namespace std;

int **createMatrix(int sizeOfMatrix)
{
	int **matrix = new int*[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		matrix[i] = new int[sizeOfMatrix] {0};
	}
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

int foundingOfMinDistance(int nameOfRoot,bool isRootUsed[],int **matrix, int sizeOfMatrix )
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

int foundingTheNearestRoot(List *&listOfRoots, bool isRootUsed[], int **matrix, int sizeOfMatrix)
{
	List *cursor = listOfRoots;
	int minDistance = INT_MAX;
	int theNearestRoot = -1;
	while (cursor)
	{
		int checkDistance = foundingOfMinDistance(cursor->value, isRootUsed, matrix, sizeOfMatrix);
		if (minDistance > checkDistance && checkDistance != -1)
		{
			minDistance = checkDistance;
			theNearestRoot = cursor->value;
		}
		cursor = cursor->next;
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

int foundingRoot(int nameOfRoot, bool isRootUsed[], int **matrix,int sizeOfMatrix, int minDistance)
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		if (matrix[i][nameOfRoot] == minDistance && !isRootUsed[i])
		{
			return i;
		}
	}
}

List *transFormingGraphToList(ifstream &inputFile)
{
	int sizeOfMatrix = 0;
	inputFile >> sizeOfMatrix;
	int **matrix = loadMatrixFromFile(inputFile, sizeOfMatrix);
	bool *isRootUsed = new bool[sizeOfMatrix] {false};
	List *listOfRoots = new List{ 0,nullptr };
	for (int i = 1; i < sizeOfMatrix; i++)
	{
		int theNearestRoot = foundingTheNearestRoot(listOfRoots, isRootUsed, matrix, sizeOfMatrix);
		if (theNearestRoot != -1)
		{
			int minDistance = foundingOfMinDistance(theNearestRoot, isRootUsed, matrix, sizeOfMatrix);
			int newRoot = foundingRoot(listOfRoots->value, isRootUsed, matrix, sizeOfMatrix, minDistance);
			push(newRoot, listOfRoots);
			isRootUsed[newRoot] = true;
		}
	}
	return listOfRoots;
}
