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

List *invertList(List *&head)
{
	List *newList = nullptr;
	while (head)
	{
		push(pop(head), newList);
	}
	return newList;
}

List *mergeSortOnName(List *&list)
{
	int deep = deepOfList(list);
	List *firstList = list;
	List *secondList = nullptr;
	if (deep > 1)
	{
		
		for (int i = 0; i < deep / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSortOnName(firstList);
		secondList = mergeSortOnName(secondList);
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

List *mergeSortOnNumber(List *&list)
{
	int deep = deepOfList(list);
	List *firstList = list;
	List *secondList = nullptr;
	if (deep > 1)
	{

		for (int i = 0; i < deep / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSortOnNumber(firstList);
		secondList = mergeSortOnNumber(secondList);
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
	while(firstList)
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
	testList = mergeSortOnName(testList);
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
	testList = mergeSortOnNumber(testList);
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
		case(1):
		{
			telephoneList = mergeSortOnName(telephoneList);
			telephoneList = invertList(telephoneList);
			printList(telephoneList);
			break;
		}
		case(2):
		{
			telephoneList = mergeSortOnNumber(telephoneList);
			telephoneList = invertList(telephoneList);
			printList(telephoneList);
			break;
		}
		default: cout << "Неккоректный ввод" << endl;
	 	}
	}
	deleteList(telephoneList);
	system("pasue");
}