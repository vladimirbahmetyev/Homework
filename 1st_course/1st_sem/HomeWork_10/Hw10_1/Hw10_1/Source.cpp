#include "Graph.h"
#include <fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	ifstream inputFile("inputFile.txt");
	int numberOfCountries = 0;
	inputFile >> numberOfCountries;
	List **mapOfWorld = creatingCoutries(inputFile);
	printMap(mapOfWorld);
	deleteMap(mapOfWorld);
	system("pause");
}