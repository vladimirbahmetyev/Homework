#include "Graph.h"

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

int **loadDatafromfile(ifstream &inputfile)
{
	int sizeOfMap = 0;
	inputfile >> sizeOfMap;
	int **WorldMap = createDoubleArray(sizeOfMap);
	return WorldMap;
}

int foundingOfMinDistance(int array[], bool *&isCitycaptured)
{
	int minDistance = INT_MAX;
	for (int i = 0; i < sizeof(array); i++)
	{
		if (array[i] < minDistance && array[i] != 0 && !isCitycaptured[i])
		{
			minDistance = array[i];
		}
	}
	if (minDistance = INT_MAX)
	{
		return -1;
	}
	else
	{
		return minDistance;
	}
}

int foundingOfTheNearestFreeTown(List *&map, bool *isCitycaptured)
{
	List *copyOfMap = map;
	int townWithNearestFreeTown = 0;
	int minDistance = INT_MAX;
	while (copyOfMap->next)
	{
		if (foundingOfMinDistance(&copyOfMap->value, isCitycaptured) < minDistance && foundingOfMinDistance(&copyOfMap->value, isCitycaptured) != -1)
		{
			minDistance = foundingOfMinDistance(&copyOfMap->value, isCitycaptured);
			townWithNearestFreeTown = copyOfMap->value;
		}
		pop(copyOfMap);
	}
	return townWithNearestFreeTown;
}

List **creatingCoutries(ifstream &inputFile)
{
	int numberOfCountries = 0;
	inputFile >> numberOfCountries;
	int **mapOfWorld = loadDatafromfile(inputFile);
	int countOfCities = sizeof(mapOfWorld);
	bool *isCitycaptured = new bool[countOfCities];
	List **citiesOfCountries = new List*[numberOfCountries]{nullptr};
	for (int i = 0; i < numberOfCountries; i++)
	{
		isCitycaptured[i] = true;
		push(i, citiesOfCountries[i]);
	}
	for (int i = numberOfCountries; i < countOfCities; i++)
	{
		int newTown = foundingOfTheNearestFreeTown(citiesOfCountries[i % sizeof(citiesOfCountries)], isCitycaptured);
		if (newTown != 0)
		{
			push(newTown, citiesOfCountries[i % sizeof(citiesOfCountries)]);
			isCitycaptured[i] = true;
		}
	}
	return citiesOfCountries;
}

void printMap(List **mapOfcounries)
{
	for (int i = 0; i < sizeof(mapOfcounries); i++)
	{
		printList(mapOfcounries[i]);
	}
}

void deleteMap(List **&mapOfcountries)
{
	for (int i = 0; i < sizeof(mapOfcountries); i++)
	{
		deleteList(mapOfcountries[i]);
	}
	delete[] mapOfcountries;
	mapOfcountries = nullptr;
}