#include "HashTable.h"

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

void addElementToHashTable(List *head[], int sizeOfHashTable, const string &word)
{
	int key = hashKey(word, sizeOfHashTable);
	if (!addWordOrIncrieseCountOfWord(head[key], word))
	{
		push(1, word, head[key]);
	}
}

void deleteHashTable(List *hashTable[], int sizeOfHashtable)
{
	for (int i = 0; i < sizeOfHashtable; i++)
	{
		if (hashTable[i])
		{
			deleteList(hashTable[i]);
		}
	}
	delete[] *hashTable;
	hashTable = nullptr;
}

int maxLengthOfList(List *hashTable[], int sizeOfHashTable)
{
	int maxList = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (maxList < countList(hashTable[i]))
		{
			maxList = countList(hashTable[i]);
		}
	}
	return maxList;
}

double averageLengthOfList(List *hashTable[], int sizeOfHashTable)
{
	double length = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		length = length + (countList(hashTable[i]));
	}
	return length / sizeOfHashTable;
} 

double fullOfHashTable(List *hashTable[], int sizeOfHashTable)
{
	double numberOfFullLists = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable[i])
		{
			numberOfFullLists++;
		}
	}
	return numberOfFullLists / sizeOfHashTable;
}

void printHashTable(List *hashTable[], int sizeOfHashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable[i])
		{
			printList(hashTable[i]);
		}
	}
}

bool test1()
{
	return hashKey("Hello", 10000) == 1925;
}

bool test2()
{
	List *hashTable[1] = { nullptr };
	addElementToHashTable(hashTable, 1, "Hello");
	return (addWordOrIncrieseCountOfWord(hashTable[0], "Hello"));	
}