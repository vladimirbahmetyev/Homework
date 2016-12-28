#pragma once

#include <string>
#include <iostream>

using namespace std;

struct Tree;
struct Array;

//Check is value in tree
bool foundingOfNumber(Tree *&binaryTree, Array *value);

//Add string to tree
void addString(Tree *&binaryTree, Array *value);

//Delete string from tree
void deleteStringFromTree(Tree *&binaryTree, int value);

//Print string with key
void printStringFromTree(Tree *&binaryTree, Array *value);

//Delete Splay Tree
void deleteSplayTree(Tree *&binaryTree);

//Simple Test
void test();