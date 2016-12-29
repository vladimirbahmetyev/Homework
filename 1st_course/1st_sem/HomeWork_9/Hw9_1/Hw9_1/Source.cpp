#include "Stack.h"
#include "HashTable.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int const sizeOfHashTable = 10000;

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!(test1 && test2))
	{
		cout << "Ошибка" << endl;
		return;
	}
	Stack *hashTable[sizeOfHashTable] = {nullptr};
	ifstream file("inputfile.txt");
	while (!file.eof())
	{
		string word = {};
		file >> word;
		addElementToHashTable(hashTable, sizeOfHashTable , word);
	}
	printHashTable(hashTable, sizeOfHashTable);
	cout << "Максимальная длина списка: " << maxLengthOfStack(hashTable, sizeOfHashTable) << endl;
	cout << "Средняя длина списка: " << averageLengthOfStack(hashTable, sizeOfHashTable) << endl;
	cout << "Коэффициент заполнения: " << fullOfHashTable(hashTable, sizeOfHashTable) << endl;
	deleteArrayOfStacks(hashTable, sizeOfHashTable);
}