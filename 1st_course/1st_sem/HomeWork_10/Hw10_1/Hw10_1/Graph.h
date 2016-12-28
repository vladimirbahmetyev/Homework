#pragma once

#include <fstream>
#include "stack.h"

//Create countries
List **creatingCoutries(std::ifstream &inputFile, int countOfCapitals);

//Print list of countries with their cities
void printMap(List **mapOfCountries, int numberOfCountries);

//Delete map
void deleteMap(List **&mapOfcountries, int numberOfCountries);