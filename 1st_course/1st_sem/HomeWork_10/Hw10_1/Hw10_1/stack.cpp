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

void printList(List *head)
{
	List *printHead = head;
	while (printHead)
	{
		cout << printHead->value + 1 << " ";
		printHead = printHead->next;
	}
	cout << endl << endl;
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