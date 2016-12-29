#include "stack.h";
#include <cstdio>
#include <iostream>

using namespace std;

struct Stack
{
	int value;
	Stack *next;
};

void push(int value, Stack *&head)
{
	head = new Stack{ value, head };
}

int pop(Stack *&head)
{
	if (!head)
	{
		return 0;
	}
	int number = head->value;
	Stack *oldHead = head;
	head = head->next;
	delete  oldHead;
	return number;
}

void printStack(Stack *head)
{
	Stack *printHead = head;
	while (printHead)
	{
		cout << printHead->value << endl;
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

int headOfStack(Stack *&head)
{
	if (!head)
	{
		return -1;
	}
	int timeHead = pop(head);
	push(timeHead, head);
	return timeHead;
}