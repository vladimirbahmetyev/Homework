#include "Graph.h"

using namespace std;

struct Tree
{
	int numberOfRoot;
	Tree *leftSon;
	Tree *rightSon;
};

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

bool isAllRootUsed(bool  isRootAlreadyUse[], int countOfRoots)
{
	bool flag = true;
	for (int i = 0; i < countOfRoots; i++)
	{
		flag = flag && isRootAlreadyUse[i];
	}
	return flag;
}

int foundingOfMinDistanceInMatrix(Tree *&root, bool isRootAlreadyUse[], int **matrix, int sizeOfMatrix)
{
	int minDistance = INT_MAX;
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		if (matrix[root->numberOfRoot][i] < minDistance && !isRootAlreadyUse[i])
		{			
			minDistance = matrix[root->numberOfRoot][i];
		}
	}
	if (minDistance == INT_MAX)
	{
		return -1;
	}
	else
	{
		return minDistance;
	}
}

int foundingTheNearestTown(bool isRootAlreadyUse[], int **matrix, int sizeOfMatrix, int minDistance, int nameOfRoot)
{
	int i = 0;
	while (minDistance != matrix[nameOfRoot][i] && !isRootAlreadyUse[i])
	{
		i++;
	}
	return i;
}


Tree transFormingGraphToTree(ifstream &inputFile)
{
	int sizeOfMatrix = 0;
	inputFile >> sizeOfMatrix;
	int **matrix = loadMatrixFromFile(inputFile, sizeOfMatrix);
	bool *isRootAlreadyUse = new bool[sizeOfMatrix] {false};
	Tree *root = new Tree{ 0, nullptr, nullptr };
	while (!isAllRootUsed(isRootAlreadyUse, sizeOfMatrix))
	{

	}
}
