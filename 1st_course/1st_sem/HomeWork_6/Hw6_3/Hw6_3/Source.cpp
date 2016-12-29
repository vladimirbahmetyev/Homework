#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "stack.h"
#include <string>

const int sizeOfExample = 50;

using namespace std;

string *sortStation(const string &example)
{
	int position = 0;
	Stack *stack = nullptr;
	string *outExample = new string[sizeOfExample];
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

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string example = {};
	cout << "Введите пример: ";
	getline(cin, example);
	string *outExample = sortStation(example);
	cout << "Пример после сортировочной станции: ";
	for (int i = 0; i < sizeOfExample; i++)
	{
		cout << outExample[i];
	}
	cout << endl;
}