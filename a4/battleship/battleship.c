/*
 * File: battleship.c
 * Author:Dong Liang
 * Purpose: A 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * setBoard(int[][]) -- use a 2D array to set the gameboard
 */	

void setBoard(int board[][10])
{
    int r, c;
        for(r=0 ; r < 10 ; r++ )
            for(c=0 ; c < 10 ; c++ )
		board[r][c]=0;
}

/*
 * checkship(char,int,int,int,int) -- check if the input ship is 
 *illigle. Return 1;
 *otherwise return 0;
 */	
int checkship(char c,int x1,int y1,int x2,int y2){
	int o=y1-y2;int p=x1-x2;
	if(c=='A'){
		if((x1=x2)&&(o=4))return 1;
		if((x1=x2)&&(o=-4))return 1;
		if((y1=y2)&&(p=-4))return 1;
		if((y1=y2)&&(p=4))return 1;
	}
	else if(c=='B'){
		if((x1=x2)&&(o=3))return 1;
		if((x1=x2)&&(o=-3))return 1;
		if((y1=y2)&&(p=-3))return 1;
		if((y1=y2)&&(p=3))return 1;
	}
	else if(c=='D'){
		if((x1=x2)&&(o=2))return 1;
		if((x1=x2)&&(o=-2))return 1;
		if((y1=y2)&&(p=-2))return 1;
		if((y1=y2)&&(p=2))return 1;	
	}
	else if(c=='S'){
		if((x1=x2)&&(o=2))return 1;
		if((x1=x2)&&(o=-2))return 1;
		if((y1=y2)&&(p=-2))return 1;
		if((y1=y2)&&(p=2))return 1;
	}	
	else if(c=='P'){
	if((x1=x2)&&(o=1))return 1;
		if((x1=x2)&&(o=-1))return 1;
		if((y1=y2)&&(p=-1))return 1;
		if((y1=y2)&&(p=1))return 1;
	}
		return 0;	
 }


/*
 * checktype(int ,int ,int ,int ,int ) -- check if the ships are formed 
 *the size correctly.
 *return 1 if it is;otherwise 0.
 */		
int checktype(int a,int b,int d,int p,int s){
	int sum=a+b+d+p+s;
	if(a!=1||b!=1||d!=1||p!=1||s!=1)return 0;
	if(sum!=5)return 0;
	return 1;
}
/*
 * isguess(int,int) -- check if the 2nd player's guess is legal 
 *return 1 if it is;otherwise 0.
 */	
int isguess(int m,int n){
	if(m>=10||n>=10)return 0;
	return 1;
}


/*
 * putship(int,int,int,int,int[][]) -- put the ships on the board.
 */	
void putship(int x1,int y1,int x2,int y2,int board[][10]){
		int t;
		if(x1==x2)
		for(t=y1;t<=y2;t++)
			board[t][x1]=1;
		if(y1==y2)
		for(t=x1;t<=x2;t++)
			board[y1][t]=1;	
			x1=0;x2=0;y1=0;y2=0; 
}


/*
 * hitmiss(int,int,int[][]) -- return 1 if the guess hit a ship.
 *otherwise, return 0;
 */	
int hitmiss(int x,int y,int board[][10]){
if(board[y][x]==1){
	return 1;
}
else{
	return 0;
}	
}

int main(){
	
	int end =17;
	int e=0;int error=0;int board[10][10];int i=0;int guessx,guessy,j;
	int x1,y1,x2,y2;
	int a=0;int b=0;int d=0;int p=0;int s=0;
	char c;int cscanf=0;
	setBoard(board);	

	while(i!=5){
	cscanf+=scanf(" %c%d%d%d%d ", &c,&x1,&y1,&x2,&y2);
	switch(c){
		case 'A':a+=1;break;
		case 'B':b+=1;break;
		case 'D':d+=1;break;
		case 'P':p+=1;break;
		case 'S':s+=1;break;
	}
	if(!checkship(c,x1,y1,x2,y2)){
		e=1;
		fprintf(stderr,"Iliigle input ships\n");
		return 1;
	}
	else{
		putship(x1,y1,x2,y2,board);
	}i++;
	}
	
	if(e==1||!checktype(a,b,d,p,s)){
		fprintf(stderr,"Iliigle input ships\n");
		return 1;
	}
			while((j=scanf(" %d%d", &guessx,&guessy))!=EOF){
			if(j==0){
			fprintf(stderr,"Iliigle guess\n");return 1;
			}
			else if(!isguess(guessx,guessy)){
			error=1;
			fprintf(stderr,"Iliigle guess\n");
			continue;
			}
			else{
			if(end==0){
			printf("all ships sunk: game over\n");
			break;
			}
			else if(end&&hitmiss(guessx,guessy,board))
			{
			printf("hit\n");end--;board[guessy][guessx]=0;continue;
			}
			else if(end&&!hitmiss(guessx,guessy,board)){	
			printf("miss\n");
			continue;
			}
			else{
				return 1;
			}	
			}
		}	
	
	
 return error;

}





