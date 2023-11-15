#include "NODE.h"

NODE * createNODE(int k)
{
    NODE * node = new NODE();
    node->key = k;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}