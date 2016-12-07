#include <cstdio>

int linePow(int number, int power)
{
	int multiplication = 1;
	for (int i = 0; i < power; i++)
	{
		multiplication = multiplication * number;
	}
	return multiplication;
}

int logPow(int number, int power)
{
	if (power == 1)
	{
		return number;
	}
	if (power % 2 == 1)
	{
		int temp = logPow(number, (power - 1) / 2);
		return number * temp * temp;
	}
	else
	{
		int temp = logPow(number, power / 2);
		return temp * temp;
	}
}

int main()
{
	int number = 0;
	int power = 0;
	printf("Input number and power ");
	scanf_s("%d %d", &number, &power);
	printf("%s %d %s\n", "The result is", linePow(number, power), "(line algorythm)");
	printf("%s %d %s\n", "The result is", logPow(number, power), "(Log algorythm)");
	return 0;
}