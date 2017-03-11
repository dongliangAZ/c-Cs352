/*
 * File: jdec.c
 * Author: Dong Liang
 * Purpose: A simple version of JVM.
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int sizee=0;
//A global varible to get the size of the stack



struct Stackin {
  char *data;
  struct Stackin *next;
};

struct stack
{
  struct Stackin *head;
  size_t size;  
};


/*
 * newStack()--Create a new stack
 */
struct stack *newStack(void)
{
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  
    s->head = NULL;
    s->size = 0;
  
  return s;
}

/*
 * cp(s)--Just like strdup()
 */
char *cp(char *s)
{
  char *temp = (char *)malloc(sizeof(char *));
  if (temp)
    strcpy(temp, s);
  return temp;
}

/*
 * push a string into the stack
 */
void push(struct stack *S, char *s)
{
  struct Stackin *e = (struct Stackin *)malloc(sizeof(struct Stackin)); 

    e->data = cp(s);
    e->next = S->head;
    S->head = e;S->size++;

  sizee++;
}

/*
 * get the top of the stack
 */
char *top(struct stack *S)
{
  if (S && S->head)
    return S->head->data;
  else
    return NULL;
}

/*
 * pop the top of this stack out
 */
void pop(struct stack *S)
{
  if (S->head != NULL)
  {
    struct Stackin *temp = S->head;
    S->head = S->head->next;
    free(temp->data);
    free(temp);
    S->size--;sizee--;
  }
   else{
	fprintf(stderr,"Can't do anything on NULL\n");
	exit(1);

	}
}







/*
 * split(**arr, *str, "") --Just like the split in java. 
 */
int split(char **arr, char *str, const char *del) {
  	char *s = strtok(str, del);
	int i;i=0;
  	while(s != NULL) {
    	i++;
	*arr++ = s;
	
     	s = strtok(NULL, del);
	
	
  	}return i;
 }

/*
 * turn(s) -- given a string and turn all the tab to space. 
 */
void turn(char *s){
	int i;
	for(i=0;i<strlen(s);i++)
	if(s[i]=='	')s[i]=' ';
} 


/*
 * sn(s) -- given a string s and check if there is char in this string not a number. 
 * if all elements in this string are numbers, return 1;
 * otherwise returns 0.
 */
int isn(char *s){
int i;
for(i=0;i<strlen(s);i++)
    if(!isdigit(s[i]))
    return 0;
return 1;
}
/*
 * ss(s) -- given a string s and check if there is char in this string not a number. 
 * if all elements in this string are numbers, return 1;
 * otherwise returns 0.
 */
int iss(char *s){
int i;
for(i=0;i<strlen(s);i++)
    if(!isalpha(s[i]))
    return 0;
return 1;
}
/*
 * sline(s) -- given a string s and check if there is char in this string not a number. 
 * if all elements in this string are numbers, return 1;
 * otherwise returns 0.
 */
int isline(char *s){
int i;
for(i=0;i<strlen(s);i++)
    if(!isspace(s[i])&&!isalpha(s[i])&&!isdigit(s[i]))
    return 0;
return 1;
}


/*
 * removeendspace(char *a) -- get rid of the spaces at the end of a line. 
 */

void removeendspace(char *a){
	int i=0;int j=0;int l=strlen(a);
	while(a[i]!='\0'){
	if(!isspace(a[i]))j=i;
	i++;
	
	}

	for(i=j+1;i<l;i++)
		a[i]='\0';
	}



/*
 * isempty(s) -- given a string and check if it is empty.
 * return 1 if it is empty.
 * 0 otherwise.
 */
int isempty(char *s){
	int i;
	if(strlen(s)==0)return 1;
	for(i=0;i<strlen(s);i++)
	if((int)s[i]!=32&&(int)s[i]!=13&&(int)s[i]!=9&&(int)s[i]!=10)
	return 0;
	return 1;
} 

/*
 * add(stack) -- A function help the main to deal with the iadd case.
 */
