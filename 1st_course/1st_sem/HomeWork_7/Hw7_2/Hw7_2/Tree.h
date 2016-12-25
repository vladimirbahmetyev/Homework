#pragma once;
#include <iostream>

using namespace std;

struct Tree;

bool isTreeFinish(Tree *binaryTree);

void printTree(Tree *binaryTree);

void pushToTree(Tree *&binaryTree, char symbol);

void loadFromFileToTree(Tree *&binaryTree);

int resultOfTree(Tree *binaryTree);

void deleteTree(Tree *&binaryTree);