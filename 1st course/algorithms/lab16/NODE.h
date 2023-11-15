#ifndef NODE_H
#define NODE_H

#include <iostream>

struct NODE
{
    int key;
    unsigned char height ;  
    NODE * left ;
    NODE * right ;
};

NODE * createNODE(int);

#endif