#ifndef TREE_H
#define TREE_H

typedef struct tree tree_t;
typedef tree_t *root;

root newRoot(int value);
void insertTree(root tree, int value);
void posOrder(root tree);
void posOrderIterative(root tree);


#endif // !TREE_H
