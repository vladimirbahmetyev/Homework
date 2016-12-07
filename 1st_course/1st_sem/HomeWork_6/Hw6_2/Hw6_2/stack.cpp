#include "stack.h";
#include <cstdio>

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
	List printHead = *head;
	while (printHead.next != nullptr)
	{
		printf("%d %s", printHead.value, "\n");
		printHead = *printHead.next;
	}
}

void deleteList(List *&head)
{
	while (head->next)
	{
		pop(head);
	}
	delete head;
	head = nullptr;
}