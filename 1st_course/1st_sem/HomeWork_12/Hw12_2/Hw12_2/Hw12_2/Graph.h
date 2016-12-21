#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

int **createMatrix(int sizeOfMatrix);

int **loadMatrixFromFile(ifstream &inputFile, int sizeOfMatrix);

int foundingOfMinDistance(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix);

int foundingTheNearestRoot(List *&listOfRoots, bool isRootUsed[], int **matrix, int sizeOfMatrix);

int foundingRoot(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix, int minDistance);

List *transFormingGraphToList(ifstream &inputFile);