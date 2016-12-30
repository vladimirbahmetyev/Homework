#include "Stack.h"
#include <iostream>
#include "MergeSort.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Stack *telephoneStack = nullptr;
	loadFromFile(telephoneStack);
	int command = -1;
	test1();
	test2();
	while (command != 0)
	{
		cout << "Введите 0 чтобы выйти" << endl;
		cout << "Введите 1 чтобы распечатать отсортированный по именам список" << endl;
		cout << "Введите 2 чтобы распечатать отсортированный по номерам список" << endl;
		cin >> command;
		switch (command)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			telephoneStack = mergeSort(telephoneStack, command);
			telephoneStack = invertStack(telephoneStack);
			printStack(telephoneStack);
			break;
		}
		case 2:
		{
			telephoneStack = mergeSort(telephoneStack, command);
			telephoneStack = invertStack(telephoneStack);
			printStack(telephoneStack);
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
	 	}
	}
	deleteStack(telephoneStack);
}