#include "stack.h"
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct Stack
{
	int value;
	string word;
	Stack *next;
};

void push(int value, const string &word, Stack *&head)
{
	head = new Stack{ value, word, head };
}

Stack pop(Stack *&head)
{
	Stack returnStack = *head;
	Stack *oldHead = head;
	head = head->next;
	delete  oldHead;
	return returnStack;
}

void printStack(Stack *head)
{
	Stack *printHead = head;
	while (printHead->next)
	{
		cout << printHead->word << " " << printHead->value << endl;
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

int countStack(Stack *head)
{
	if (!head)
	{
		return 0;
	}
	if (!head->next)
	{
		return 1;
	}
	return (1 + countStack(head->next));
}

bool addWordOrIncrieseCountOfWord(Stack *&head, const string &word)
{
	Stack *cursor = head;
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

void deleteArrayOfStacks(Stack *hashTable[], int sizeOfHashtable)
{
	for (int i = 0; i < sizeOfHashtable; i++)
	{
		if (hashTable[i])
		{
			deleteStack(hashTable[i]);
		}
	}
	delete[] * hashTable;
	hashTable = nullptr;
}