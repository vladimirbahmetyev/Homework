#include "HashTable.h"
#include <fstream>

int const sizeOfHashTable = 10000;

void main()
{
	List *hashTable[sizeOfHashTable] = {nullptr};
	setlocale (LC_ALL, "Russian");
	ifstream file("inputfile.txt");
	while (!file.eof())
	{
		string word = {};
		file >> word;
		addElementToHashTable(hashTable[hashKey(word, sizeOfHashTable)], word);
	}
	printHashTable(hashTable, sizeOfHashTable);
	cout << "Максимальная длина списка: " << maxLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "Средняя длина списка: " << averageLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "Коэффициент заполнения: " << fullOfHashTable(hashTable, sizeOfHashTable) << endl;
	deleteHashTable(hashTable, sizeOfHashTable);
	test_1();
	system("pause");
}