
/*
 * File: Spellcheck.c
 * Author: Dong Liang
 * Purpose: print out the words that are not in the dictionary.
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
char *str;
struct node * next;
}node;
node *head=NULL;node *h;

node *uo;node *z;


int u=0;
char *dir;
char *file;


/*
 * turn(s)--make the char * input legal
 */
void turn(char s[]){
int i;
for(i=0;i<strlen(s);i++){
if(!isalpha(s[i]))s[i] = ' ';
s[i]=tolower(s[i]);
}
}
/*
 * plist(*node)--print out a linked list
 */
void plist(node *n){
	node *t=n;
	if(t==NULL)return;
	while(t!=NULL){
	printf("%s\n",t->str);
	t=t->next;
	}
	
	return;
}


/*
 * argcases(i,arr)--function to check the input agrgs
 */
void argcases(int i,char *arg[]){


if(i<3){
fprintf(stderr,"Error:Needs more arguments\n");
exit(1);
}
if(i>6){
fprintf(stderr,"Error:Needs fewer arguments\n");
exit(1);
}
if(i==3){
	
	if(strcmp(arg[1],"-d")==0){
	dir=strdup(arg[2]);
	}else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}

	}//i=3

if(i==4){
	u=1;
	if(strcmp(arg[1],"-u")==0){
	if(strcmp(arg[2],"-d")==0){
	dir=strdup(arg[3]);
	}else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}

	}
	if(strcmp(arg[3],"-u")==0){
	if(strcmp(arg[1],"-d")==0){
	dir=strdup(arg[2]);
	}else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}

	}
	}//i=4

if(i==5){
	if(strcmp(arg[1],"-d")==0&&
	strcmp(arg[3],"-i")==0){
		dir=strdup(arg[2]);
		file=strdup(arg[4]);
		}
	else if(strcmp(arg[1],"-i")==0&&
	strcmp(arg[3],"-d")==0){
		dir=strdup(arg[4]);
		file=strdup(arg[2]);
		}
	else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}
	}//i=5
if(i==6){
	u=1;

	if(strcmp(arg[1],"-u")==0){
	if(strcmp(arg[2],"-d")==0&&
	strcmp(arg[4],"-i")==0){
		dir=strdup(arg[3]);
		file=strdup(arg[5]);
		}
	else if(strcmp(arg[2],"-i")==0&&
	strcmp(arg[4],"-d")==0){
		dir=strdup(arg[5]);
		file=strdup(arg[3]);
		}
	else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}
	}//-u 1
	else if(strcmp(arg[3],"-u")==0){
	if(strcmp(arg[1],"-d")==0&&
	strcmp(arg[4],"-i")==0){
		dir=strdup(arg[2]);
		file=strdup(arg[5]);
		}
	else if(strcmp(arg[1],"-i")==0&&
	strcmp(arg[4],"-d")==0){
		dir=strdup(arg[5]);
		file=strdup(arg[2]);
		}
	else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}
	}//-u 3
	else if(strcmp(arg[5],"-u")==0){
		if(strcmp(arg[1],"-d")==0&&
	strcmp(arg[3],"-i")==0){
		dir=strdup(arg[2]);
		file=strdup(arg[4]);
		}
	else if(strcmp(arg[1],"-i")==0&&
	strcmp(arg[3],"-d")==0){
		dir=strdup(arg[4]);
		file=strdup(arg[2]);
		}
	else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}
	}//-u 5
	else{
	fprintf(stderr,"Wrong inputs\n");
	exit(1);
	}
	}//i=6
return;
}

/*
 * print(*n,s)--print step for spellcheck
 */
void print(node *n, char *s){
	node *temp=n;int i=0;
	while(temp!=NULL){
	if(strcmp(s,temp->str)==0){i=1;}
	temp=temp->next; 
 	}
	if(i==0)printf("%s\n",s);
	return;
}


/*
 *isin(*n,s)--check if the word is in the list
 */
