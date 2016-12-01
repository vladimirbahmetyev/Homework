#include <cstdio>
#include <iostream>

using namespace std;

struct list
{
	int value;
	list *next;
};

void push(int addToStack, list **head)
{
	list * newListElement = new list{ addToStack, *head };
	*head = newListElement;
	newListElement = nullptr;
}

void pop(list **head)
{
	list *newHead = (**head).next;
	delete[] * head;
	*head = newHead;
}

void roundList(int sizeOfList, list **head)
{
	list *tale = *head;
	for (int i = 1; i < sizeOfList; i++)
	{
		tale = (*tale).next;
	}
	(*tale).next = *head;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	list * head = ( 0, nullptr );
	printf("Сколько было сикариев? ");
	int sizeOfList = 0;
	scanf_s("%d", &sizeOfList);
	printf("Какого по счету они убивали? ");
	int numberOfUnlucker = 0;
	scanf_s("%d", &numberOfUnlucker);
	for (int i = sizeOfList; i > 0; i--)
	{
		push(i, &head);
	}
	roundList(sizeOfList, &head);
	while (&*head != (*head).next)
	{
		for (int i = 0; i < numberOfUnlucker - 2; i++)
		{
			*&head = (*head).next;
		}
		list *nextElement = (*(*head).next).next;
		list *oldHead = head;
		*&head = (*head).next;
		pop(&head);
		(*oldHead).next = nextElement;
	}
	printf("%s %d\n", "Выигрышная позиция номер: ", (*head).value);
	delete head;
	head = nullptr;
	system("pause");
}