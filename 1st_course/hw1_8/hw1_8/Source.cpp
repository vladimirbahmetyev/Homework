#include <cstdio>

int main()
{
	int array[10] = {}, numberOfZeroElements = 0;
	printf("Input array of 10 integer ");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d",&array[i]);
		if (array[i] == 0)
		{
			numberOfZeroElements++;
		}
	}
	printf("%s %d", "Number of zero is", numberOfZeroElements);
	return 0;
}