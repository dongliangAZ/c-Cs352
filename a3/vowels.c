/*
 * File: vowels.c
 * Author:Dong Liang
 * Purpose: Reads in words and determine whether or not it is
 * vowels and they are in order.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * isword(s) -- returns 1 if s[] is a word 
 * 0 otherwise.
 */	
    int isword(char s[]){
    int i;
    int result=1;
    for(i=0;i<strlen(s);i++)
    if(!isalpha(s[i]))
         result=0;
    return result;

}

/*
 * hasvowel(s) -- returns 1 if s[] has vowels 
 * 0 otherwise.
 */
int hasvowel(char s[]){
	int result=0;
	int i;
	char c;
	for(i=0;i<strlen(s);i++){
	c=tolower(s[i]);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
	result = 1;
}	return result;
} 

/*
 * isorder(s) -- returns 1 if the vowels in s[]
 * is in order.0 otherwise.
 * if there is no vowels in s[], it returns 1.
 */
int isorder(char s[]){
	char vowels[65]; 
	int i;int j=0;
	for(i=0;i<strlen(s);i++){
 	    char c=tolower(s[i]);
 		if((int)c==97||(int)c==101||(int)c==105||(int)c==111||(int)c==117)
   		{
		   vowels[j]=c;
		   j++;
		   }
                  }
	for(i=0;i<j-1;i++)
	if((int)vowels[i]>(int)vowels[i+1])return 0;
	return 1;
}
/*
 *main() -- Reads in the input and for each word use function
 *to determine if there are vowels.
 *No, print out 1;
 *Else, check if all the vowels are in order.
 *return 1 if they are.
 *0 otherwise.
 */
int main(){
   int e=0;
   char str[64+1];
        while((scanf("%s",str))!=EOF){
        
	if(!isword(str)){
        fprintf( stderr,"Error: non-letter character in word %s\n",str);
        e=1;
        continue;
	}
		
	else{
                printf("%d\n",isorder(str));          
    }

        }

            return e;
}



