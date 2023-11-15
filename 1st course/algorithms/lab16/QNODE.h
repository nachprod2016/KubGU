#ifndef QNODE_H
#define QNODE_H

#include <iostream>
#include "NODE.h"

struct QNODE
{
    int key;
    int level;
    QNODE * next;
};

QNODE * createQNODE(NODE *, int);

void addQNode(QNODE * &, QNODE *);

void deleteQueue(QNODE *);

#endif