#include "stack.h";

void push(int value, string word, List *&head)
{
	List * newListElement = new List{ value, word, head };
	head = newListElement;
	newListElement = nullptr;
}

List pop(List *&head)
{
	List returnList = *head;
	List *oldHead = head;
	head = head->next;
	delete  oldHead;
	return returnList;
}

void printList(List *&head)
{
	List *printHead = head;
	while (printHead->next)
	{
		cout << head->word << " " << head->value << endl;
		printHead = printHead->next;
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