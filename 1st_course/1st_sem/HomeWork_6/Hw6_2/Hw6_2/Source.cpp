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
	List * brackets = nullptr;
	bool flag = true;
	for (int i = 0; i < sizeOfString; i++)
	{
		switch ((example[i]))
		{
			case('('): push(1, brackets);
				break;
			case('['): push(2, brackets);
				break;
			case('{'): push(3, brackets);
				break;
			case (')'):
			{
				
				if (brackets)
				{
					flag = flag && (pop(brackets) == 1);					
				}
				else
				{
					flag = false;
				}
			}
				break;
			case (']'):
			{				
				if (brackets)
				{
					flag = flag && (pop(brackets) == 2);
				}
				else
				{
					flag = false;
				}
			}
				break;
			case ('}'):
			{
				
				if (brackets)
				{
					flag = flag && (pop(brackets) == 3);
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