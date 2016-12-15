#pragma once

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct List
{
	int value;
	string word;
	List *next;
};

//Add element to stack
void push(int addToStack, string word, List *&head);

//Delete element from stack
List pop(List *&head);

//Print all stack
void printList(List *&head);

//Delete all List
void deleteList(List *&head);

//Count length of list
int countList(List *&head);