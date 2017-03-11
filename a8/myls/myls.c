/*
 * File: myls.c
 * Author: Dong Liang
 * Purpose: A similar version of ls.
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> 


typedef struct node{
char *str;
struct node * next;
}node;
node *h=NULL;
node *n;


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
 * sortlist(none)--inpt nothing but sort the linked list
 */
void sortlist(){
	char *temp;
	n=h;node *pi=n;
	while(pi!=NULL){
	while(n->next!=NULL){
		temp=strdup(n->str);
		if(strcmp(temp,n->next->str)>0){
			n->str=strdup(n->next->str);
			n->next->str=strdup(temp);
		}n=n->next;
	}pi=pi->next;n=h;
	}
}


/*
 * storefile(s)--input a dir path and store those files in to
 * the global linked list.
 */
void storefile(char dirname[])
{
   struct dirent *dp;;
   DIR *direct;
  
   if ((direct=opendir(dirname)) == NULL)	 
   {
      perror(dirname);
      exit(1);
   }
   else
   {
	  while ((dp=readdir(direct)) != NULL) {
		
		n=(node *)malloc(sizeof(node));
		n->str=strdup(dp->d_name);
		n->next=h;h=n;		
	}
      		closedir(direct); 
   }
} 

/*
 *main(i,char *)--get the comman as the dir name and print out
 *names of files under that path
 */

int main (int argc, char **argv)
{
if(argc>2)
    {
      fprintf(stderr,"too many args\n");
      exit(1);
    }
if (argc == 1)
   {  
      storefile(".");
   }
else  
    while (--argc > 0)
   {	     
	argv++;	 
 	storefile(*argv);
   }
	
	sortlist();
	plist(n);
   return 0;
}

