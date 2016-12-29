#include "stack.h";
#include <cstdio>
#include <iostream>

using namespace std;

struct Stack
{
	int value;
	Stack *next;
};

Stack *nextHead(Stack *head)
{
	return head->next;
}

int valueFromHead(Stack *&head)
{
	int timeValue = pop(head);
	push(timeValue, head);
	return timeValue;
}

void push(int value, Stack *&head)
{
	Stack * newStackElement = new Stack{ value, head };
	head = newStackElement;
	newStackElement = nullptr;
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

void deleteStack(Stack *&head)
{
	if (!head)
	{
		return;
	}
	while (head)
	{
		pop(head);
	}
	head = nullptr;
}

void printStack(Stack *&head)
{
	Stack *cursor = head;
	while (cursor)
	{
		cout << cursor->value + 1 << " ";
		cursor = cursor->next;
	}
	cout << endl << endl;
}

Stack *transformStack(Stack *&head)
{
	Stack *newStack = nullptr;
	while (head)
	{
		push(pop(head), newStack);
	}
	head = newStack;
	return newStack;
}