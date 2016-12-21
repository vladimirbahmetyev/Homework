#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

//Create Matrix
int **createMatrix(int sizeOfMatrix);

//Load matrix from file
int **loadMatrixFromFile(ifstream &inputFile, int sizeOfMatrix);

//Find the lest distance benween two roots
int foundingOfMinDistance(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix);

//Find root with the nearest free root
int foundingTheNearestRoot(List *&listOfRoots, bool isRootUsed[], int **matrix, int sizeOfMatrix);

//Find root on distance
int foundingRoot(int nameOfRoot, bool isRootUsed[], int **matrix, int sizeOfMatrix, int minDistance);

//Transform graph to list
List *transFormingGraphToList(ifstream &inputFile);

//Cheking twst with key
bool checkingForTest(List *&testList, List *&keyList);

//Test_1
void test1();

//Test_2
void test2();