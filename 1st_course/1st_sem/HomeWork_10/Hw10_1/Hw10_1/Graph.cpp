#include "Graph.h"
#include <iostream>

using namespace std;
 
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
	int numberOfRoads;
	inputFile >> numberOfRoads;
	int **mapOfWorld = createDoubleArray(numberOfCities);
	for (int i = 0; i < numberOfRoads;i++)
	{
		int City1 = 0;
		int City2 = 0;
		int lengthOfRoad = 0;
		inputFile >> City1;
		inputFile >> City2;
		inputFile >> lengthOfRoad;
		mapOfWorld[City1-1][City2-1] = lengthOfRoad;
		mapOfWorld[City2-1][City1-1] = lengthOfRoad;
	}
	return mapOfWorld;
}

int foundingOfMinDistance(int **mapOfWorld, bool isCityÑaptured[], int numberOfCities, int numberOfCity)
{
	int minDistance = INT_MAX;
	for (int i = 0; i <= numberOfCities; i++)
	{
		if (mapOfWorld[numberOfCity][i] < minDistance && mapOfWorld[numberOfCity][i] != 0 && !isCityÑaptured[i])
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

int foundingOfTheNearestFreeCity(int **map, List *&ListWithCitys, bool isCityÑaptured[], int numberOfCities)
{
	List *copyOfList = ListWithCitys;
	int CityWithNearestFreeCity = 0;
	int minDistance = INT_MAX;
	while (copyOfList)
	{
		if (foundingOfMinDistance(map, isCityÑaptured, numberOfCities, copyOfList->value) < minDistance && foundingOfMinDistance(map, isCityÑaptured, numberOfCities, copyOfList->value) != -1)
		{
			minDistance = foundingOfMinDistance(map, isCityÑaptured, numberOfCities, copyOfList->value);
			CityWithNearestFreeCity = copyOfList->value;
		}
		copyOfList = copyOfList->next;
	}
	int i = 0;
	if (minDistance == INT_MAX)
	{
		return 0;
	}
	while ((map[CityWithNearestFreeCity][i] != minDistance) || isCityÑaptured[i])
	{
		i++;
	}
	return i;
}

bool isAllCitiesCaptured(bool isCityÑaptured[], int numberOfCities)
{
	bool flag = true;
	for (int i = 0; i <= numberOfCities; i++)
	{
		flag = flag && isCityÑaptured[i];
	}
	return flag;
}

List **creatingCoutries(ifstream &inputFile, int countOfCapitals)
{
	int numberOfCities = 0;
	inputFile >> numberOfCities;
	int **mapOfWorld = loadDataFromFile(inputFile, numberOfCities);
	bool *isCityÑaptured = new bool[numberOfCities] {false};
	List **citiesOfCountries = new List*[countOfCapitals]{nullptr};
	for (int i = 0; i < countOfCapitals; i++)
	{
		isCityÑaptured[i] = true;
		push(i, citiesOfCountries[i]);
	}
	int i = countOfCapitals;
	while(!isAllCitiesCaptured(isCityÑaptured, numberOfCities))
	{
		int newCity = foundingOfTheNearestFreeCity(mapOfWorld, citiesOfCountries[i % countOfCapitals], isCityÑaptured, numberOfCities);
		if (newCity != 0)
		{
			push(newCity, citiesOfCountries[i % countOfCapitals]);
			isCityÑaptured[newCity] = true;
		}
		i++;
	}
	return citiesOfCountries;
}

void printMap(List **mapOfCountries, int numberOfCountries)
{
	for (int i = 0; i < numberOfCountries; i++)
	{
		cout << "Citys of " << i + 1 << " country ";
		printList(mapOfCountries[i]);
	}
}

void deleteMap(List **&mapOfcountries, int numberOfCountries)
{
	for (int i = 0; i < numberOfCountries; i++)
	{
		deleteList(mapOfcountries[i]);
	}
	delete[] mapOfcountries;
	mapOfcountries = nullptr;
}