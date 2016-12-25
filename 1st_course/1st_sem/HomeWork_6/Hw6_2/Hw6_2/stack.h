#pragma once

struct List;

//Add element to stack
void push(int addToStack, List *&head);

//Delete element from stack
int pop(List *&head);

//Print all stack
void printList(List *head);

//Delete all List
void deleteList(List *&head);