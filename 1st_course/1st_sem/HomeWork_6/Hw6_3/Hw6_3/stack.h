#pragma once

struct Stack;

//Add element to stack
void push(int addToStack, Stack *&head);

//Delete element from stack
int pop(Stack *&head);

//Print all stack
void printStack(Stack *head);

//Delete all Stack
void deleteStack(Stack *&head);

//Get last value from stack
int headOfStack(Stack *&head);