#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

int isFull(root node);
void insert(root node, int value);
root newRoot(int value);
void preOrder(root node);

#endif // !TREE_H
