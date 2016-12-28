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

int sizeOfList(List *&head)
{
	int size = 0;
	List *cursor = head;
	while (cursor)
	{
		cursor = cursor->next;
		size++;
	}
	return size;
}

List *invertList(List *&head)
{
	List *newList = nullptr;
	while (head)
	{
		push(pop(head), newList);
	}
	return newList;
}

List *mergeSort(List *&list, int typeOfSort)
{
	int size = sizeOfList(list);
	List *firstList = list;
	List *secondList = nullptr;
	if (size > 1)
	{
		
		for (int i = 0; i < size / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSort(firstList, typeOfSort);
		secondList = mergeSort(secondList, typeOfSort);
	}
	List *finalList = nullptr;
	while (firstList && secondList)
	{
		switch (typeOfSort)
		{
		case 1:
		{
			if (firstList->record.name > secondList->record.name)
			{
				push(pop(firstList), finalList);
			}
			else
			{
				push(pop(secondList), finalList);
			}
			break;
		}
		case 2:
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
		break;
		default: return nullptr;
		}
	}
	while (firstList)
	{
		push(pop(firstList), finalList);
	}
	while (secondList)
	{
		push(pop(secondList), finalList);
	}
	return invertList(finalList);
}

void test1()
{
	List *testList = {};
	loadFromFile(testList);
	testList = mergeSort(testList, 1);
	testList = invertList(testList);
	List *cursor = testList;
	bool flag = true;
	while (cursor->next)
	{
		flag = flag && (cursor->record.name < cursor->next->record.name);
		cursor = cursor->next;
	}
	if (flag)
	{
		cout << "Тест пройден" << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl;
	}
	deleteList(testList);
}

void test2()
{
	List *testList = {};
	loadFromFile(testList);
	testList = mergeSort(testList, 2);
	testList = invertList(testList);
	List *cursor = testList;
	bool flag = true;
	while (cursor->next)
	{
		flag = flag && (cursor->record.number < cursor->next->record.number);
		cursor = cursor->next;
	}
	if (flag)
	{
		cout << "Тест пройден" << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl;
	}
	deleteList(testList);
}

void main()
{
	setlocale(LC_ALL, "Russian");
	List *telephoneList = nullptr;
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
			telephoneList = invertList(telephoneList);
			printList(telephoneList);
			break;
		}
		case 2:
		{
			telephoneList = mergeSort(telephoneList, command);
			telephoneList = invertList(telephoneList);
			printList(telephoneList);
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
	 	}
	}
	deleteList(telephoneList);
}