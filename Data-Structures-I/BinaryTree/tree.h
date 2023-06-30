#ifndef TREE_H
#define TREE_H

typedef struct tree {
  int value;
  struct tree *r;
  struct tree *l;
} tree_t;

typedef tree_t *root;

root newRoot(int);
void preOrder(root);
void insert(root, int);
int numberOfLeafs(root);
int largest(root);

#endif // !TREE_H
