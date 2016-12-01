#include <cstdio>
#include <cstdlib>
#include "sorts.h"
#include "load.h"

using namespace std;

int searchingOfMainElement(int array[], int sizeOfArray)
{
	int mainElement = 0;
	int numberOfMainElement = 0;
	int element = -1;
	int numberOfElement = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (array[i] == element)
		{
			numberOfElement++;
		}
		else
		{
			element = array[i];
			numberOfElement = 1;
		}
		if (numberOfElement > numberOfMainElement)
		{
			mainElement = element;
			numberOfMainElement = numberOfElement;
		}
	}
	return mainElement;
}

void printfArray(int array[], int sizeOfArray)
{
	printf("Array from file:");
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test1()
{
	int array[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	if (1 == searchingOfMainElement(array, 10))
	{
		printf("Test_1 completed\n");
	}
	else
	{
		printf("Test_1 failed\n");
	}
}

void test2()
{
	int array[10] = { 1, 2, 20, 40, 55, 55, 76, 99, 110, 101 };
	if (55 == searchingOfMainElement(array, 10))
	{
		printf("Test_2 completed\n");
	}
	else
	{
		printf("Test_2 failed\n");
	}
}

int main()
{
	const  int sizeOfArray = 20;
	int array[sizeOfArray] = {};
	inputArrayFromFile(array, sizeOfArray);
	qSort(array, 0, sizeOfArray - 1);
	printfArray(array, sizeOfArray);
	printf("%s %d\n", "The main element is", searchingOfMainElement(array, sizeOfArray));
	test1();
	test2();
	return 0;
}