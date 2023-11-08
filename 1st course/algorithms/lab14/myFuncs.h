#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Queue.h"

void userInterface();

Queue * createQueue(int);

void add(Queue * &, int);

void removeSecondElement(Queue * &);

void showQueue(Queue *);

void removeQueue(Queue *);

#endif