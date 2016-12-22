#include "stack.h";
#include <iostream>
#include <string>

using namespace std;

void push(Record newRecord, List *&head)
{
	List *newElement = new List{ newRecord, head };
	head = newElement;
}

Record pop(List *&head)
{
	Record oldRecord = head->record;
	List *oldHead = head;
	head = head->next;
	delete oldHead;
	return oldRecord;
}

void printList(List *&head)
{
	List *printHead = head;
	while (printHead!= nullptr)
	{
		cout << printHead->record.name << " " << printHead->record.number << endl;
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