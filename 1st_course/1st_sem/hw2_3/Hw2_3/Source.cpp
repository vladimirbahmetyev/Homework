#include <cstdio>

const int numberOfNumbers = 20;

void copyArray(int arrayOne[], int arrayTwo[])
{
	for (int i = 0; i < numberOfNumbers; i++)
	{
		arrayTwo[i] = arrayOne[i];
	}
}

void bubble(int array[], int length)
{
	for (int i = 0; i < length - 1; i++) 
	{
		bool swapped = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1]) 
			{
				int changeElement = array[j];
				array[j] = array[j + 1];
				array[j + 1] = changeElement;
				swapped = true;
			}
		}
			if (!swapped)
		{
			break;
		}
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void inputArray(int array[])
{
	printf("Input twenty elements of array\n");
	for (int i = 0; i < numberOfNumbers; i++)
	{
		printf("%s %d %s", "Input", i + 1, "element:");
		scanf_s("%d\n", &array[i]);
	}
}

void countingSort(int array[])
{
	int arrayOfNumbers[1000] = {};
	int countElement = 0;
	for (int i = 0; i < numberOfNumbers; i++)
	{
		arrayOfNumbers[array[i]]++;
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < arrayOfNumbers[i]; j++)
		{
			array[countElement] = i;
			countElement++;
		}
	}
}

int main()
{
	int arrayOne[numberOfNumbers] = {};
	int arrayTwo[numberOfNumbers] = {};
	inputArray(arrayOne);
	copyArray(arrayOne, arrayTwo);
	printf("Array before sort\n");
	printArray(arrayOne, numberOfNumbers);
	bubble(arrayOne, numberOfNumbers);
	printf("Array after babble sort\n");
	printArray(arrayOne, numberOfNumbers); 
	printf("Array after counting sort\n");
	countingSort(arrayTwo);
	printArray(arrayTwo, numberOfNumbers);
	return 0;
}