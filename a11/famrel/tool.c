/*
 * File: tools.c
 * Author: dong liang
 * Purpose: This file contains functions.         
*/

#include "easy.h"
#include <string.h>
#include <stdlib.h>







/*
 *contain(s)-- return a value to show the string is already in
 */
int contain(char *s,tr *thetree){
	tr *t=thetree;
	while(t!=NULL){
  	if(strcmp(s,t->name)==0)return 1;
	t=t->next;
  }return 0;
}



/*
 *parrent(s,s,tr)-- Hard to describe
 */

void parent(char *s1,char *s2,tr *thetree){
	tr *t1;tr *t2;
	t1=thetree;
	while(strcmp(t1->name,s1)!=0)t1=t1->next;
	t2=thetree;
	while(strcmp(t2->name,s2)!=0)t2=t2->next;
	t2->par=t1;
	
	}


/*
 * plist(*node)--print out a linked list
 */
void plist(tr *thetree){	
	tr *t=thetree;
	
	while(t!=NULL){
	printf("%s\n",t->name);
	t=t->next;
	}
	
	return;
}


/*
 *ftreef()-- free the tree
 */
void ftree(tr *t){
	tr *t1,*t2;
	t1=t;
	while(t1!=NULL){
	t2=t1->next;
	free(t1->name);
	free(t1);
	t1=t2;
	}
	return;
}


/*
 * find(s,tr)
 */
void find(char *s,char *ss,tr *tree){
		tr *t=tree;int i=0;int j=0; int f=0;
	while(strcmp(s,t->name)!=0)
	t=t->next;
	
	tr *tt=tree;tr *temp;
	while(strcmp(ss,tt->name)!=0)tt=tt->next;
	while(t!=NULL){
	temp=tt;j=0;
	while(temp!=NULL){
	if(strcmp(t->name,temp->name)==0){f=1;break;}
	j++;temp=temp->par;
	}if(f)break;
	t=t->par;i++;
	}
	if(f)
	printf("%d %d\n",i,j);
	if(!f)
	printf("%d %d\n",-1,-1);return;
}