#include <iostream>
#include "stack.h"

using namespace std;

int const sizeOfExample = 100;

void translationStringToAnswer(List *&numbers, char example[])
{
	int number = 0;
	for (int i = 0; i < sizeOfExample; i++)
	{
		switch (example[i])
		{
		case('0'): number = number * 10;
			break;
		case('1'): number = number * 10 + 1;
			break;
		case('2'): number = number * 10 + 2;
			break;
		case('3'): number = number * 10 + 3;
			break;
		case('4'): number = number * 10 + 4;
			break;
		case('5'): number = number * 10 + 5;
			break;
		case('6'): number = number * 10 + 6;
			break;
		case('7'): number = number * 10 + 7;
			break;
		case('8'): number = number * 10 + 8;
			break;
		case('9'): number = number * 10 + 9;
			break;
		case(' '):
			if ((example[i - 1] != '*') && (example[i - 1] != '+') && (example[i - 1] != '-') && (example[i - 1] != '/'))
			{
				push(number, numbers);
				number = 0;
			}
			break;
		case('*'):
		{
			int numberOne = pop(numbers);
			int numberTwo = pop(numbers);
			push(numberOne * numberTwo, numbers);
		};
			break;
		case('+'):
		{
			int numberOne = pop(numbers);
			int numberTwo = pop(numbers);
			push(numberOne + numberTwo, numbers);
		};
			break;
		case('-'):
		{
			int numberOne = pop(numbers);
			int numberTwo = pop(numbers);
			push(numberTwo - numberOne, numbers);
		};
			break;
		case('/'):
		{
			int numberOne = pop(numbers);
			int numberTwo = pop(numbers);
			push(numberTwo / numberOne, numbers);
		};
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	char example[sizeOfExample] = {};
	printf("¬ведите выражение: ");
	gets_s(example);
	List *numbers = nullptr;
	translationStringToAnswer(numbers, example);
	printf("%s %d", "ќтвет: ", pop(numbers));
	printf("\n");
}