void add(struct stack *s){
	if(sizee<2){fprintf(stderr,"Error, try to do sth on NULL\n");exit(1);}
	char *t=(char *)malloc(sizeof(char *));
	char *t1=(char *)malloc(sizeof(char *));
	char *t2=(char *)malloc(sizeof(char *));
	strcpy(t1,top(s));pop(s);
	strcpy(t2,top(s));pop(s);
	strcat(t,"(");strcat(t,t2);strcat(t," + ");strcat(t,t1);strcat(t,")");
	push(s,t);	
}
/*
 * sub(stack) -- A function help the main to deal with the isub case.
 */
void sub(struct stack *s){
	if(sizee<2){fprintf(stderr,"Error, try to do sth on NULL\n");exit(1);}
	char *t=(char *)malloc(sizeof(char *));
	char *t1=(char *)malloc(sizeof(char *));
	char *t2=(char *)malloc(sizeof(char *));
	strcpy(t1,top(s));pop(s);
	strcpy(t2,top(s));pop(s);
	strcat(t,"(");strcat(t,t2);strcat(t," - ");strcat(t,t1);strcat(t,")");
	push(s,t);	
}
/*
 * mul(stack) -- A function help the main to deal with the imul case.
 */
void mul(struct stack *s){
	if(sizee<2){fprintf(stderr,"Error, try to do sth on NULL\n");exit(1);}
	char *t=(char *)malloc(sizeof(char *));
	char *t1=(char *)malloc(sizeof(char *));
	char *t2=(char *)malloc(sizeof(char *));
	strcpy(t1,top(s));pop(s);
	strcpy(t2,top(s));pop(s);
	strcat(t,"(");strcat(t,t2);strcat(t," * ");strcat(t,t1);strcat(t,")");
	push(s,t);	
}
/*
 * dv(stack) -- A function help the main to deal with the idiv case.
 */
void dv(struct stack *s){
	if(sizee<2){fprintf(stderr,"Error, try to do sth on NULL\n");exit(1);}
	char *t=(char *)malloc(sizeof(char *));
	char *t1=(char *)malloc(sizeof(char *));
	char *t2=(char *)malloc(sizeof(char *));
	strcpy(t1,top(s));pop(s);
	strcpy(t2,top(s));pop(s);
	strcat(t,"(");strcat(t,t2);strcat(t," / ");strcat(t,t1);strcat(t,")");
	push(s,t);	
}


/*
 * main() -- Get the input and do everything then print out the result.
 */

int main() {
  char *line;size_t n;
  
  char **arr;struct stack *stack = newStack();;
	
 while (getline(&line, &n, stdin) > 0)  {
	
	arr=(char **)malloc(sizeof(char **)); 
	turn(line);
	removeendspace(line);

	if(isempty(line)){}
	else if(!isline(line)){
	fprintf(stderr,"illegle nonletter input\n");
	exit(1);
	}
	else{
	int i=split(arr,line," ");
	if(i==2){
	if(strcmp(arr[0],"iload")==0&&iss(arr[1])){push(stack,arr[1]); }
	else if(strcmp(arr[0],"iconst")==0&&isn(arr[1])){push(stack,arr[1]);}
	else{ fprintf(stderr,"wrong input\n");exit(1);}
	}//i=2
	else if(i==1){
	if(strcmp(arr[0],"iadd")==0){add(stack);}
	else if(strcmp(arr[0],"isub")==0){sub(stack);}
	else if(strcmp(arr[0],"imul")==0){mul(stack);}
	else if(strcmp(arr[0],"idiv")==0){dv(stack);}
	else{fprintf(stderr,"wrong input\n");exit(1);}
	
	}
	else if(i>2){
	fprintf(stderr,"Too much input\n");
	exit(1);
	}

	else{}		
	
}//else    
}//while
	if(sizee==0){exit(0);}
	if(sizee>1){fprintf(stderr,"Error: More inputs\n");exit(1);}
	printf("%s\n",top(stack));
	return 0;
}

