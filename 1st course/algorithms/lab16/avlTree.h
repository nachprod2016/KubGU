#ifndef AVLTREE_H
#define AVLTREE_H

#include "NODE.h"
#include "QNODE.h"

struct AVLTree
{
    NODE * root;
};

unsigned char height(NODE * p);

int bfactor(NODE * p);

void fixheight(NODE * p);

NODE * rotateright(NODE * p);

NODE * rotateleft(NODE * q);

NODE * balance(NODE * p);

NODE * insert(NODE * &p, int k); 

void print_dfs(NODE * p, int level);

void print_c(NODE * p, int level);

void print_reverse(NODE * p, int level);

void insertRoot(NODE * & p, int k);

void print(NODE * p);

void searchNode(NODE * &, NODE *, int);

void searchParent(NODE *, NODE * &, int);

NODE * getMinimumKey(NODE *);

void deleteNode(NODE * &, int);

void deleteTree(NODE *);

void widthTraversal(NODE *, QNODE * &, int);

void showWidthTraversal(QNODE *);

void calcNumbersNodes(QNODE *);

#endif