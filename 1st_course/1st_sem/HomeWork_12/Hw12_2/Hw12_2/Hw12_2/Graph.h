#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

//Delete Matrix
void deleteMatrix(int **&matrix, int sizeOfMatrix);

//Create Matrix
int **createMatrix(int sizeOfMatrix);

//Load matrix from file
int **loadMatrixFromFile(ifstream &inputFile, int sizeOfMatrix);

//Find the lest distance benween two roots
int foundingOfMinDistance(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix);

//Find root with the nearest free root
int foundingTheNearestRoot(Stack *&StackOfRoots, bool isRootUsed[], int **matrix, int sizeOfMatrix);

//Find root on distance
int foundingRoot(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix, int minDistance);

//Transform graph to Stack
int **transFormingGraphToOstTree(ifstream &inputFile, int sizeOfMatrix);

//Cheking twst with key
bool checkingForTest(Stack *&testStack, Stack *&keyStack);

//Print Matrix
void printMatrix(int **matrix, int sizeOfMatrix);