#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Stack *telephoneList = nullptr;
	loadFromFile(telephoneList);
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
		case(0):
		{
			break;
		}
		case 1:
		{
			telephoneList = mergeSort(telephoneList, command);
			telephoneList = invertStack(telephoneList);
			printList(telephoneList);
			break;
		}
		case 2:
		{
			telephoneList = mergeSort(telephoneList, command);
			telephoneList = invertStack(telephoneList);
			printList(telephoneList);
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
	 	}
	}
	deleteList(telephoneList);
}