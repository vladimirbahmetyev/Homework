#include <cstdio>
#include <iostream>

using namespace std;

struct List
{
	int value;
	List *next;
};

void push(int addToStack, List *&head)
{
	List * newListElement = new List{ addToStack, head };
	head = newListElement;
}

void pop(List *&head)
{
	List *newHead = head->next;
	delete head;
	head = newHead;
}

void roundList(int sizeOfList, List *&head)
{
	List *tale = head;
	for (int i = 1; i < sizeOfList; i++)
	{
		tale = tale->next;
	}
	tale->next = head;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	List * head = ( 0, nullptr );
	printf("Сколько было сикариев? ");
	int sizeOfList = 0;
	scanf_s("%d", &sizeOfList);
	printf("Какого по счету они убивали? ");
	int numberOfUnlucker = 0;
	scanf_s("%d", &numberOfUnlucker);
	for (int i = sizeOfList; i > 0; i--)
	{
		push(i, head);
	}
	roundList(sizeOfList, head);
	while (head != head->next)
	{
		for (int i = 0; i < numberOfUnlucker - 2; i++)
		{
			head = head->next;
		}
		List *nextElement = head->next->next;
		List *oldHead = head;
		head = head->next;
		pop(head);
		oldHead->next = nextElement;
	}
	printf("%s %d\n", "Выигрышная позиция номер: ", head->value);
	delete head;
	head = nullptr;
}