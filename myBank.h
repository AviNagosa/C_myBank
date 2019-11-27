#ifndef MYBANK_H
#define MYBANK_H

#define row 50
#define cow 2


#include<stdio.h>

double bankAccounts[row][cow];

int ifAccountOpen();


void openAccount();
void Balance();
void Deposit();
void Withdrawal();
void closeAccount();
void interestRate();
void printOpenAccount();
void closeAll();




















#endif
