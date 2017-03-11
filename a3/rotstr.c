/*
 * File: rotstr.c
 * Author:Dong Liang
 * Purpose: Reads in a number first and rots the strings inputed later
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * isalphaandnumeric(s) -- returns 1 if s[] is a word or number.
 * 0 otherwise.
 */	
int isalphaandnumeric(char s[]){
	int i;
	for(i=0;i<strlen(s);i++)
	if(!isalnum(s[i]))return 0;
	return 1;
}

/*
 * changeit(n,c) -- return a char that changed by the inputed one
 * with the number.
 */	

char changeit(int n, char c){
if((int)c>=97&&(int)c<=122){
	if(((int)c+n)<97)return (char)((int)c+n+26);
	if(((int)c+n)>122)return (char)((int)c+n-26);
	return (char)((int)c+n);
}
if((int)c>=65&&(int)c<=90){
	if(((int)c+n)<65)return (char)((int)c+n+26);
	if(((int)c+n)>90)return (char)((int)c+n-26);
	return (char)((int)c+n);
}
if((int)c>=48&&(int)c<=57){
	return c;
}
else{
	return '\0';
}
}

/*
 * doit(n,s) -- rost the sting by the number.
 */	

void doit(int n,char input[]){
	int change=n%26;
	int i;
	for(i=0;i<strlen(input);i++)
		{
		char temp=changeit(change,input[i]);
		input[i]=temp;
		temp='\0';
		}
}

/*
 * main() -- Reads a numer then some strings from the input and 
 *do the rost work.
 */
int main(){
		int e=0;
		int firstinput,count;char input[65];
		count=scanf("%d",&firstinput);

		switch(count){
		
		case 0:
		fprintf(stderr,"ERROR: first input must be an integer\n");
		e=1;break;
	
		case 1:
		while(scanf("%s",input)!=EOF){
	 		if(!isalphaandnumeric(input)){
	 			fprintf(stderr, "ERROR: string is not alphanumeric: %s",input);
	 			e=1;
	 			continue;
		 	}else{
	 			doit(firstinput,input);
	 			printf("%s\n",input);
	 		}
	 	}
		break;
		
			
		}
	
 return e;

}




