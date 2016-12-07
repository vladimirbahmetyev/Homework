#include <cstdio>

const int quantityOfNumbers = 10;

void printArray(int array[])
{
	for (int i = 0; i < quantityOfNumbers; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void changeArray(int array[], int firstElement, int lastElement)
{
	while (firstElement < lastElement)
	{
		int zeroVariable = array[lastElement];
		array[lastElement] = array[firstElement];
		array[firstElement] = zeroVariable;
		firstElement++;
		lastElement--;
	}
}

int main()
{
	int array[quantityOfNumbers] = {};
	for (int i = 0; i < quantityOfNumbers; i++)
	{
		array[i] = i;
	}
	printArray(array);
	printf("input first number of the end: ");
	int numberOfTheFirstElement = 0;
	scanf_s("%d", &numberOfTheFirstElement);
	changeArray(array, 0, numberOfTheFirstElement - 2);
	changeArray(array, numberOfTheFirstElement - 1, quantityOfNumbers - 1);
	changeArray(array, 0, quantityOfNumbers - 1);
	printArray(array);
	return 0;
}