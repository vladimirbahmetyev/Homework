#include "stack.h";
#include <iostream>
#include <string>
#include "MergeSort.h"


using namespace std;

struct Record
{
	string name;
	int number;
};

struct Stack
{
	Record record;
	Stack *next;
};

void push(Record newRecord, Stack *&head)
{
	Stack *newElement = new Stack{ newRecord, head };
	head = newElement;
}

Record pop(Stack *&head)
{
	Record oldRecord = head->record;
	Stack *oldHead = head;
	head = head->next;
	delete oldHead;
	return oldRecord;
}

void printStack(Stack *head)
{	
	Stack *printHead = head;
	while (printHead != nullptr)
	{
		cout << printHead->record.name << " " << printHead->record.number << endl;
		printHead = printHead->next;
	}
}

void deleteStack(Stack *&head)
{
	while (head->next)
	{
		pop(head);
	}
	delete head;
	head = nullptr;
}

int sizeOfStack(Stack *&head)
{
	int size = 0;
	Stack *cursor = head;
	while (cursor)
	{
		cursor = cursor->next;
		size++;
	}
	return size;
}

Stack *invertStack(Stack *&head)
{
	Stack *newStack = nullptr;
	while (head)
	{
		push(pop(head), newStack);
	}
	return newStack;
}