#pragma once

#include <string>
#include <iostream>

using namespace std;

struct Tree
{
	Tree *leftSon;
	Tree *rightSon;
	int value;
	string stringInTree;
};

//Turn tree to left
void zig(Tree  *&binaryTree);

//Turn tree to right
void zag(Tree  *&binaryTree);

//Check is value in tree
bool foundingOfNumber(Tree *&binaryTree, int value);

//Splaying root to key
void splayToKey(Tree *&binaryTree, int value);

//Add string to tree
void addString(Tree *&binaryTree, int value, string inputString);

//Delete string from tree
void deleteStringFromTree(Tree *&binaryTree, int value);

//Print string with key
void printStringFromTree(Tree *&binaryTree, int value);

//Delete Splay Tree
void deleteSplayTree(Tree *&binaryTree);

//Simple Test
void test();