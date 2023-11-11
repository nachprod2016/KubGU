#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Node.h"
#include "List.h"

void userInterface();

List * createList(int);

void add(List * &, int, int);

void showListStart(List *);

void removeList(List *);

void showListEnd(List *);

void sortlist(List * &);

void sortAdd(List * &, Node *);

void setHeadAndTail(List * &);

void moveLeft(List * &);

void moveRight(List * &);

void move(List * &);

int elementSearch(List * &, int);

#endif