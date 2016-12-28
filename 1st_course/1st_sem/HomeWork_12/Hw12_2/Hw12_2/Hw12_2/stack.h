#pragma once

struct List;

//Add element to stack
void push(int value, List *&head);

//Delete element from stack
int pop(List *&head);

//Delete all List
void deleteList(List *&head);

//Print List
void printList(List *&head);

//Invert List
List *transformList(List *&head);

int valueFromHead(List *head);

List *nextHead(List *head);