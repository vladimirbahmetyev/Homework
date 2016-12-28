#include "HashTable.h"
#include <fstream>

int const sizeOfHashTable = 10000;

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!(test1 && test2))
	{
		cout << "Ошибка" << endl;
		return;
	}
	List *hashTable[sizeOfHashTable] = {nullptr};
	ifstream file("inputfile.txt");
	while (!file.eof())
	{
		string word = {};
		file >> word;
		addElementToHashTable(hashTable, sizeOfHashTable , word);
	}
	printHashTable(hashTable, sizeOfHashTable);
	cout << "Максимальная длина списка: " << maxLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "Средняя длина списка: " << averageLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "Коэффициент заполнения: " << fullOfHashTable(hashTable, sizeOfHashTable) << endl;
	deleteHashTable(hashTable, sizeOfHashTable);
}