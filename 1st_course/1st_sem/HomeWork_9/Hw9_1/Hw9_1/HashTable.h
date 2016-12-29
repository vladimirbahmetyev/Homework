#pragma once

#include "stack.h"

//Add  word to hashTable
void addElementToHashTable(Stack *head[], int sizeOfHashTable,const string &word);

//Find the longest Stack in hashTable
int maxLengthOfStack(Stack *hashTable[], int sizeOfHashTable);

//Count average length of Stack in hashTable
double averageLengthOfStack(Stack *hashTable[], int sizeOfHashTable);

//Count fulling hashTable
double fullOfHashTable(Stack *hashTable[], int sizeOfHashTable);

//Print hashTable
void printHashTable(Stack *hashTable[], int sizeOfHashTable);

//Test
bool test1();

bool test2();