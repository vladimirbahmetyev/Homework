#include "stack.h";
#include <cstdio>

struct List
{
	int value;
	List *next;
};

void push(int value, List *&head)
{
	head = new List{ value, head };
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
	List printHead = *head;
	while (printHead.next != nullptr)
	{
		printf("%d %s", printHead.value, "\n");
		printHead = *printHead.next;
	}
}

void deleteList(List *&head)
{
	if (!head)
	{
		return;
	}
	while (head->next)
	{
		pop(head);
	}
	delete head;
	head = nullptr;
}