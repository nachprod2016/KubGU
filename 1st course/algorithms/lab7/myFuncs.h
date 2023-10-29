#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include "CallInformation.h"

void userInterface();

void showCalls(CallInformation **, int);

void setDateCall(CallInformation &);

void setCity(CallInformation &);

void setTalkTime(CallInformation &);

void setRate(CallInformation &);

void setPhoneNumbers(CallInformation &);

void createCall(CallInformation &);

void deleteCalls(CallInformation **, int);

void showSumm(CallInformation ** calls, int size);

#endif