#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Person.h"
#include <stdlib.h>

void userInterface();

void writeToFile(char *, Person &, FILE *);

void showFile(FILE *);

void createPersonFromFile(Person &, char *);

void createString(char *, char *, int &);

void showPerson(Person &, int);

void createPerson(Person &);

void createFileName(char *);

bool checkFile(char *);

#endif