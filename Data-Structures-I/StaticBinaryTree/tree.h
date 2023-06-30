#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

extern int __TREE_SIZE__;

typedef int key;

typedef struct no {
  key value;
  int right;
  int left;
  int parent;
} tree;

void clearTree(tree *t, int size);
void initializeTree(tree *t, int size);
bool empty(tree *t);
int getMaxSize();
void createRoot(tree *t, key value);
void insert(tree *t, key value); // Valores maiores na direita, menores na esquerda
int newNode(tree *t, int parent, key value);
void callPrintTree2D(tree *t);
void printTree2D(tree *t, int i, int space);
void callPreOrder(tree *t);
void preOrder(tree *t, int i);
void callPosOrder(tree *t);
void posOrder(tree *t, int i);
void callInOrder(tree *t);
void inOrder(tree *t, int i);
void printNode(tree *t, int i);
int callNumberOfNodes(tree *t);
int numberOfNodes(tree *t, int i);
int callHeight(tree *t);
int height(tree *t, int i);
bool callBalanced(tree *t);
bool balanced(tree *t, int i);
bool callPerfectlyBalanced(tree *t);
bool perfectlyBalanced(tree *t, int i);

#endif // !TREE_H
