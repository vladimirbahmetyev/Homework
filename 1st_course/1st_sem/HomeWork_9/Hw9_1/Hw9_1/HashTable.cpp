#include "HashTable.h"

int hashKey(string word, int sizeOfHashTable)
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

bool isWordInList(List *&head, string word)
{
	List *cursor = head;
	while (cursor)
	{
		if (word == cursor->word)
		{
			cursor->value++;
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}

void addElementToHashTable(List *&head, string word)
{
	if (!isWordInList(head, word))
	{
		push(1, word, head);
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

void test_1()
{
	if (hashKey("Hello", 10000) == 1925)
	{
		cout << "Тест пройден" << endl << endl;
	}
	else
	{
		cout << "Тест не пройден" << endl << endl;
	}
}