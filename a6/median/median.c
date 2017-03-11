/*
 * File: median.c
 * Author: Dong Liang
 * Purpose: Find the median of a bunch of input numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



struct s {
	 int data;
	 struct s *next;
}*head=NULL;


/*
 * iseven(i) -- return 1 if the input number is even. 
 * 0 otherwise;
 */
int iseven(int i){
if(i%2==0)return 1;
return 0;
}





/*
 * isinput(s) -- given a string s and check if it is a good input, return 1;
 * otherwise returns 0.
 */
 int isinput(char *s){
  char *p;
  for (p = s; *p != '\0'; ++p) {
    if (!isdigit(*p) && !isspace(*p)&&(int)*p!=45) {
      return 0;
    }
  }
  return 1;
 }



/*
 * iswhat(s) is a very tricky function to solve a very tricky problem;
 */
int iswhat(char c){
if(c=='-')return 1;
if(isdigit(c))return 1;
return 0;
}








/*
 * main: Have input from stdin
 * find the median value
 */

int main(){
	int size;size=0;	
	char *line;line=malloc(1024*sizeof(char));
	int temp;temp=0;
	struct s *t;
    while(fgets(line,1024,stdin)>0){
	if(!isinput(line)){
	fprintf(stderr,"Error:non-integer input\n");return 1;
}	
	
	while(sscanf(line,"%d",&temp)>0){
	
	while(iswhat(*line++));
	
	while(isspace(*line))
       ++line;
        t=(struct s*)malloc(sizeof(struct s));    
	    	(t->data)=temp;
		
		t->next=head;
		head=t;
		size++;   
	
	}
}
	
	int magic;
	if(size==0){
	fprintf(stderr,"Error: Empty input\n");
	return 1;
	}
	
	
	t=head; struct s *pi=t;
	while(pi!=NULL){
	
	while(t->next!=NULL){
	magic=t->data;
	if(magic>((t->next)->data)){
	t->data=t->next->data;(t->next)->data=magic;
	}
	t=t->next;

	}pi=pi->next;
	t=head;
	}

	t=head;int j;float mid;float mid2;
	

	if(iseven(size)){

	for(j=1;j<(size/2);j++)
	t=t->next;
	mid=(float)t->data;
	t=t->next;
	mid2=(float)t->data;
	printf("%f\n",(mid+mid2)/2);
	}
	
	else{
	
	for(j=1;j<(size/2+1);j++)
	t=t->next;
	mid=(float)t->data;
	printf("%f\n",mid);
	}
	
	return 0;
}


