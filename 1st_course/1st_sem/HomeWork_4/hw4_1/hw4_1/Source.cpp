#include <cstdio>
#include <iostream> 

int const sizeOfBit = 31;

using namespace std;

void translationToBit(int number, bool numberInBit[])
{
	int bit = 0b1000000000000000000000000000000;
	for (int i = 0; i < sizeOfBit; i++)
	{
		numberInBit[i] = (number & bit);
		bit = bit >> 1;
	}
}

void printNumberInBit(bool numberInBit[])
{
	for (int i = 0; i < sizeOfBit; i++)
	{
		if (numberInBit[i])
		{
			printf("%d", 1);
		}
		else
		{
			printf("%d", 0);
		}
	}
	printf("\n");
}

void sumNumbersInBit(bool numberOneInBit[], bool numberTwoInBit[], bool sumInBit[])
{
	for (int i = sizeOfBit - 1; i >= 0; i--)
	{
		if (sumInBit[i] && numberOneInBit[i])
		{
			if (i != 0)
			{
				sumInBit[i - 1] = true;
			}
			sumInBit[i] = false;
		}
		else
		{
			sumInBit[i] = (sumInBit[i] || numberOneInBit[i]);
		}
		if (sumInBit[i] && numberTwoInBit[i])
		{
			sumInBit[i] = false;
			if (i != 0)
			{
				sumInBit[i - 1] = true;
			}
		}
		else
		{
			sumInBit[i] = (sumInBit[i] || numberTwoInBit[i]);
		}
		if (i == 0)
		{
			return;
		}
	}
}

int translationToDec(bool sumInBit[])
{
	int position = 1;
	int sumInDec = 0;
	for (int i = sizeOfBit - 1; i >= 0; i--)
	{
		if (sumInBit[i])
		{
			sumInDec = sumInDec + position;
		}
		position = position * 2;
	}
	if (sumInBit[0])
	{
		return sumInDec + 2147483648  ;
	}
	else
	{
		return sumInDec;
	}
}

void test1()
{
	int testNumber = 6;
	bool testNumberInBut[sizeOfBit] = {};
	bool checkNumber[sizeOfBit] = { false, false, false, false, false,false, false, false, false, false,false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false };
	translationToBit(testNumber, testNumberInBut);
	for (int i = 0; i < sizeOfBit; i++)
	{
		if (!(checkNumber[i] == testNumberInBut[i]))
		{
			printf("���� 1 �� �������\n");
			return;
		}
	}
	printf("���� 1 �������\n");
}

void test2()
{
	bool checkNumber1[sizeOfBit] = { false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false };
	bool checkNumber2[sizeOfBit] = { false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false };
	bool sumInBit[sizeOfBit] = {};
	bool chekSumInBit[sizeOfBit] = { false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false };
	sumNumbersInBit(checkNumber1, checkNumber2, sumInBit);
	for (int i = 0; i < sizeOfBit; i++)
	{
		if (!(sumInBit[i] == chekSumInBit[i]))
		{
			printf("���� 2 �� �������\n");
			return;
		}
	}
	printf("���� 2 �������\n");
}

void test3()
{
	bool chekNumberInBit[sizeOfBit] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false };
	if (12 == translationToDec(chekNumberInBit))
	{
		printf("���� 3 �������\n");
	}
	else
	{
		printf("���� 3 �� �������\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int numberOne = 0;
	int numberTwo = 0;
	bool numberOneInBit[sizeOfBit] = {};
	bool numberTwoInBit[sizeOfBit] = {};
	printf("������� ����� a ");
	scanf_s("%d", &numberOne);
	translationToBit(numberOne, numberOneInBit);
	printf("%s \n", "����� � � ������� ������� ���������:");
	printNumberInBit(numberOneInBit);
	printf("������� ����� � ");
	scanf_s("%d", &numberTwo);
	translationToBit(numberTwo, numberTwoInBit);
	printf("%s\n", "����� � � ������� ������� ���������:");
	printNumberInBit(numberTwoInBit);
	bool sumInBit[sizeOfBit] = {};
	sumNumbersInBit(numberOneInBit, numberTwoInBit, sumInBit);
	printf("%s ", "����� ����� � � � � ������� ������� ���������:");
	printNumberInBit(sumInBit);
	printf("%s%d\n", "����� � ���������� ����: ", translationToDec(sumInBit));
	test1();
	test2();
	test3();
	return 0;
}