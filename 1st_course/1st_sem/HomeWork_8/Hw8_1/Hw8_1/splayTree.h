#pragma once

#include <string>
#include <iostream>

using namespace std;

struct Tree;
struct Array;

//Check is value in tree
bool foundingOfNumber(Tree *&binaryTree, const string &key);

//Add string to tree
void addString(Tree *&binaryTree, const string &key, const string &newString);

//Delete string from tree
void deleteStringFromTree(Tree *&binaryTree, const string &value);

//Print string with key
void printStringFromTree(Tree *&binaryTree, const string &value);

//Delete Splay Tree
void deleteSplayTree(Tree *&binaryTree);