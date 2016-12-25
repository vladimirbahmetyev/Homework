#include <iostream>

using namespace std;

struct List
{
	int value;
	List *next;
};

void push(List *&head, int  value)
{
	List *newElement = new List{ value, head };
	head = newElement;      
}

int pop(List *&head)
{
	if (!head)
	{
		return 0;
	}
	int timeValue = head->value;
	List *oldElement = head;
	head = head->next;
	delete oldElement;
	return timeValue;
}

void printList(List *&head)
{
	List *cursor = head;
	while (cursor->next)
	{
		cout << cursor->value << " ";
		cursor = cursor->next;
	}
	cout << endl << endl;
}

void deleteList(List *&head)
{
	while (head)
	{
		pop(head);
	}
}

void addElementToSortList(List *&head, int value)
{
	if (!head)
	{
		push(head, value);
		return;
	}
	List *timeList = nullptr;
	while (value > head->value && head->next)
	{
		push(timeList, pop(head));
	}
	push(head, value);
	while (timeList)
	{
		push(head, pop(timeList));
	}
}

void deleteElementFromSortList(List *&head, int value)
{
	List  *cursor = head;
	while (cursor->next && cursor->value != value)
	{
		cursor = cursor->next;
	}
	if (!cursor->next)
	{
		cout << "Данного значения нет в списке" << endl << endl;
		return;
	}
	List *timeList = nullptr;
	while (value > head->value)
	{
		push(timeList, pop(head));
	}
	pop(head);
	while (timeList)
	{
		push(head, pop(timeList));
	}
	cout << "Значение успешно удалено " << endl << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	List * head = new List{0, nullptr};
	while (command != 0)
	{
		printf("Нажмите 0 чтобы выйти\n");
		printf("Нажмите 1 чтобы добавить значение в сортированный список\n");
		printf("Нажмите 2 чтобы удалить значения из списка\n");
		printf("Нажмите 3 чтобы распечатать список\n\n");
		scanf_s("%d", &command);
		printf("\n");
		switch (command)
		{
		case 0:;
			break;
		case 1: 
		{
			cout << "Введите значение ";
			int value = 0;
			cin >> value;
			cout << endl << endl;
			addElementToSortList(head, value);
			cout << "Значение успешно добавлено" << endl<< endl;
		};
			break;	
		case 2: 
		{
			cout << "Введите значение которое нужно удалить ";
			int value = 0;
			cin >> value;
			cout << endl;
			deleteElementFromSortList(head, value);
		};
			break;
		case 3: printList(head);
			break;
		default: cout << "Неккоректный ввод" << endl << endl;
		}
	}
	deleteList(head);
}