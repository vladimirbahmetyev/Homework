#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

int **createDoubleArray(int sizeOfGraph);

int **loadDatafromfile(ifstream &inputfile, int numberOfCities);

int foundingOfMinDistance(int *array[], bool isCitycaptured[]);

int foundingOfTheNearestFreeTown(int **map[], List *&ListWithTowns, bool isCitycaptured[]);

List **creatingCoutries(ifstream &inputFile, int countOfCapitals);

void printMap(List **mapOfcounries);

void deleteMap(List **&mapOfcountries);