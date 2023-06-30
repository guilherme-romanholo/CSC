#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

root newRoot(int value);
void insert(root *tree, int value);
void preOrder(root tree);
void vetToTree(int *vet, int ini, int fim, root *r);
void print2DUtil(root root, int space);

#endif // !TREE_H
