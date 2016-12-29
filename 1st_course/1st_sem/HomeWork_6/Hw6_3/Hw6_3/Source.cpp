#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "stack.h"
#include <string>

int const sizeOfExample = 256;

using namespace std;

string *sortStation(const string &example)
{
	int position = 0;
	Stack *stack = nullptr;
	string outExample[sizeOfExample] = {};
	for (int i = 0; i < example.length(); i++)
	{
		if ((example[i] >= '0') && (example[i] <= '9'))
		{
			outExample[position] = example[i];
			position++;
			outExample[position] = ' ';
			position++;
		}
		if (example[i] == '(')
		{
			push('(', stack);
		}
		if (example[i] == ')')
		{
			while (headOfStack(stack) != '(')
			{
				outExample[position] = headOfStack(stack);
				position++;
				outExample[position] = ' ';
				position++;
				pop(stack);
			}
			pop(stack);
		}
		if ((example[i] == '+') || (example[i] == '-') || (example[i] == '/') || (example[i] == '*'))
		{
			if (((example[i] == '+') || (example[i] == '-') || ((example[i] == '*') && (headOfStack(stack) != '-') && (headOfStack(stack) != '+')) || ((example[i] == '/') && (headOfStack(stack) != (headOfStack(stack) != '-')) && (headOfStack(stack) != '+'))) && stack && headOfStack(stack) != '(')
			{
				outExample[position] = pop(stack);
				position++;
				outExample[position] = ' ';
				position++;
			}
			push(example[i], stack);
		}
	}
	while (stack)
	{
		outExample[position] = pop(stack);
		position++;
		outExample[position] = ' ';
		position++;
	}
	delete stack;
	return outExample;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string example = {};
	cout << "Введите пример: ";
	cin >> example[sizeOfExample];
	string *outExample = sortStation(example);
	cout << "Пример после сортировочной станции: ";
	for (int i = 0; i < outExample->length(); i++)
	{
		cout << outExample[i];
	}
	cout << endl;
	system("pause");
	return 0;
}