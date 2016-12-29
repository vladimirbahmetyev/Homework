#pragma once

struct Record;

struct Stack;

//Merge sort records from telephone list
Stack *mergeSort(Stack *&stack, int typeOfSort);

//Load telephone List from file
void loadFromFile(Stack *&stack);

//Test
void test1();

//Test
void test2();