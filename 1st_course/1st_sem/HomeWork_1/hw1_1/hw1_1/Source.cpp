#include <cstdio>

int main()
{
	int singlX = 0;
	int doubleX = 0;
	printf("Input x ");
	scanf_s("%d", &singlX);
	doubleX = singlX * singlX;
	printf("%s %d\n", "Answer is", ((doubleX + singlX) * (doubleX + 1) + 1));
	return 0;
}