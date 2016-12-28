#pragma once

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct List;

//Add element to List
void push(int addToList,const string &word, List *&head);

//Delete element from List
List pop(List *&head);

//Print all List
void printList(List *&head);

//Delete all List
void deleteList(List *&head);

//Count length of List
int countList(List *&head);

//Check is this word in List and if it is true, increase count of word
bool addWordOrIncrieseCountOfWord(List *&head, const string &word);