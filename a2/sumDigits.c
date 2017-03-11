/*
 * File: sumDigits.c
 * Author:Dong Liang
 * Purpose: Reads in a bunch of numbers and prints out the sum of their digits.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * sumDigits(n) -- Input a positive integer n and returns the number
 * formed by adding its digits together
 */
int sumdigit(int n){
if(n<=9)
    return n;
else
    return (n%10)+sumdigit(n/10);
}

/*
 * main() -- Reads in possitive numbers and prints the sum of their digits.
 */

int main()
{
 int count,num,e;
 e=0;
 while((count=scanf("%d", &num))!=EOF){
	if(count==0){fprintf(stderr,"Error: Non-integer value in input\n" );
	return 1;
	}

	 else if(num<=0){
  	  fprintf(stderr,"Error: input value %d is not positive\n",num);
	  e=1;
	  continue;
	 }
 else
 {
   int r =sumdigit(num);
  printf("%d\n",r);
 }
 }
 return e;

}
