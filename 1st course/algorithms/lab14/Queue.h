#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

struct Queue
{
    Node * head;
    Node * tail;
    int count;
};

#endif