int isin(node *n, char *s){
	node *temp=n;int i=0;
	while(temp!=NULL){
	if(strcmp(s,temp->str)==0){i=1;}
	temp=temp->next; 
 	}
	return i;
}


/*
 *swap(**p,**q)--swap 2 char[] with their address stay
 */
void swap(char **p, char **q) {
 char *tmp;

 tmp = *p;
 *p = *q;
 *q = tmp;
}
/*
 *sort(char *s[],**q)--swap 2 char[] with their address stay
 */		
void sort(char *s[], int n) {
 int i = 0;
 int j = 0;

 for(i = 0; i < n; ++i)
  for(j = i + 1; j < n; ++j)
   if(strcmp(s[i], s[j]) > 0)
    swap(&s[i], &s[j]);
}





/*
 *reverse(node * n)-- reverse a linked list then return a new node hold it
 */
node* reverse(node* root) {
  node* new_root = 0;
  while (root) {
    node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

/*
 *check(char *s,node * n)-- To find out if a word already exist in a list
 */
int check(char *s,node *n){
	node *t=n;int i;i=0;
	while(t!=NULL){
	if(strcmp(t->str,s)==0){i=1;}
	t=t->next;
	}
	return i;
}






/*
 * main(argc,argv)--spellcheck
 */
int main(int argc, char** argv){
char *line1=malloc(1024*sizeof(char));
char *line2=malloc(1024*sizeof(char));

node *diclist; char *t,*p;  char *temp;   ;

argcases(argc,argv);

if(((dir!=NULL)&&(dir[0]=='-'))||((file!=NULL)&&(file[0]=='-'))){
	fprintf(stderr,"File name start with - \n");
	exit(1);
	}



FILE *fpd=NULL;

if((fpd=fopen(dir,"r")) == NULL)
{
	perror(dir);
	exit(1);
}
else{
while((fgets(line1,1024,fpd))!=NULL){
	turn(line1);
	p=line1;
	while((t=strtok(p," "))!=NULL){
	p=NULL;
	diclist=(node *)malloc(sizeof(node));
	diclist->str=strdup(t);
	diclist->next=head;head=diclist;}		

}	
}
fclose(fpd);

if(argc>=5){
FILE *fpi=NULL;

if((fpi=fopen(file,"r")) == NULL)
{
	perror(file);
	exit(1);
}//if
else{
if(u==0){while((fgets(line2,1024,fpi))!=NULL){
	turn(line2);
	p=line2;
	while((t=strtok(p," "))!=NULL){
	p=NULL;
	temp=t;
	print(diclist,temp);
	
 
	}				
}}//while() u=0

if(u==1){
	while((fgets(line2,1024,fpi))!=NULL){
	turn(line2);
	p=line2;
	while((t=strtok(p," "))!=NULL){
	p=NULL;
	temp=t;
	if(isin(diclist,temp)==0){
	if(!check(temp,uo)){
 	printf("%s\n",temp);
	uo=(node *)malloc(sizeof(node));
	uo->str=strdup(temp);
	uo->next=h;h=uo;
	}else{}}

	}
	
				
}//while() 
	
}//u=1

}//else

fclose(fpi);


}//input from files

if(argc<=4){
if(u==0){while((fgets(line2,1024,stdin))!=NULL){
	turn(line2);
	p=line2;
	while((t=strtok(p," "))!=NULL){
	p=NULL;
	temp=t;
	print(diclist,temp);
	}				
}}//while() u=0
if(u==1){
	while((fgets(line2,1024,stdin))!=NULL){
	turn(line2);
	p=line2;
	while((t=strtok(p," "))!=NULL){
	p=NULL;
	temp=t;
	if(isin(diclist,temp)==0){
	if(check(temp,uo)==0){
 	printf("%s\n",temp);
	uo=(node *)malloc(sizeof(node));
	uo->str=strdup(temp);
	uo->next=h;h=uo;
	}else{}}
}
}//while() 
	
}//u=1


}//input is stdin



return 0;
}

