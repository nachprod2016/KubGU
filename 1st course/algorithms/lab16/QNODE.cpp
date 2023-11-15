#include "QNODE.h"

QNODE * createQNODE(NODE * node, int lvl)
{
    QNODE * qnode = new QNODE();
    qnode->key = node->key;
    qnode->level = lvl;
    qnode->next = NULL;
    return qnode;
}

void addQNode(QNODE * & root, QNODE * addNODE)
{
    if (root == NULL)
    {
        root = addNODE;
        return;
    }
    QNODE * ptr = root;
    while (true)
    {
        if (ptr->level <= addNODE->level && ptr->next == NULL)
        {
            ptr->next = addNODE;
            break;
        }
        if (ptr->level <= addNODE->level && ptr->next->level > addNODE->level)
        {
            addNODE->next = ptr->next;
            ptr->next = addNODE;
            break;
        }
        ptr = ptr->next;
    }
}

void deleteQueue(QNODE * qroot)
{
    while (qroot != NULL)
    {
        QNODE * ptr = qroot;
        qroot = qroot->next;
        delete ptr;
    }
}