#pragma once

#include <string>

struct Stack;

//Add element to Stack
void push(int addToStack,const std::string &word, Stack *&head);

//Delete element from Stack
Stack pop(Stack *&head);

//Print all Stack
void printStack(Stack *head);

//Delete all Stack
void deleteStack(Stack *&head);

//Count length of Stack
int countStack(Stack *head);

//Check is this word in Stack and if it is true, increase count of word
bool addWordOrIncrieseCountOfWord(Stack *&head, const std::string &word);

//Delete array of stacks
void deleteArrayOfStacks(Stack *hashTable[], int sizeOfHashtable);