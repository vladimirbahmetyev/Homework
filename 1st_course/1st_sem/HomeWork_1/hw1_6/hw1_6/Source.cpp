#include <cstdio>
#include <cstring>

int numberOfSubStrings(char mainString[], char subString[])
{
	bool checkString = true;
	int result = 0;
	for (int i = 0; i < strlen(mainString) - strlen(subString) + 1; i++)
	{
		checkString = true;
		for (int j = 0; j < strlen(subString); j++) 
		{
			if (mainString[i + j] != subString[j])
			{
				checkString = false;
			}
		}
		if (checkString)
		{
			result++;
		}
	}
	return result;
}

int main()
{
	const int stringLongth = 256;
	char mainString[stringLongth] = {};
	char subString[stringLongth] = {};
	printf("Input main string: ");
	gets_s(mainString);
	printf("Input sub string: ");
	gets_s(subString);
	printf("%s %d\n", "Number of substrings is", numberOfSubStrings(mainString, subString));
	return 0;
}