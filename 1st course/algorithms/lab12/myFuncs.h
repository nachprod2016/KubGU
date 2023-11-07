#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <iomanip>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Person.h"
#include <stdlib.h>

void userInterface();

void writeToFile(char *, Person &, FILE *);

void showFile(Person*, int);

void createPersonFromFile(Person &, char *);

void createString(char *, char *, int &);

void showPerson(Person &);

void createPerson(Person &);

void createFileName(char *);

bool checkFile(char *);

int sumPersons(char *);

Person * createList(int, FILE *);

int partition(Person *, int, int);

void swapPersons(Person &, Person &);

void qSort(Person *, int, int);

void insertionSort(Person *, int);

void copyPerson(Person &, Person &);

Person * search(Person *, int, int);

Person * searchBinary(Person *, int, int);

#endif