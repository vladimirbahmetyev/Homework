#pragma once

#include "stack.h"

//Add  word to hashTable
void addElementToHashTable(List *head[], int sizeOfHashTable,const string &word);

//Delete hashTable
void deleteHashTable(List *hashTable[], int sizeOfHashtable);

//Find the longest list in hashTable
int maxLengthOfList(List *hashTable[], int sizeOfHashTable);

//Count average length of list in hashTable
double averageLengthOfList(List *hashTable[], int sizeOfHashTable);

//Count fulling hashTable
double fullOfHashTable(List *hashTable[], int sizeOfHashTable);

//Print hashTable
void printHashTable(List *hashTable[], int sizeOfHashTable);

//Test
bool test1();

bool test2();