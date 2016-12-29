#pragma once

#include <string>
#include "MergeSort.h"

using namespace std;

struct Record;

struct Stack;

//Add record to stack
void push(Record newRecord, Stack *&head);

//Get value from stack
Record pop(Stack *&head);

//Print stack
void printList(Stack *head);

//Delete stack
void deleteList(Stack *&head);

//Count size of stack
int sizeOfStack(Stack *&head);

//Invert Stack
Stack *invertStack(Stack *&head);