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
	Stack * newStackElement = new Stack{ value, head };
	head = newStackElement;
}

int pop(Stack *&head)
{
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
		cout << printHead->value + 1 << " ";
		printHead = printHead->next;
	}
	cout << endl << endl;
}

void deleteStack(Stack *&head)
{
	while (head)
	{
		pop(head);
	}
	delete head;
	head = nullptr;
}

int getValue(Stack *&head)
{
	int timeValue = pop(head);
	push(timeValue, head);
	return timeValue;
}

Stack *getNextHead(Stack *head)
{
	return head->next;
}