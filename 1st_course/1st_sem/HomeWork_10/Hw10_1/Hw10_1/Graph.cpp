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

int **loadDatafromfile(ifstream &inputfile, int numberOfCities)
{
	int numberOfRoads;
	inputfile >> numberOfRoads;
	int **mapOfWorld = createDoubleArray(numberOfCities);
	for (int i = 0; i < numberOfRoads;i++)
	{
		int town_1 = 0;
		int town_2 = 0;
		int lengthOfRoad = 0;
		inputfile >> town_1;
		inputfile >> town_2;
		inputfile >> lengthOfRoad;
		mapOfWorld[town_1-1][town_2-1] = lengthOfRoad;
		mapOfWorld[town_2-1][town_1-1] = lengthOfRoad;
	}
	return mapOfWorld;
}

int foundingOfMinDistance(int *array[], bool isCitycaptured[])
{
	int minDistance = INT_MAX;
	for (int i = 0; i < sizeof(array); i++)
	{
		if (*array[i] < minDistance && *array[i] != 0 && !isCitycaptured[i])
		{
			minDistance = *array[i];
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

int foundingOfTheNearestFreeTown(int **map[], List *&ListWithTowns, bool isCitycaptured[])
{
	List *copyOfList = ListWithTowns;
	int townWithNearestFreeTown = 0;
	int minDistance = INT_MAX;
	while (copyOfList)
	{
		if (foundingOfMinDistance(map[copyOfList->value], isCitycaptured) < minDistance && foundingOfMinDistance(map[copyOfList->value], isCitycaptured) != -1)
		{
			minDistance = foundingOfMinDistance(map[copyOfList->value], isCitycaptured);
			townWithNearestFreeTown = copyOfList->value;
		}
		copyOfList = copyOfList->next;
	}
	int i = 0;
	if (minDistance == INT_MAX)
	{
		return 0;
	}
	while ((*map[townWithNearestFreeTown][i] != minDistance) && !isCitycaptured[i])
	{
		i++;
	}
	return i;
}

List **creatingCoutries(ifstream &inputFile, int countOfCapitals)
{
	int numberOfCities = 0;
	inputFile >> numberOfCities;
	int **mapOfWorld = loadDatafromfile(inputFile, numberOfCities);
	bool *isCitycaptured = new bool[numberOfCities] {false};
	List **citiesOfCountries = new List*[countOfCapitals]{nullptr};
	for (int i = 0; i <= countOfCapitals; i++)
	{
		isCitycaptured[i] = true;
		push(i, citiesOfCountries[i]);
	}
 	for (int i = countOfCapitals; i <= numberOfCities; i++)
	{
		int newTown = foundingOfTheNearestFreeTown(&mapOfWorld, citiesOfCountries[i % countOfCapitals], isCitycaptured);
		if (newTown != 0)
		{
			push(newTown + 1, citiesOfCountries[i % countOfCapitals]);
			isCitycaptured[i] = true;
		}
	}
	return citiesOfCountries;
}

void printMap(List **mapOfCountries)
{
	for (int i = 0; i < sizeof(mapOfCountries); i++)
	{
		printList(mapOfCountries[i]);
	}
}

void deleteMap(List **&mapOfcountries)
{
	for (int i = 0; i <= sizeof(mapOfcountries); i++)
	{
		deleteList(mapOfcountries[i]);
	}
	delete[] mapOfcountries;
	mapOfcountries = nullptr;
}