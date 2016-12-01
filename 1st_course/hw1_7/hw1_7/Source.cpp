#include <cstdio>
#include <cstdlib>

int main()
{
	int maxNumber = 0;
	bool chekNumber = true;
	printf("Input n ");
	scanf_s("%d", &maxNumber);
	for (int i = 2; i < maxNumber + 1; i++)
	{
		chekNumber = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				chekNumber = false;
			}
		}
		if (chekNumber)
		{
			printf("%d \n", i);
		}
	}
	system("pause");
	return 0;
}