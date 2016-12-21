#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

void main()
{
	ifstream inputFile("inputFile.txt");
	cout << "Enter number of countries ";
	int countOfCapitals = 0;
	cin >> countOfCapitals;
	List **mapOfWorld = creatingCoutries(inputFile, countOfCapitals);
	printMap(mapOfWorld, countOfCapitals);
	deleteMap(mapOfWorld, countOfCapitals);
}