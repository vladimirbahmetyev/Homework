#include "sorts.h"
#include <iostream>
#include <fstream>

using namespace std;

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