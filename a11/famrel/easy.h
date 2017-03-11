/*
 * File: easy.h
 * Author: Dong liang
 * Purpose: header file for famrel program
 *
*/
#ifndef _EASY_H_
#define _EASY_H_
#include<stdio.h>

typedef struct tr{
  char *name;
  struct tr *next;
   struct tr *par;
}tr;



//The prototypes
void ftree(tr *);
void readf(FILE *);void opfile(char *);
void find(char *,char *,tr *);

int contain(char *,tr *);

void parent(char *,char *, tr *);
void plist(tr *);



#endif
