#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "stack.h"

int const sizeOfExample = 256;

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	char example[sizeOfExample] = {};
	printf("Введите пример: ");
	gets_s(example);
	char outExample[sizeOfExample] = {};
	int position = 0;
	List *stack = nullptr;
	for (int i = 0; i < strlen(example); i++)
	{
		if ((example[i] >= (int)'0') && (example[i] <= (int)'9'))
		{
			outExample[position] = example[i];
			position++;
			outExample[position] = ' ';
			position++;
		}
		if (example[i] == '(')
		{
			push((int)'(', stack);
		}
		if (example[i] == ')')
		{
			while (headOfStack(stack) != (int)'(')
			{
				outExample[position] = ((char)headOfStack(stack));
				position++;
				outExample[position] = ' ';
				position++;
				pop(stack);
			}
			pop(stack);
		}
		if ((example[i] == '+') || (example[i] == '-') || (example[i] == '/') || (example[i] == '*'))
		{
			if (((example[i] == '+') || (example[i] == '-') || ((example[i] == '*') && ((char)headOfStack(stack) != '-') && ((char)headOfStack(stack) != '+')) || ((example[i] == '/') && ((char)headOfStack(stack) != ((char)headOfStack(stack) != '-')) && ((char)headOfStack(stack) != '+'))) && ((char)headOfStack(stack) != '(') && (stack))
			{
				outExample[position] = (char)headOfStack(stack);
				pop(stack);
				position++;
				outExample[position] = ' ';
				position++;
			}
			push((int)example[i], stack);
		}
	}
	while (stack)
	{
		outExample[position] = pop(stack);
		position++;
		outExample[position] = ' ';
		position++;
	}
	cout << "Пример после сортировочной станции: ";
	for (int i = 0; i < strlen(outExample); i++)
	{
		cout << outExample[i];
	}
	cout << endl;
	delete stack;
	stack = nullptr;
	system("pause");
	return 0;
}