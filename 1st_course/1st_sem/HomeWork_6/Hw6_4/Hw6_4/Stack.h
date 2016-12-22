#pragma once

#include <string>

using namespace std;

struct Record
{
	string name;
	int number;
};

struct List
{
	Record record;
	List *next;
};

void push(Record newRecord, List *&head);

Record pop(List *&head);

void printList(List *&head);

void deleteList(List *&head);