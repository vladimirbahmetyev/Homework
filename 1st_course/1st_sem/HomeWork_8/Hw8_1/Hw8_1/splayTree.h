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

void zig(Tree  *&binaryTree);

void zag(Tree  *&binaryTree);

void splayToKey(Tree *&binaryTree, int value);

bool foundingOfNumber(Tree *&binaryTree, int value);

void addString(Tree *&binaryTree, int value, string inputString);

void deleteStringFromTree(Tree *&binaryTree, int value);

void printStringFromTree(Tree *&binaryTree, int value);