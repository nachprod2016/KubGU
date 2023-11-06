#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <iostream>

void userInterface();

int** createMatrix(int, int, int);

void deleteMatrix(int**, int, int);

void setArray(int *, int, int);

int getMax(int *, int);

int getMin(int *, int, int);

void showMatrix(int**, int, int);

void getSpecialPoints(int**, int, int);

#endif