#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Record
{
	string name;
	int number;
};

void addNewContact(Record list[], int * number)
{
	*number = *number + 1;
	cout << "Введите имя контакта: ";
	cin >> list[*number].name;
	cout << "Введите номер контакта: ";
	cin >> list[*number].number;
	cout << "Контакт успешно добавлен" << endl << endl;
}

void printAllContacts(Record list[], int *number)
{
	if (*number == 0)
	{
		cout << "Список пустой" << endl;
		return;
	}
	else
	{
		for (int i = 0; i <= *number; i++)
		{
			cout << list[i].name << " " << list[i].number << endl;
		}
	}
	cout << endl;
}

void searchWithName(Record list[], int *number)
{
	cout << "Введите имя контакта: ";
	string name = {};
	cin >> name;
	for (int i = 0; i <= *number; i++)
	{
		if (name == list[i].name)
		{
			cout << "Номер" << " " << name << " " << list[i].number << endl << endl;
			return;
		}
	}
	cout << "Такого имени нет в списке :(" << endl << endl;
}

void searchWithNumber(Record list[], int * number)
{
	cout << "Введите телефонный номер: ";
	int telephoneNumber = 0;
	cin >> telephoneNumber;
	for (int i = 0; i <= *number; i++)
	{
		if (list[i].number == telephoneNumber)
		{
			cout << "Это номер " << list[i].name << endl << endl;
			return;
		}
	}
	cout << "Такого номера нет в списке :(" << endl << endl;
}

void saveAllToFile(Record list[], int *number)
{
	ofstream file("list.txt");
	for (int i = 0; i <= *number; i++)
	{
		file << list[i].name << " " << list[i].number << endl;
	}
	file.close();
	cout << "Сохранение успешно" << endl << endl;
}

void loadFromFile(Record list[], int *sizeOfList)
{
	ifstream file("list.txt");
	int number = 0;
	if (!file.is_open())
	{
		cout << "Ошибка загрузки списка" << endl;
		cout << "Создание нового списка" << endl;
		ofstream file("list.txt");
		file.close();
		cout << "Список успешно создан" << endl;
	}
	else
	{
		while (!file.eof())
		{
			file >> list[number].name;
			file >> list[number].number;
			number++;
		}
		file.close();
	}
	*sizeOfList = number - 1;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	Record list[100] = {};
	int sizeOfList = 0;
	loadFromFile(list, &sizeOfList);
	while (command != 0)
	{
		cout << "Нажмите 0 - выйти" << endl;
		cout << "Нажмите 1 - добавить запись (имя и телефон)" << endl;
		cout << "Нажмите 2 - распечатать все имеющиеся записи" << endl;
		cout << "Нажмите 3 - найти телефон по имени" << endl;
		cout << "Нажмите 4 - найти имя по телефону" << endl;
		cout << "Нажмите 5 - сохранить текущие данные в файл" << endl;
		cout << endl;
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 0:;
			break;
		case 1: 
			if (sizeOfList <= 100)
			{
				addNewContact(list, &sizeOfList);
			}
			else
			{
				cout << "Список переполнен" << endl;
			}
				break;
		case 2: printAllContacts(list, &sizeOfList);
			break;
		case 3: searchWithName(list, &sizeOfList);
			break;
		case 4: searchWithNumber(list, &sizeOfList);
			break;
		case 5: saveAllToFile(list, &sizeOfList);
			break;
		default: cout << "Неккоректный ввод" << endl << endl;
		}
	}
}