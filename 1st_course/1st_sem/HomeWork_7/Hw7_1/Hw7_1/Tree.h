#pragma once

struct Tree;

//Add number to tree
void addNumber(Tree *&binaryTree, int value);

//Checking is number in tree or is not
bool foundingOfNumber(Tree *&binaryTree, int value);

//Print Binary Tree In crease
void printBinaryTreeIncrease(Tree *&binaryTree);

//Print Binary Tree Decrease
void printBinaryTreeDecrease(Tree *&binaryTree);

//Delete element value from Tree
void deleteElementFromTree(Tree *&binaryTree, int value);

//Delete Tree
void deleteTree(Tree *&binaryTree);

//test
bool test1();

//test
bool test2();

//test
bool test3();