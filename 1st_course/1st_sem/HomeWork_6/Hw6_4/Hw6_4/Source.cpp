#include "Stack.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void loadFromFile(List *&list)
{
	ifstream file("list.txt");
	int number = 0;
	if (!file.is_open())
	{
		ofstream file("list.txt");
		file.close();
	}
	else
	{
		while (!file.eof())
		{
			Record newRecord = {};
			file >> newRecord.name;
			file >> newRecord.number;
			push(newRecord, list);
		}
		file.close();
	}
}

int deepOfList(List *&head)
{
	int deep = 0;
	List *cursor = head;
	while (cursor)
	{
		cursor = cursor->next;
		deep++;
	}
	return deep;
}

List *mergeSortOnName(List *&list)
{
	int deep = deepOfList(list);
	List *firstList = list;
	List *secondList = nullptr;
	if (deep > 2)
	{
		
		for (int i = 0; i < deep / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSortOnName(firstList);
		firstList = mergeSortOnName(secondList);
	}
	List *finalList = nullptr;
	while (firstList && secondList)
	{
		if (firstList->record.name > secondList->record.name)
		{
			push(pop(firstList), finalList);
		}
		else
		{
			push(pop(secondList), finalList);
		}
	}
	if (firstList)
	{
		push(pop(firstList), finalList);
	}
	if (secondList)
	{
		push(pop(secondList), finalList);
	}
	return finalList;
}

List *mergeSortOnNumber(List *&list)
{
	int deep = deepOfList(list);
	List *firstList = list;
	List *secondList = nullptr;
	if (deep > 2)
	{

		for (int i = 0; i < deep / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSortOnName(firstList);
		firstList = mergeSortOnName(secondList);
	}
	List *finalList = nullptr;
	while (firstList && secondList)
	{
		if (firstList->record.number > secondList->record.number)
		{
			push(pop(firstList), finalList);
		}
		else
		{
			push(pop(secondList), finalList);
		}
	}
	if (firstList)
	{
		push(pop(firstList), finalList);
	}
	if (secondList)
	{
		push(pop(secondList), finalList);
	}
	return finalList;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	List *telephoneList = nullptr;
	int numberOfNumbers = 0;
	loadFromFile(telephoneList);
	int command = -1;
	while (command != 0)
	{
		cout << "Введите 0 чтобы выйти" << endl;
		cout << "Введите 1 чтобы распечатать отсортированный по именам список" << endl;
		cout << "Введите 2 чтобы распечатать отсортированный по номерам список" << endl;
		cin >> command;
		switch (command)
		{
		case(1):
		{
			telephoneList = mergeSortOnName(telephoneList);
			printList(telephoneList);
			break;
		}
		case(2):
		{
			telephoneList = mergeSortOnNumber(telephoneList);
			printList(telephoneList);
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
	 	}
	}
	deleteList(telephoneList);
	system("pasue");
}