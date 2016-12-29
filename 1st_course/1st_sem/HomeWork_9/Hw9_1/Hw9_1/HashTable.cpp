#include "HashTable.h"
#include <string>
#include "Stack.h"

using namespace std;

int hashKey(const string &word, int sizeOfHashTable)
{
	int hash = 1;
	for (int i = 0; i < size(word); i++)
	{
		hash = (144 + (int)word[i]) * hash + i - sizeOfHashTable + 144 + 666 + 777;
	}
	hash = hash % sizeOfHashTable;
	if (hash > 0)
	{
		return hash;
	}
	else
	{
		return hash * -1;
	}
}

void addElementToHashTable(Stack *head[], int sizeOfHashTable, const string &word)
{
	int key = hashKey(word, sizeOfHashTable);
	if (!addWordOrIncrieseCountOfWord(head[key], word))
	{
		push(1, word, head[key]);
	}
}

int maxLengthOfStack(Stack *hashTable[], int sizeOfHashTable)
{
	int maxStack = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (maxStack < countStack(hashTable[i]))
		{
			maxStack = countStack(hashTable[i]);
		}
	}
	return maxStack;
}

double averageLengthOfStack(Stack *hashTable[], int sizeOfHashTable)
{
	double length = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		length = length + (countStack(hashTable[i]));
	}
	return length / sizeOfHashTable;
} 

double fullOfHashTable(Stack *hashTable[], int sizeOfHashTable)
{
	double numberOfFullStacks = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable[i])
		{
			numberOfFullStacks++;
		}
	}
	return numberOfFullStacks / sizeOfHashTable;
}

void printHashTable(Stack *hashTable[], int sizeOfHashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable[i])
		{
			printStack(hashTable[i]);
		}
	}
}

bool test1()
{
	return hashKey("Hello", 10000) == 1925;
}

bool test2()
{
	Stack *hashTable[1] = { nullptr };
	addElementToHashTable(hashTable, 1, "Hello");
	return (addWordOrIncrieseCountOfWord(hashTable[0], "Hello"));	
}