#pragma once

struct List
{
	int value;
	List *next;
};

//Add element to stack
void push(int value, List *&head);

//Delete element from stack
int pop(List *&head);

//Delete all List
void deleteList(List *&head);

void printList(List *&head);