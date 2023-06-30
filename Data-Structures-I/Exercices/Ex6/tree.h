#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

int empty(root tree);
root newRoot(int value);
void insert(root tree, int value);
int numberOfLeaves(root tree);
void preOrder(root tree);
int largest(root tree);


#endif // !TREE_H
