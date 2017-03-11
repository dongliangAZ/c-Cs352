/*
 * File: dna.c
 * Author: Dong Liang
 * Purpose: Get a result of 2 input information about DNA.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 * sdigit(s) -- given a string s and check if there is char in this string not a number. 
 * if all elements in this string are numbers, return 1;
 * otherwise returns 0.
 */
int sdigit(char *s){
int i;
for(i=0;i<strlen(s);i++)
    if(!isdigit(s[i]))
    return 0;
return 1;
}

/*
 * getresult(s,s) -- input 2 strings and they are supposed to have the same lengths. 
 * compare them in some rule to help the main function  get the result;
 *
 */
int getresult(char *s1,char *s2)
{
    int result=0;int i;
    int l=strlen(s1);
    for(i=0;i<l;i++){
        if((int)s1[i]>54&&(int)s2[i]>54)
            result+=1;
        else if((int)s1[i]<=54&&(int)s2[i]<=54)
            result+=1;
        else
            result+=0;
    }
    return result;
}

/*
 * main: Have 2 strings as input. The 2 strings are supposed to be same long.
 * get a result by comparing each elements from them.
 */
int main(){
    int e=0;int i;char c;
    char *input1;
    input1=(char *)malloc(1025 * sizeof(char));
    char *input2;
    input2=(char *)malloc(1025 * sizeof(char));
    scanf("%s",input1);
     scanf("%s",input2);
    if(strlen(input1)!=strlen(input2)){
            fprintf(stderr,"Input strings are not of the same length\n");
            e=1;
    }
    else if(!sdigit(input1)){
        for(i=0;i<strlen(input1);i++)
        {
            if(!isdigit(input1[i]))c=input1[i];
            break;
        }
        fprintf(stderr,"Illegal character in input: %c\n",c);
        e=1;
    }
    else if(!sdigit(input2)){
        for(i=0;i<strlen(input2);i++)
        {
            if(!isdigit(input2[i]))c=input2[i];
            break;
        }
        fprintf(stderr,"Illegal character in input: %c\n",c);
        e=1;
    }
    else{
        printf("%d\n",getresult(input1,input2));
    }
	return e;
}



