#pragma once

struct Stack;

//Add element to stack
void push(int value, Stack *&head);

//Delete element from stack
int pop(Stack *&head);

//Delete all Stack
void deleteStack(Stack *&head);

//Print Stack
void printStack(Stack *&head);

//Invert Stack
Stack *transformStack(Stack *&head);

int valueFromHead(Stack *&head);

Stack *nextHead(Stack *head);