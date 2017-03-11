/*
 * File: isFib.c
 * Author:Dong Liang   
 * Purpose: Reads in non-negative numbers and prints out whether or not it is a
 * fibbonoci number.
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * main() -- Reads in the input and determine if the numbers are fib.
 */
int main()
{
int a,b,c,num,count,e;e=0;
while((count=scanf("%d", &num))!=EOF){
if(count==0){
fprintf(stderr,"Error: input is not a number\n" );
return 1;
} 

else if(num<=0){
    fprintf(stderr,"Error: input value %d is not positive\n",num);
    e=1;
 }
else if(num==1){
   printf("%d is fib\n",num);
 }
 else
 {
   a=0;
   b=1;
   c=a+b;
while(c<num)
   {
     a=b;
     b=c;
     c=a+b;
   }
   if(c==num)
     printf("%d is fib\n",num);
   else
     printf("%d is not fib\n",num);
 }
 }
 return e;
}

