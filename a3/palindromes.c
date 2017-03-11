/*
 * File: palindromes.c
 * Author:Dong Liang
 * Purpose: Reads in words and prints out if it is a palindrome.
 * If it is prints out 1, or 0 for not.
 */
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
/*
 * isSymmetry(str[]) -- returns 1 if the inputword is symmetry. 
 * 0 otherwise. 
 */
int isSymmetry(char str[]){
 int length=strlen(str);int result=1;
 for (int i=0;i<length/2;i++)
 {
  if(tolower(str[i])!=tolower(str[length-i-1]))result=0;
 }
 return result;
}

/*
 * main() -- Reads in the input word and check out if it is palindrome by use
 * function.
 */


int main(){
	char str[64+1];
	int statue;
	while((statue=scanf("%s",str))!=EOF){
		if(statue ==0)printf("ERROR!");
		
		printf("%d\n",isSymmetry(str));
	}
	return 0;
}


