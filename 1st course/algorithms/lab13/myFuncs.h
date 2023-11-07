#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Stack.h"

void userInterface();

Stack * createStack(int);

void add(Stack * &, int);

Node * get(Stack * &);

#endif