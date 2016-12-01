#include <cstdio>
#include <cstdlib>

int fibonaciRecursive(int preFib)
{
	if ((preFib == 0) || (preFib == 1))
	{
		return 1;
	}
	else
	{
		return (fibonaciRecursive(preFib - 1) + fibonaciRecursive(preFib - 2));
	}
}

int fibonaciLine(int numberOfFibbanaci)
{
	int fibbanaci1 = 1;
	int fibbanaci2 = 1;
	int fibbanaci3 = 0;
	for (int i = 0; i < numberOfFibbanaci - 1; i++)
	{
		fibbanaci3 = fibbanaci2 + fibbanaci1;
		fibbanaci1 = fibbanaci2;
		fibbanaci2 = fibbanaci3;
	}
	return fibbanaci2;
}

int main()
{
	int numberOfFibbanaci = 0;	
	printf("Input number of Fibbanaci ");
	scanf_s("%d", &numberOfFibbanaci);	
	printf("%s %d %s\n", "Your Fibbanacci is", fibonaciLine(numberOfFibbanaci - 1), "(line algorithm)");
	printf("%s %d %s\n", "Your Fibbanaci is ", fibonaciRecursive(numberOfFibbanaci - 1), "(recursive algorithm)");
	system("pause");
	return 0;
}