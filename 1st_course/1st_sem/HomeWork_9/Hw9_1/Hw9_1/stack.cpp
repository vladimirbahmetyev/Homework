#include "stack.h";

struct List
{
int value;
string word;
List *next;
};

void push(int value, const string &word, List *&head)
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
		cout << printHead->word << " " << printHead->value << endl;
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

int countList(List *&head)
{
	if (!head)
	{
		return 0;
	}
	if (!head->next)
	{
		return 1;
	}
	return (1 + countList(head->next));
}

bool addWordOrIncrieseCountOfWord(List *&head,const string &word)
{
	List *cursor = head;
	while (cursor)
	{
		if (word == cursor->word)
		{
			cursor->value++;
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}