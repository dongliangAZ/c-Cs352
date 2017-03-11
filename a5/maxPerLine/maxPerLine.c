/*
 * File: maxPerLine.c
 * Author: Dong Liang
 * Purpose: Find the largest number for each line from stdin.
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
 * isinput(s) -- given a string s and check if it is a good input, return 1;
 * otherwise returns 0.
 */
 int isinput(char s[]){
 	int i;int result =1;
 	for(i=0;i<strlen(s);i++)
 	if(((int)s[i]>57||(int)s[i]<48)&&(int)s[i]!=32&&(int)s[i]!=13&&(int)s[i]!=10&&(int)s[i]!=9) result=0;
 	return result;
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
 * main: Have input from stdin
 * get the largest number for each line.
 */

int main()
{
int temp;
int i=0;int e=0;
  char line[1025];
  char *arr[1025];
  while(fgets(line,1025,stdin)>0){
		turn(line);
		if(isempty(line)){
		fprintf(stderr,"Empty input\n");
		e=1;	
		}
		else if(!isinput(line)){
	  	fprintf(stderr,"Not a good input\n");
		e=1;
	  }

  	else{
    split(arr,line," ");
     temp=atoi(arr[0]);
  for(i=0;arr[i]!=NULL;i++){
    if(atoi(arr[i])>temp)temp=atoi(arr[i]);
  	}
    printf("%d\n",temp);
    while(i>=0){
        arr[i]=NULL;
        i--;
    }
	}

	}

  return e;

}
