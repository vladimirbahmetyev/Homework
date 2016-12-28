#include "Graph.h"
#include "stack.h"
#include <iostream>

using namespace std;

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

int foundingOfMinDistance(int nameOfRoot, bool isRootUsed[],int **matrix, int sizeOfMatrix)
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
	List *listOfRoots = nullptr;
	push(0, listOfRoots);
	isRootUsed[0] = true;
	for (int i = 1; i < sizeOfMatrix; i++)
	{
		int theNearestRoot = foundingTheNearestRoot(listOfRoots, isRootUsed, matrix, sizeOfMatrix);
		int minDistance = foundingOfMinDistance(theNearestRoot, isRootUsed, matrix, sizeOfMatrix);
		int newRoot = foundingRoot(theNearestRoot, isRootUsed, matrix, sizeOfMatrix, minDistance);
		push(newRoot, listOfRoots);
		isRootUsed[newRoot] = true;
	}
	return listOfRoots;
}

bool checkingForTest(List *&testList, List *&keyList)
{
	bool flag = true;
	while (nextHead(testList))
	{
		flag = flag && (pop(testList) == pop(keyList));
	}
	return flag;
}

void test1()
{
	ifstream inputFile("testByMariia.txt");
	List *testList = transFormingGraphToList(inputFile);
	List *keyList = nullptr;
	push(0, keyList);
	push(1, keyList);
	push(3, keyList);
	push(4, keyList);
	push(2, keyList);
	if (checkingForTest(testList, keyList))
	{
		cout << "Test 1 completed" << endl;
	}
	else
	{
		cout << "Test 1 failed" << endl;
	}
}

void test2()
{
	ifstream inputFile("testByAlexey");
	List *testList = transFormingGraphToList(inputFile);
	List *keyList = nullptr;
	push(0, keyList);
	push(3, keyList);
	push(4, keyList);
	push(5, keyList);
	push(6, keyList);
	push(2, keyList);
	push(1, keyList);
	if (checkingForTest(testList, keyList))
	{
		cout << "Test 2 completed" << endl;
	}
	else
	{
		cout << "Test 2 failed" << endl;
	}
}