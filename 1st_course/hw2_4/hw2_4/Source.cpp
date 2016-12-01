#include <cstdio>
#include <cstdlib>

int const numberOfNumber = 20;

void inputArray(int array[])
{
	for (int i = 0; i < numberOfNumber; i++)
	{
		array[i] = rand()%20;
	}
}

void printArray(int array[])
{
	for (int i = 0; i < numberOfNumber; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void beginOfQSort(int array[])
{
	int i = 1;
	int j = numberOfNumber - 1;
	while (j > i)
	{
		while (array[i] <= array[0])
		{
			i++;
		}
		while (array[j] >= array[0])
		{
			j--;
		}
		if (j <= i)
		{
			return;
		}
		int numberForSwap = 0;
		numberForSwap = array[i];
		array[i] = array[j];
		array[j] = numberForSwap;
	}
}

int main()
{
	int array[numberOfNumber] = {};
	inputArray(array);
	printf("Array before sort\n");
	printArray(array);
	beginOfQSort(array);
	printf("Array after sort\n");
	printArray(array);
	return 0;
}