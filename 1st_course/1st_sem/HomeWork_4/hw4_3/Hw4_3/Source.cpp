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
	cout << "������� ��� ��������: ";
	cin >> list[*number].name;
	cout << "������� ����� ��������: ";
	cin >> list[*number].number;
	cout << "������� ������� ��������" << endl << endl;
}

void printAllContacts(Record list[], int *number)
{
	if (*number == 0)
	{
		cout << "������ ������" << endl;
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
	cout << "������� ��� ��������: ";
	string name = {};
	cin >> name;
	for (int i = 0; i <= *number; i++)
	{
		if (name == list[i].name)
		{
			cout << "�����" << " " << name << " " << list[i].number << endl << endl;
			return;
		}
	}
	cout << "������ ����� ��� � ������ :(" << endl << endl;
}

void searchWithNumber(Record list[], int * number)
{
	cout << "������� ���������� �����: ";
	int telephoneNumber = 0;
	cin >> telephoneNumber;
	for (int i = 0; i <= *number; i++)
	{
		if (list[i].number == telephoneNumber)
		{
			cout << "��� ����� " << list[i].name << endl << endl;
			return;
		}
	}
	cout << "������ ������ ��� � ������ :(" << endl << endl;
}

void saveAllToFile(Record list[], int *number)
{
	ofstream file("list.txt");
	for (int i = 0; i <= *number; i++)
	{
		file << list[i].name << " " << list[i].number << endl;
	}
	file.close();
	cout << "���������� �������" << endl << endl;
}

void loadFromFile(Record list[], int *sizeOfList)
{
	ifstream file("list.txt");
	int number = 0;
	if (!file.is_open())
	{
		cout << "������ �������� ������" << endl;
		cout << "�������� ������ ������" << endl;
		ofstream file("list.txt");
		file.close();
		cout << "������ ������� ������" << endl;
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
		cout << "������� 0 - �����" << endl;
		cout << "������� 1 - �������� ������ (��� � �������)" << endl;
		cout << "������� 2 - ����������� ��� ��������� ������" << endl;
		cout << "������� 3 - ����� ������� �� �����" << endl;
		cout << "������� 4 - ����� ��� �� ��������" << endl;
		cout << "������� 5 - ��������� ������� ������ � ����" << endl;
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
				cout << "������ ����������" << endl;
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
		default: cout << "������������ ����" << endl << endl;
		}
	}
}