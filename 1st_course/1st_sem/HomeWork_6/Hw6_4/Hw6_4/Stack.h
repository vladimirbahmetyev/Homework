#pragma once

struct Record;

struct Stack;

//Add record to stack
void push(Record newRecord, Stack *&head);

//Get value from stack
Record pop(Stack *&head);

//Print stack
void printStack(Stack *head);

//Delete stack
void deleteStack(Stack *&head);

//Count size of stack
int sizeOfStack(Stack *&head);

//Invert Stack
Stack *invertStack(Stack *&head);