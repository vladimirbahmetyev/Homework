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

bool checkArray(int arrayOne[], int arrayTwo[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (arrayOne[i] != arrayTwo[i])
		{
			return false;
		}
	}
	return true;
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
		array[i] = rand() % 50;
	}
}

void qSort(int array[],int leftElement, int rightElement)
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

bool fullTest(int array[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			printf("%s %d\n", "Error in element number", i);
			return false;
		}
	}
	return true;
}

void test_1()
{
	int checkingArray[5] = { 4, 5, 1, 3, 2 };
	int rightArray[5] = { 1, 2, 3, 4, 5 };
	qSort(checkingArray, 0, 4);
	if ((checkArray(checkingArray, rightArray, 5)))
	{
		printf("Test_1 complete\n");
	}
	else
	{
		printf("Test_1 failed\n");
	}
}

void test_2()
{
	int checkingArray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int rightArray[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	qSort(checkingArray, 0, 9);
	if ((checkArray(checkingArray, rightArray, 10)))
	{
		printf("Test_2 complete\n");
	}
	else
	{
		printf("Test_2 failed\n");
	}
}

void test_3()
{
	int checkingArray[10] = { 999, 499, 399, 299, 199, 199, 99, 9, 1, 0 };
	int rightArray[10] = { 0, 1, 9, 99, 199, 199, 299, 399, 499, 999 };
	qSort(checkingArray, 0, 9);
	if ((checkArray(checkingArray, rightArray, 10)))
	{
		printf("Test_3 complete\n");
	}
	else
	{
		printf("Test_3 failed\n");
	}
}

int main()
{
	printf("Input number of elements in array ");
	int numberOfElements = 0;
	scanf_s(" %d", &numberOfElements);
	int *array = new int[numberOfElements] {};
	inputArray(array, numberOfElements);
	printf("Array before sort\n");
	printArray(array, numberOfElements);
	qSort(array, 0, numberOfElements - 1);
	printf("Array after sort\n");
	printArray(array, numberOfElements);
	if (fullTest(array, numberOfElements))
	{
		printf("Sort is Right\n");
	}
	else
	{
		printf("Sort if False\n");
	}
	test_1();
	test_2();
	test_3();
	delete[] array;
	array = nullptr;
	return 0;
}