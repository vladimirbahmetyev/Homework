#include "HashTable.h"
#include <fstream>

int const sizeOfHashTable = 10000;

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!(test1 && test2))
	{
		cout << "������" << endl;
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
	cout << "������������ ����� ������: " << maxLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "������� ����� ������: " << averageLengthOfList(hashTable, sizeOfHashTable) << endl;
	cout << "����������� ����������: " << fullOfHashTable(hashTable, sizeOfHashTable) << endl;
	deleteHashTable(hashTable, sizeOfHashTable);
}