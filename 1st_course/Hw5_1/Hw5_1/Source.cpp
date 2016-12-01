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
		printf("������� ����� ��������: ");
	int addToStack = 0;
	scanf_s("%d", &addToStack);
	list * newListElement = new list{ addToStack, *head };
	*head = newListElement;
	printf("\n");
	printf("������� ������� ��������\n\n");
	newListElement = nullptr;
}

void pop(list **head)
{
	if ((**head).next != nullptr)
	{
		list *newHead = (**head).next;
		delete[] * head;
		*head = newHead;
		printf("������� ������� ������\n\n");
	}
	else
	{
		printf("������ ����, �������� ����������\n\n");
	}
}

void printList(list *head)
{
	if ((*head).next == nullptr)
	{
		printf("������ ������\n\n");
		return;
	}
	else
	{
		printf("������:\n");
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
		printf("������� 0 ����� �����\n");
		printf("������� 1 ����� �������� �������� � ������������� ������\n");
		printf("������� 2 ����� ������� �������� �� ������\n");
		printf("������� 3 ����� ����������� ������\n\n");
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