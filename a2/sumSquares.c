/*
 * File: sumSquares.c
 * Author:Dong Liang
 * Purpose: Reads in 2 non-negative numbers and print out the numbers between 
 * them which can be written as 2 squares of another 2 numbers.
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * issumofsquares(n) -- returns 1 if n is a sum of positive squares, 
 * 0 otherwise. n should be possitive.
 */

int issumofsquares(int n){
	int result =0;
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i*i+j*j==n)
	result=1;
	return result;
}

/*
 * main() -- Reads in two numbers and calls funtions to print the
 * numbers that are sums of two squares.
 */
int main()
{
int firstinput;
int a=scanf("%d",&firstinput);
int secondinput;
int b=scanf("%d",&secondinput);

if(a==0||b==0){
fprintf(stderr,"Error reading input\n");
return 1;
}

else if(firstinput<=0||secondinput<=0){
    fprintf(stderr,"Error: Non-positve number entered.\n");
       return 1;
 }
else if(firstinput>secondinput)
    {
    }
else{
 	int x;
	 for(x=firstinput;x<=secondinput;x++){
		if(issumofsquares(x)==1)
		printf("%d\n",x);
		else;

}
}

return 0;
}
