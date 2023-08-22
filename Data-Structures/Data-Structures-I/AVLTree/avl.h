#ifndef AVL_H
#define AVL_H

typedef struct avl avl_t;

avl_t *insert(avl_t *root, int key);
avl_t *remocao(avl_t *root, int key);
void preOrder(avl_t *root);

#endif // !AVL_H
