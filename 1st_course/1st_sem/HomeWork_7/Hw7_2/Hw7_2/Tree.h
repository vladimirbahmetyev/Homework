#pragma once

struct Tree;

//Print tree
void printTree(Tree *binaryTree);

//Load tree from File
void loadFromFileToTree(Tree *&binaryTree);

//Count result of tree
int resultOfTree(Tree *binaryTree);

//Delete Tree
void deleteTree(Tree *&binaryTree);