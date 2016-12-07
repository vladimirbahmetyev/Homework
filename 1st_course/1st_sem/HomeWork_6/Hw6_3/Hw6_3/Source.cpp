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
	printf("Введите строку: ");
	gets_s(example);
	char outExample[sizeOfExample] = {};
	int position = 0;
	List *stack = new List{};
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
			while (stack->value != (int)'(')
			{
				outExample[position] = ((char)stack->value);
				position++;
				outExample[position] = ' ';
				position++;
				pop(stack);
			}
			pop(stack);
		}
		if ((example[i] == '+') || (example[i] == '-') || (example[i] == '/') || (example[i] =='*'))
		{
			if (((example[i] == '+') || (example[i] == '-') || ((example[i] == '*') && ((char)stack->value != '-') && ((char)stack->value != '+')) || ((example[i] == '/') && ((char)stack->value != ((char)stack->value != '-')) && ((char)stack->value != '+'))) && ((char)stack->value != '(') && (stack->next))
			{
				outExample[position] = (char)stack->value;
				pop(stack);
				position++;
				outExample[position] = ' ';
				position++;
			}
			push((int)example[i], stack);
		}
	}
	while (stack->next)
	{
		outExample[position] = (char)stack->value;
		pop(stack);
		position++;
		outExample[position] = ' ';
		position++;
	}
	cout << "Пример после обработки: ";
	for (int i = 0; i < strlen(outExample); i++)
	{
		cout << outExample[i];
	}
	cout << endl;
	delete stack;
	stack == nullptr;
	return 0;
}