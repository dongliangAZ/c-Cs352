/*
 * File: shuffle.c
 * Author: Dong Liang
 * Purpose: Have 2 lines from stdin and print out them after shuffled.
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
 * isinput(s) -- given a string s and check if it is a good input, return 1;
 * otherwise returns 0.
s
x */
 int isinput(char s[]){
 	int i;int result =1;
 	for(i=0;i<strlen(s);i++)
 	if(!isdigit(s[i])&&!isspace(s[i]))return 0;
 	return result;
 }


/*
 * main: Have input from stdin
 * Get the two lines of numbers and return them after shuffled
 */
int main()
{
 
char line1[1025]={0};char *arr1[1025];
char line2[1025]={0};char *arr2[1025];
int i=0,j=0;
int a1[1025];int a2[1025];
fgets(line1,1025,stdin);fgets(line2,1025,stdin);
turn(line1);turn(line2);
if(!isinput(line1)||!isinput(line2)){
	fprintf(stderr,"Error input.\n");
	return 1;
}
split(arr1,line1," ");
split(arr2,line2," ");
while (arr1[i]!=NULL){
	a1[i]=atoi(arr1[i]);i++;	
}
while (arr2[j]!=NULL){
	a2[j]=atoi(arr2[j]);j++;	
}
int a=0; 
if(i==j)
while(a<i )
{

printf("%d\n",a1[a]);printf("%d\n",a2[a]);a++;

}

if(i>j)
{
for(a=0;a<j;a++)
printf("%d\n%d\n",a1[a],a2[a]);
for(a=j;a<i;a++)
printf("%d\n",a1[a]);
}

if(i<j)
{
for(a=0;a<i;a++)
printf("%d\n%d\n",a1[a],a2[a]);
for(a=i;a<j;a++)
printf("%d\n",a2[a]);
}


return 0;
}
