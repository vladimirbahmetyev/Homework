#include <cstdio>

int main()
{
	int arrayOfLuckyTickets[28] = {};
	int numberOfLuckyTickets = 0;
	for (int ch1 = 0; ch1 < 10; ch1++)
	{
		for (int ch2 = 0; ch2 < 10; ch2++)
		{
			for (int ch3 = 0; ch3 < 10; ch3++)
			{
				arrayOfLuckyTickets[ch1 + ch2 + ch3]++;
			}
		}
	}
	for (int i = 0; i < 28; i++)
	{
		numberOfLuckyTickets = numberOfLuckyTickets + arrayOfLuckyTickets[i] * arrayOfLuckyTickets[i];
	}
	printf("%s %d\n", "The answer is", numberOfLuckyTickets);
	return 0;
}