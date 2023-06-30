#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

root newRoot(int value);
void insert(root tree, int value);
void preOrder(root tree);
root search_insert(root r, int value);


#endif // !TREE_H
