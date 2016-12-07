#include "stack.h"
#include <iostream>

using namespace std;

int const sizeOfExample = 100;

void translationStringToAnswer(List *&numbers, char example[])
{
	int number = 0;
	for (int i = 0; i < sizeOfExample; i++)
	{
		switch ((int)example[i])
		{
		case(48): number = number * 10;
			break;
		case(49): number = number * 10 + 1;
			break;
		case(50): number = number * 10 + 2;
			break;
		case(51): number = number * 10 + 3;
			break;
		case(52): number = number * 10 + 4;
			break;
		case(53): number = number * 10 + 5;
			break;
		case(54): number = number * 10 + 6;
			break;
		case(55): number = number * 10 + 7;
			break;
		case(56): number = number * 10 + 8;
			break;
		case(57): number = number * 10 + 9;
			break;
		case(32):
			if (((int)example[i - 1] != 42) && ((int)example[i - 1] != 43) && ((int)example[i - 1] != 45) && ((int)example[i - 1] != 47))
			{
				push(number, numbers);
				number = 0;
			}
			break;
		case(42):
		{
			int numberOne = numbers->value;
			pop(numbers);
			int numberTwo = numbers->value;
			pop(numbers);
			push(numberOne * numberTwo, numbers);
		};
			break;
		case(43):
		{
			int numberOne = numbers->value;
			pop(numbers);
			int numberTwo = numbers->value;
			pop(numbers);
			push(numberOne + numberTwo, numbers);
		};
			break;
		case(45):
		{
			int numberOne = numbers->value;
			pop(numbers);
			int numberTwo = numbers->value;
			pop(numbers);
			push(numberTwo - numberOne, numbers);
		};
			break;
		case(47):
		{
			int numberOne = numbers->value;
			pop(numbers);
			int numberTwo = numbers->value;
			pop(numbers);
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
	List *numbers = (0, nullptr);
	translationStringToAnswer(numbers, example);
	printf("%s %d", "ќтвет: ", numbers->value);
	printf("\n");
}