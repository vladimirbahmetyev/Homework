#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	ifstream inputFile("inputFile.txt");
	cout << "¬ведите кол-во стран ";
	int countOfCapitals = 0;
	cin >> countOfCapitals;
	List **mapOfWorld = creatingCoutries(inputFile, countOfCapitals);
	printMap(mapOfWorld);
	deleteMap(mapOfWorld);
	system("pause");
}