#include <iostream>
#include "stack.h"

using namespace std;

int const sizeOfString = 256;

void main()
{
	setlocale(LC_ALL, "Russian");
	char example[sizeOfString] = {};
	printf("Введите строку: ");
	gets_s(example);
	List * brackets = (0, nullptr);
	bool flag = true;
	for (int i = 0; i < sizeOfString; i++)
	{
		switch (int(example[i]))
		{
			case(40): push(1, brackets);
				break;
			case(91): push(2, brackets);
				break;
			case(123): push(3, brackets);
				break;
			case (41):
			{
				
				if (brackets)
				{
					flag = flag && (brackets->value == 1);
					pop(brackets);
				}
				else
				{
					flag = false;
				}
			}
				break;
			case (93):
			{				
				if (brackets)
				{
					flag = flag && (brackets->value == 2);
					pop(brackets);
				}
				else
				{
					flag = false;
				}
			}
				break;
			case (125):
			{
				
				if (brackets)
				{
					flag = flag && (brackets->value == 3);
					pop(brackets);
				}
				else
				{
					flag = false;
				}
			}
				break;
		}
	}
	if (flag)
	{
		printf("Баланс соблюден\n");
	}
	else
	{
		printf("Баланс не соблюден\n");
	}
}