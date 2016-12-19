#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

int **createDoubleArray(int sizeOfGraph);

int **loadDatafromfile(ifstream &inputfile);

int foundingOfMinDistance(int array[], bool *&isCitycaptured);

int foundingOfTheNearestFreeTown(List *&map, bool *isCitycaptured);

List **creatingCoutries(ifstream &inputFile);

void printMap(List **mapOfcounries);

void deleteMap(List **&mapOfcountries);