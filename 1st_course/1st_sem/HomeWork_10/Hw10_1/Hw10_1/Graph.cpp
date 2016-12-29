#include "Graph.h"
#include <iostream>

using namespace std;
 
void deleteMatrix(int **&matrix,int countOfCities)
{
	for (int i = 0; i < countOfCities; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

int **createDoubleArray(int sizeOfGraph)
{
	int **doubleArray = new int*[sizeOfGraph];
	for (int i = 0; i < sizeOfGraph; i++)
	{
		doubleArray[i] = new int[sizeOfGraph] {0};
	}
	return doubleArray;
}

int **loadDataFromFile(ifstream &inputFile, int numberOfCities)
{
	int numberOfRoads = 0;
	inputFile >> numberOfRoads;
	int **mapOfWorld = createDoubleArray(numberOfCities);
	for (int i = 0; i < numberOfRoads;i++)
	{
		int city1 = 0;
		int city2 = 0;
		int lengthOfRoad = 0;
		inputFile >> city1;
		inputFile >> city2;
		inputFile >> lengthOfRoad;
		mapOfWorld[city1 - 1][city2 - 1] = lengthOfRoad;
		mapOfWorld[city2 - 1][city1 - 1] = lengthOfRoad;
	}
	return mapOfWorld;
}

int foundingOfMinDistance(int **mapOfWorld, bool isCity�aptured[], int numberOfCities, int numberOfCity)
{
	int minDistance = INT_MAX;
	for (int i = 0; i <= numberOfCities; i++)
	{
		if (mapOfWorld[numberOfCity][i] < minDistance && mapOfWorld[numberOfCity][i] != 0 && !isCity�aptured[i])
		{
			minDistance = mapOfWorld[numberOfCity][i];
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

int foundingOfTheNearestFreeCity(int **map, Stack *&StackWithCities, bool isCity�aptured[], int numberOfCities)
{
	Stack *copyOfStack = nullptr;
	int CityWithNearestFreeCity = 0;
	int minDistance = INT_MAX;
	while (StackWithCities)
	{
		if (foundingOfMinDistance(map, isCity�aptured, numberOfCities, getValue(StackWithCities)) < minDistance && foundingOfMinDistance(map, isCity�aptured, numberOfCities, getValue(StackWithCities)) != -1)
		{
			minDistance = foundingOfMinDistance(map, isCity�aptured, numberOfCities, getValue(StackWithCities));
			CityWithNearestFreeCity = getValue(StackWithCities);
		}
		push(pop(StackWithCities), copyOfStack);
	}
	StackWithCities = copyOfStack;
	int i = 0;
	if (minDistance == INT_MAX)
	{
		return 0;
	}
	while ((map[CityWithNearestFreeCity][i] != minDistance) || isCity�aptured[i])
	{
		i++;
	}
	return i;
}

bool isAllCitiesCaptured(bool isCity�aptured[], int numberOfCities)
{
	bool flag = true;
	for (int i = 0; i <= numberOfCities; i++)
	{
		flag = flag && isCity�aptured[i];
	}
	return flag;
}

void printMap(Stack **mapOfCountries, int numberOfCountries)
{
	for (int i = 0; i < numberOfCountries; i++)
	{
		cout << "Cities of " << i + 1 << " country ";
		printStack(mapOfCountries[i]);
	}
}

void deleteMap(Stack **&mapOfcountries, int numberOfCountries)
{
	for (int i = 0; i < numberOfCountries; i++)
	{
		deleteStack(mapOfcountries[i]);
	}
	delete[] mapOfcountries;
	mapOfcountries = nullptr;
}

void creatingCoutries(ifstream &inputFile)
{
	int numberOfCities = 0;
	inputFile >> numberOfCities;
	int **mapOfWorld = loadDataFromFile(inputFile, numberOfCities);
	bool *isCity�aptured = new bool[numberOfCities] {false};
	int countOfCapitals = 0;
	inputFile >> countOfCapitals;
	Stack **citiesOfCountries = new Stack*[countOfCapitals]{nullptr};
	for (int i = 0; i < countOfCapitals; i++)
	{
		int capital = 0;
		inputFile >> capital;
		isCity�aptured[capital - 1] = true;
		push(capital - 1, citiesOfCountries[i]);
	}
	int i = 0;
	while (!isAllCitiesCaptured(isCity�aptured, numberOfCities))
	{
		int newCity = foundingOfTheNearestFreeCity(mapOfWorld, citiesOfCountries[i % countOfCapitals], isCity�aptured, numberOfCities);
		if (newCity != 0)
		{
			push(newCity, citiesOfCountries[i % countOfCapitals]);
			isCity�aptured[newCity] = true;
		}
		i++;
	}
	deleteMatrix(mapOfWorld, numberOfCities);
	printMap(citiesOfCountries, countOfCapitals);
	deleteMap(citiesOfCountries, countOfCapitals);
}