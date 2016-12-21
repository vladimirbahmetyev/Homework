#include "stack.h";
#include <cstdio>
#include <iostream>

using namespace std;

void push(int value, List *&head)
{
	List * newListElement = new List{ value, head };
	head = newListElement;
	newListElement = nullptr;
}

int pop(List *&head)
{
	int number = head->value;
	List *oldHead = head;
	head = head->next;
	delete  oldHead;
	return number;
}

void deleteList(List *&head)
{
	while (head)
	{
		pop(head);
	}
	delete head;
	head = nullptr;
}

void printList(List *&head)
{
	List *cursor = head;
	while (cursor)
	{
		cout << cursor->value + 1 << " ";
		cursor = cursor->next;
	}
	cout << endl << endl;
}

List *transformList(List *&head)
{
	List *newList = nullptr;
	while (head)
	{
		push(pop(head), newList);
	}
	head = newList;
	return newList;
}