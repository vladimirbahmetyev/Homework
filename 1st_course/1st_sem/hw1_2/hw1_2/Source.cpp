#include <cstdio>
#include <cstdlib>

int main()
{
	bool signOfDividend = false;
	bool signOfDivider = false;
	int dividend = 0;
	int divider = 0;
	int nod = 0;
	printf("Input a ");
	scanf_s("%d", &dividend);
	printf("Input b ");
	scanf_s("%d", &divider);
	if (dividend >= 0)
	{
		signOfDividend = true;
	}
	if (divider >= 0)
	{
		signOfDivider = true;
	}
	dividend = abs(dividend);
	divider = abs(divider);
	while (dividend >= divider)
	{
		dividend = dividend - divider;
		nod++;
	}
	if (signOfDividend == signOfDivider)
	{
		printf("%s %d\n", "The result is", nod);
	}
	else
	{
		printf("%s %d\n", "The result is", -1 * nod - 1);
	}
	return 0;
}