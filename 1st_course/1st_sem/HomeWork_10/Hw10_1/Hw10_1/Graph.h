#pragma once

#include <fstream>
#include "stack.h"

using namespace std;

//Create Matrix
int **createDoubleArray(int sizeOfGraph);

//Load data to Matrix
int **loadDataFromFile(ifstream &inputFile, int numberOfCities);

//Found min distance from numberOfCity to nearest free city
int foundingOfMinDistance(int **mapOfWorld, bool isCity—aptured[], int numberOfCities, int numberOfCity);

//Founding the town with the nearest free town
int foundingOfTheNearestFreeTown(int **map, List *&ListWithTowns, bool isCity—aptured[], int numberOfCities);

//Cheking is there any free cities
bool isAllCitiesCaptured(bool isCity—aptured[], int numberOfCities);

//Create countries
List **creatingCoutries(ifstream &inputFile, int countOfCapitals);

//Print list of countries with their cities
void printMap(List **mapOfCountries, int numberOfCountries);

//Delete map
void deleteMap(List **&mapOfcountries, int numberOfCountries);