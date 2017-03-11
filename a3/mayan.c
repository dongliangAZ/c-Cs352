/*
 * File: mayan.c
 * Author:Dong Liang
 * Purpose: Reads in mayanss and return the values
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*
 * isMayan(s) -- returns 1 if s[] is mayans 
 * 0 otherwise.
 */
int isMayan(char s[]){
int result,i;
result =1;
for(i=0;i<strlen(s);i++){
    char c=tolower(s[i]);
    if((int)c<97||(int)c>116)result = 0;
}return result;
}
/*
 * twenty(n) -- returns 20^n 
 */
 
int twenty(int n){
int result =1;
int i;
for(i=n;i>0;i--)
    result=result*20;

    return result;
}
/*
 * dotheMath(s) -- do the math work needed in main()
 */
int dotheMath(char s[]){
int result,i;
result =0 ;
int l=strlen(s);
for(i=0;i<l;i++){
    char c=tolower(s[i]);
    result=result + (((int)c-97)*(twenty(l-i-1)));
}
return result;
}

/*
 * main() -- Reads in the input determine it is a mayan and return the
 *mayan numbers
 */
int main(){
	int e=0; char c;
    char str[8];
	while(scanf("%s",str)!=EOF){
     if(!isMayan(str)){
     	int i =0;
 		while(str[i]!='\0'){
		 	if((int)tolower(str[i])<97||(int)tolower(str[i])>116){
	 			c=tolower(str[i]);
	 			break;
	 		}	
			 i++;
		 }	
	    fprintf(stderr,"Invalid base-20 digit: %c\n",c);
     	e =1 ;
	continue;
     }	
     	else{
	     	printf("%d\n",dotheMath(str));
	     }
     	
	 }

      return e;
}



