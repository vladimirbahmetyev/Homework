#pragma once

#include "stack.h"

//Count hash
int hashKey(string word, int sizeOfHashTable);

//Cheking is word in list or no
bool isWordInList(List *&head, string word);

//Add  word to hashTable
void addElementToHashTable(List *&head, string word);

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
void test_1();