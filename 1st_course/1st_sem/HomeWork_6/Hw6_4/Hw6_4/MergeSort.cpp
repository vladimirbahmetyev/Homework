#include "Stack.h"
#include <fstream>
#include <iostream>
#include <string>
#include "MergeSort.h"

using namespace std;

struct Record
{
	string name;
	int number;
};

Stack *mergeSort(Stack *&stack, int typeOfSort)
{
	int size = sizeOfStack(stack);
	Stack *firstList = stack;
	Stack *secondList = nullptr;
	if (size > 1)
	{

		for (int i = 0; i < size / 2; i++)
		{
			push(pop(firstList), secondList);
		}
		firstList = mergeSort(firstList, typeOfSort);
		secondList = mergeSort(secondList, typeOfSort);
	}
	Stack *finalList = nullptr;
	while (firstList && secondList)
	{
		switch (typeOfSort)
		{
		case 1:
		{
			if (getRecord(firstList).name > getRecord(secondList).name)
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
			if (getRecord(firstList).number > getRecord(secondList).number)
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
	return invertStack(finalList);
}

void loadFromFile(Stack *&stack)
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
			push(newRecord, stack);
		}
		file.close();
	}
}

void test1()
{
	Stack *testList = {};
	loadFromFile(testList);
	testList = mergeSort(testList, 1);
	testList = invertStack(testList);
	bool flag = true;
	while (nextHead(testList))
	{
		Stack *timeHead = nextHead(testList);
		flag = flag && (getRecord(testList).name < getRecord(timeHead).name);
		pop(testList);
	}
	if (flag)
	{
		cout << "Тест пройден" << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl;
	}
	deleteStack(testList);
}

void test2()
{
	Stack *testList = {};
	loadFromFile(testList);
	testList = mergeSort(testList, 2);
	testList = invertStack(testList);
	bool flag = true;
	while (nextHead(testList))
	{
		Stack *timeHead = nextHead(testList);
		flag = flag && (getRecord(testList).number < getRecord(timeHead).number);
		pop(testList);
	}
	if (flag)
	{
		cout << "Тест пройден" << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl;
	}
	deleteStack(testList);
}