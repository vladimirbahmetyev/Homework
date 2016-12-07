#include <cstdio>
#include <iostream>

using namespace std;

struct list
{
	int value;
	list *next;
};

void push(list **head)
{
		printf("Введите новое значение: ");
	int addToStack = 0;
	scanf_s("%d", &addToStack);
	list * newListElement = new list{ addToStack, *head };
	*head = newListElement;
	printf("\n");
	printf("Элемент успешно добавлен\n\n");
	newListElement = nullptr;
}

void pop(list **head)
{
	if ((**head).next != nullptr)
	{
		list *newHead = (**head).next;
		delete[] * head;
		*head = newHead;
		printf("Элемент успешно удален\n\n");
	}
	else
	{
		printf("Список пуст, удаление невозможно\n\n");
	}
}

void printList(list *head)
{
	if ((*head).next == nullptr)
	{
		printf("Список пустой\n\n");
		return;
	}
	else
	{
		printf("Список:\n");
		list printHead = *head;
		while (printHead.next != nullptr)
		{
			printf("%d %s", printHead.value, "\n");
			printHead = *printHead.next;
		}
	}
	printf("\n");
}

void deleteList(list **head)
{
	while ((**head).next != nullptr)
	{
		pop(head);
	}
	delete *head;
	*head = nullptr;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	list * head = new list{ 0, nullptr };
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
		case 1: push(&head);			
			break;	
		case 2: pop(&head);
			break;
		case 3: printList(head);
			break;
		}
	}
	deleteList(&head);
}