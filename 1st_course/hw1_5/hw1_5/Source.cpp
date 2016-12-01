#include <cstdio>
#include <cstring>

bool isBalanceOfBracketTrue(char inputString[])
{
	int roundBrackets = 0;
	for (int i = 0; i < strlen(inputString) ; i++)
	{
		switch (inputString[i])
		{
		case '(':
		{
			roundBrackets++;
		}
		break;
		case ')':
		{
			roundBrackets--;
		}
		break;
		}
		if (roundBrackets < 0)
		{
			return false;
		}
	}
	if (roundBrackets == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	const int length = 256;
	char inputString[length] = {};
	printf("Input string for cheking balance of brackets: ");
	gets_s(inputString);
	if (isBalanceOfBracketTrue(inputString))
	{
		printf("Balance brackets is True\n");
	}
	else
	{
		printf("Balance brackets is False\n");
	}
	return 0;
}