#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

void insert(root node, int value);
root newRoot(int value);
void preOrder(root node);
int *lessThanN(root node, int n);

#endif // !TREE_H
