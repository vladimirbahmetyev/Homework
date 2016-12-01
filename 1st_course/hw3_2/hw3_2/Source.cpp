#include <cstdlib>
#include <cstdio>
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

void qSort(int array[], int leftElement, int rightElement)
{
	if ((rightElement - leftElement + 1) <= 10)
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

void inputArray(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray; i++)
	{
		array[i] = (rand() * rand()) % 1000000000;
	}
}

bool searchingInArray(int array[], int leftElement, int rightElement, int searchElement)
{
	if (array[(leftElement + rightElement) / 2] == searchElement)
	{
		return true;
	}
	if (leftElement == rightElement)
	{
		return false;
	}
	if (array[(leftElement + rightElement) / 2] > searchElement)
	{
		return searchingInArray(array, leftElement, (leftElement + rightElement) / 2, searchElement);
	}
	else
	{
		return searchingInArray(array, (leftElement + rightElement) / 2 + 1, rightElement, searchElement);
	}
		
}

void test1()
{
	int array[10] = { 4, 3, 2, 6, 7, 9, 0, 1, 5, 8 };
	qSort(array, 0, 9);
	if (searchingInArray(array, 0, 9, 5))
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
	int array[10] = { 10, 9, 8, 6, 5, 4, 3, 2, 1, 0 };
	qSort(array, 0, 9);
	if (!(searchingInArray(array, 0, 9, 7)))
	{
		printf("Test_1 completed\n");
	}
	else
	{
		printf("Test_1 failed\n");
	}
}

int main()
{
	printf("Input n (1 <= n <= 5000) "); 
	int sizeOfArray = 0;
	scanf_s("%d", &sizeOfArray);
	int *array = new int[sizeOfArray];
	inputArray(array, sizeOfArray);
	qSort(array, 0, sizeOfArray - 1);
	printArray(array, sizeOfArray);
	printf("Input k (1 <= k <= 300000) ");
	int numberOfChekingElements = 0;
	scanf_s("%d", &numberOfChekingElements);
	for (int i = 0; i < numberOfChekingElements; i++)
	{
		int chekingElement = (rand() * rand()) % 1000000000;
		if (searchingInArray(array, 0, sizeOfArray, chekingElement))
		{
			printf("%s %d %s", "The number", chekingElement, "is in array\n");
		}
	}
	delete[] array;
	array = nullptr;
	test1();
	test2();
	return 0;
}