#include "stack.h"
#include "HashTable.h"
#include <fstream>

void main()
{
	List *hashTable[10000] = {nullptr};
	setlocale (LC_ALL, "Russian");
	ifstream file("inputfile.txt");
	while (!file.eof())
	{
		string word = {};
		file >> word;
		addElementToHashTable(hashTable[hashKey(word)], word);
	}
	for (int i = 0; i < 10000; i++)
	{
		if (hashTable[i])
		{
			printList(hashTable[i]);
		}
	}
	system("pause");
}