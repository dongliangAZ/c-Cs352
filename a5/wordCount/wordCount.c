/*
 * File: wordCount.c
 * Author: Dong Liang
 * Purpose: count for each word
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
 * split(**arr, *str, "") --Just like the split in java. 
 */
void split(char **arr, char *str, const char *del) {
  	char *s = strtok(str, del);

  	while(s != NULL) {
    	*arr++ = s;
     	s = strtok(NULL, del);
  	}
 }

/*
 * turn(s) -- given a string and turn all the tab to space.
 */
void turn(char *s){
	int i;
	for(i=0;i<strlen(s);i++)
	if(isspace(s[i]))s[i]=' ';
} 



/*
 * a(**arr , *s, n) -- input and string[] and word
 *store the times of the word appears in this arr to n
 */
int a(char **arr, char *s){
int i;int n=0;
for(i=0;arr[i]!=NULL;i++)
{if(strcmp(arr[i],s)==0&&s!=NULL){n++;arr[i]=NULL;}}return n;
}
typedef struct node{
char *str;
struct node * next;
}node;
node *h=NULL;node *no;node *z;
/*
 * check(*node)--nocomments
 */int check(char *s,node *n){node *t=n;int i=0;while(t!=NULL){if(strcmp(s,t->str)==0)i++;t=t->next;}return i;}
/*
 * plist(*node)--print out a linked list
 */
void plist(node *n){
	node *t=n;int i=0;int j;if(t==NULL)return;
	while(t!=NULL){
	if((i=check(t->str,no))>1){printf("%s %d\n",(t->str),i);for(j=i;j!=0;j--)t=t->next;}
	else{printf("%s %d\n",(t->str),i);t=t->next;}}}/*
 * sortlist(none)--inpt nothing but sort the linked list
 */
void sortlist(){
	char *temp;no=h;node *pi=no;while(pi!=NULL){while(no->next!=NULL){
	temp=strdup(no->str);if(strcmp(temp,no->next->str)>0){strcpy(no->str,no->next->str);strcpy(no->next->str,temp);
}no=no->next;}pi=pi->next;no=h;}}
/*
 * main: Have input from stdin
 * Get each word and get the word count;
 */
int main()
{char *t,*p;char *temp;
char line[128*1024];int i,j;i=0;j=0;

	char ch='\0';
while((ch=getchar())!=EOF)
{
	if(isalpha(ch)||isspace(ch)){
	line[i]=tolower(ch);i++;
	if(isspace(ch))j++;
	}
}turn(line);p=line;
while((t=strtok(p," "))!=NULL){
	p=NULL;temp=t;no=(node *)malloc(sizeof(node));no->str=strdup(temp);no->next=h;h=no;
}sortlist();plist(no);

/*split(arr,line," ");


for(i=0;i<1025;i++){ 
   
   j=a(arr,arr[i]);
   if(arr[i]!=NULL)
	
    j=0;
	}*/ 
  return 0;

}

