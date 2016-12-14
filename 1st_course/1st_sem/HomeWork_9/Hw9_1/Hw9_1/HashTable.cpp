#include "HashTable.h"

int hashKey(string word)
{
	int hash = 1;
	for (int i = 0; i < size(word); i++)
	{
		hash = (int)word[i] * hash;
	}
	hash = hash % 10000;
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
	if (!head)
	{
		return false;
	}
	if (word == head->word)
	{
		head->value++;
		return true;
	}	
	return isWordInList(head->next, word);
}

void addElementToHashTable(List *&head, string word)
{
	if (!isWordInList(head, word))
	{
		push(1, word, head);
	}
}