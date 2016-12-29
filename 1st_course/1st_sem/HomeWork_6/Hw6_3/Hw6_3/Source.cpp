#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

void sortStation(const string &example)
{
	Stack *stack = nullptr;
	string outExample = "";
	for (int i = 0; i < example.length(); i++)
	{
		if ((example[i] >= '0') && (example[i] <= '9'))
		{
			outExample += example[i];
			outExample += " ";
		}
		if (example[i] == '(')
		{
			push('(', stack);
		}
		if (example[i] == ')')
		{
			while (headOfStack(stack) != '(')
			{
				outExample += headOfStack(stack);
				outExample += " ";
				pop(stack);
			}
			pop(stack);
		}
		if ((example[i] == '+') || (example[i] == '-') || (example[i] == '/') || (example[i] == '*'))
		{
			if (((example[i] == '+') || (example[i] == '-') || ((example[i] == '*') && (headOfStack(stack) != '-') && (headOfStack(stack) != '+')) || ((example[i] == '/') && (headOfStack(stack) != (headOfStack(stack) != '-')) && (headOfStack(stack) != '+'))) && stack && headOfStack(stack) != '(')
			{
				outExample += pop(stack);
				outExample += " ";
			}
			push(example[i], stack);
		}
	}
	while (stack)
	{
		outExample += pop(stack);
		outExample += " ";
	}
	delete stack;
	for (int i = 0; i < outExample.length(); i++)
	{
		cout << outExample[i];
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string example = {};
	cout << "Введите пример: ";
	getline(cin, example);
	cout << "Пример после сортировочной станции: ";
	sortStation(example);
}