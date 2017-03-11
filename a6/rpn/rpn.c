/*
 * File: rpn.c
 * Author: Dong Liang
 * Purpose: An easy form of rpn caculator.
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef struct stack
{
	int maxsize;
        int size;
        int *e;
}stack;

/*
 * create(max) -- given a number for the size of a stack. 
 * Then create a stack and return it;
 */
stack * create(int max)
{

        stack *S;
        S = (stack *)malloc(sizeof(stack));
       
        S->e = (int *)malloc(sizeof(int)*max);
        S->size = 0;
        S->maxsize = max;
        
        return S;
}


/*
 *  ---pop(pop out the top value out of a stack)
 */
void pop(stack *S)
{
	if(S->size==0)return;
	S->size--;
        return;
}

/*
 *  ---push(push an element in)
 */
void push(stack *S,int E)
{
       if(S->size==S->maxsize)return;
       S->e[S->size++] = E;
        return;
}

/*
 *  ---top(get the value of the top of the stack)
 */
int top(stack *S)
{
       if(S->size==0)return 0;

        return S->e[S->size-1];
}


/*
 * sdigit(s) -- given a string s and check if there is char in this string not a number. 
 * if all elements in this string are numbers, return 1;
 * otherwise returns 0.
 */
int sdigit(char *s){
int i;
for(i=0;i<strlen(s);i++)
    if(!isdigit(s[i])&&s[i]!='-')
    return 0;
return 1;
}

/*
 * sdoit(s, c) -- given a char and stack. 
 * do the math with the topest 2 numbers in the stack;
 * the char were assumed to be'+' or '-' or '*' or '/'
 */
void doit(stack *s,char c,int special){
	int m,n;
	if(s->size<2){
	special=1;
	return;
	}
	else{
	m=top(s);pop(s);
	n=top(s);pop(s);
	switch((int)c){
	case '+':
	push(s,n+m);
	break;
	case '-':
	push(s,n-m);
	break;
	case '*':
	push(s,n*m);
	break;
	case '/':
	push(s,n/m);
	break;
	}

}	
}


/*
 * main() -- get input line by line.
 * caculate them in rpn way
 * the char were assumed to be'+' or '-' or '*' or '/'
 */


int main() {
  char *line, *tok, *p;int special,special2;
  size_t n;int end;
	end=0;
  
  while (getline(&line, &n, stdin) > 0) {

    special =1;special2 =0;
   int num=0,sign=0;
    stack *s=create(strlen(line));
    p = line;
    while ((tok = strtok(p, " \t\n\r")) != NULL) {  
   	
	p = NULL; 
	if(strlen(tok)>1&&sdigit(tok)){push(s,atoi(tok));num++; }
	
	else if(strlen(tok)==1&&isdigit(tok[0])){push(s,atoi(tok));num++; }

	else if(strlen(tok)==1&&!isdigit(tok[0])){
	char ctemp= tok[0];
	if(ctemp=='+'||ctemp=='-'||ctemp=='*'||ctemp=='/'){
	sign++;doit(s,ctemp,special2);
	}
	if((num>=1)&&(num<=sign)){special=0;break;}	  
    }
	else{special=-1;}
		
  }
	if(sign==0&&num==0&&special!=-1){fprintf(stderr,"Empty input\n");
	end =1 ;
	}
	else if(special==0||special2==1){
	fprintf(stderr,"Not enough ops\n");
	end =1 ;
	}
	
	else if(num-sign!=1||special==-1){
	fprintf(stderr,"Illeagle input\n");
	end =1 ;
	}	

	
	else{
	
	printf("%d\n",top(s));
	}
    
}

return end;
}

