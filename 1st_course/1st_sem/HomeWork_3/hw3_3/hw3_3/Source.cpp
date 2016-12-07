#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void printArray(int array[], int numberOfNumbers)
{
	for (int i = 0; i < numberOfNumbers; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void insertionSort(int array[], int leftElement, int rightElement)
{
	for (int i = 1; i < rightElement - leftElement + 1; i++)
	{
		int j = i + leftElement;
		while ((array[j] < array[j - 1]) && (j != 0))
		{
			swap(array[j], array[j - 1]);
			j--;
		}
	}
}

void inputArray(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray; i++)
	{
		array[i] = rand() % 10000;
	}
}

void qSort(int array[], int leftElement, int rightElement)
{
	if ((rightElement - leftElement + 1) <= 2)
	{
		insertionSort(array, leftElement, rightElement);
	}
	else
	{
		int i = leftElement + 1;
		int j = rightElement;
		int mainElement = leftElement;
		while (i < j + 1)
		{
			while (array[i] < array[mainElement])
			{
				i++;
			}
			while (array[j] > array[mainElement])
			{
				j--;
			}
			if (i <= j)
			{
				swap(array[i], array[j]);
				i++;
				j--;
			}
		}
		swap(array[mainElement], array[j]);
		qSort(array, leftElement, j);
		qSort(array, j + 1, rightElement);
	}
}

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

void test_1()
{
	int array[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	if (1 == searchingOfMainElement(array, 10))
	{
		printf("Test_1 completed\n");
	}
	else
	{
		printf("Test_1 failed\n");
	}
}

void test_2()
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
	int const sizeOfArray = 100000;
	int array[sizeOfArray] = {};
	inputArray(array, sizeOfArray);
	printf("Array:\n");
	//printArray(array, sizeOfArray);
	qSort(array, 0, sizeOfArray - 1);
	printArray(array, sizeOfArray);
	printf ("%s %d\n", "The main element is", searchingOfMainElement(array, sizeOfArray));
	test_1();
	test_2();
	return 0;
}