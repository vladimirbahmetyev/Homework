#include "load.h"
#include <iostream>
#include <fstream>

using namespace std;

void inputArrayFromFile(int array[], int sizeOfArray)
{
	ifstream file("inputFile.txt");
	if (!file.is_open())
	{
		printf("Error, opening file failed");
	}
	else
	{
		for (int i = 0; i < sizeOfArray; i++)
		{
			file >> array[i];
		}
	}
	file.close();
}