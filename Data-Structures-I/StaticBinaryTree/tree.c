#include "tree.h"
#include <stdio.h>
#define root -9
#define empty_t -1

int __TREE_SIZE__;

void clearTree(tree *t, int size) {
  for (int i = 0; i < size; i++) {
    t[i].parent = empty_t;
    t[i].right = empty_t;
    t[i].left = empty_t;
  }
}

void initializeTree(tree *t, int size) {
  clearTree(t, size);
  __TREE_SIZE__ = size;
}

bool empty(tree *t) {
  if (t[0].parent != root)
    return true;
  return false;
}

int getMaxSize() { return __TREE_SIZE__; }

void createRoot(tree *t, key value) {
  if (!empty(t)) {
    printf("Árvore não está vazia!");
    return;
  }

  t[0].parent = root;
  t[0].right = empty_t;
  t[0].left = empty_t;
  t[0].value = value;
}

int newNode(tree *t, int parent, key value) {
  int i = 1;
  while (t[i].parent != empty_t)
    i++;

  t[i].value = value;
  t[i].parent = parent;
  t[i].right = empty_t;
  t[i].left = empty_t;

  return i;
}

void insert(tree *t, key value) {
  if (empty(t)){
    printf("Árvore sem raiz!\n");
    return;
  }

  int i = 0;

  while (true) {
    if (i >= __TREE_SIZE__) {
      printf("Árvore está cheia!\n");
      break;
    }

    if (value > t[i].value) {
      if (t[i].right == empty_t) {
        t[i].right = newNode(t, i, value);
        break;
      } else
        i = t[i].right;
    } else {
      if (t[i].left == empty_t) {
        t[i].left = newNode(t, i, value);
        break;
      } else
        i = t[i].left;
    }
  }
}

void printNode(tree *t, int i) { printf("Valor: %d\n", t[i].value); }

void callPrintTree2D(tree *t) { printTree2D(t, 0, 0); }

void printTree2D(tree *t, int i, int space) {
  if (i == empty_t)
    return;

  space += 5;

  printTree2D(t, t[i].right, space);

  printf("\n");
  for (int i = 5; i < space; i++)
    printf(" ");
  printf("%d\n", t[i].value);

  printTree2D(t, t[i].left, space);
}

void callPreOrder(tree *t) { preOrder(t, 0); }

void preOrder(tree *t, int i) {
  if (i != empty_t) {
    printNode(t, i);
    preOrder(t, t[i].left);
    preOrder(t, t[i].right);
  }
}

void callPosOrder(tree *t) { posOrder(t, 0); }

void posOrder(tree *t, int i) {
  if (i != empty_t) {
    posOrder(t, t[i].left);
    posOrder(t, t[i].right);
    printNode(t, i);
  }
}

void callInOrder(tree *t) { inOrder(t, 0); }

void inOrder(tree *t, int i) {
  if (i != empty_t) {
    inOrder(t, t[i].left);
    printNode(t, i);
    inOrder(t, t[i].right);
  }
}

int callNumberOfNodes(tree *t) { return numberOfNodes(t, 0); }

int numberOfNodes(tree *t, int i) {
  if (empty(t) || i == empty_t)
    return 0;

  int nRight = numberOfNodes(t, t[i].right);
  int nLeft = numberOfNodes(t, t[i].left);

  return (nRight + nLeft + 1);
}

int callHeight(tree *t) { return height(t, 0); }

int height(tree *t, int i) {
  if (empty(t) || i == empty_t)
    return 0;

  int hLeft = height(t, t[i].left);
  int hRight = height(t, t[i].right);

  if (hLeft > hRight)
    return (hLeft + 1);

  return (hRight + 1);
}

bool callBalanced(tree *t) { return balanced(t, 0); }

bool balanced(tree *t, int i) {
  if (empty(t))
    return true;
  else if (t[i].left == empty_t && t[i].right == empty_t)
    return true;
  else if (t[i].left != empty_t && t[i].right != empty_t)
    return (balanced(t, t[i].left) && balanced(t, t[i].right));
  else if (t[i].left != empty_t)
    return (height(t, t[i].left) == 1);
  else
    return (height(t, t[i].right) == 1);
}

bool callPerfectlyBalanced(tree *t) { return perfectlyBalanced(t, 0); }

bool perfectlyBalanced(tree *t, int i) {
  if (empty(t))
    return true;
  else if (t[i].left == empty_t && t[i].right == empty_t)
    return true;
  else if (t[i].left != empty_t && t[i].right != empty_t)
    return (perfectlyBalanced(t, t[i].left) &&
            perfectlyBalanced(t, t[i].right));
  else if (t[i].left != empty_t)
    return (numberOfNodes(t, t[i].left) == 1);
  else
    return (numberOfNodes(t, t[i].right) == 1);
}
