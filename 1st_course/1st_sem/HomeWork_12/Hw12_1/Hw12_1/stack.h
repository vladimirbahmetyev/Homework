#pragma once

struct List
{
	int value;
	string string;
	List *next;
};

//Add element to stack
void push(int addToStack, string inputString, List *&head);

//Delete element from stack
int pop(List *&head);

//Print all stack
void printList(List *head);

//Delete all List
void deleteList(List *&head);