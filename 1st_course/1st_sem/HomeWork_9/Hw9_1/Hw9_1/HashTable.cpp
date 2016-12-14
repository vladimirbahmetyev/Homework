#include "HashTable.h"

int hashKey(string word)
{
	int hash = 1;
	for (int i = 0; i < size(word); i++)
	{
		hash = (int)word[i] * hash;
	}
	hash = hash % 10000;
	return hash;
}

bool isWordInList(List *&head, string word)
{
	if (word == head->word)
	{
		head->value++;
		return true;
	}
	if (!head->next)
	{
		return false;
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