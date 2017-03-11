/*author: Dong Liang
 *  famrel.c
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> 
#include "easy.h"

tr * tree;tr *root=NULL;

/*
 *main(i,char *)-- The main(n,arg)
 */

int main (int argc, char **argv)
{	int e=0;
	if(argc!=2){
	fprintf(stderr,"Usage:<filename>\n");
	exit(1);
	}
	opfile(argv[1]);//open a file. And read it in a tree.

	char *s1 = malloc(65*sizeof(char));
	 char *s2 = malloc(65*sizeof(char));
	char *s3 = malloc(65*sizeof(char));

	char line[1024]={0};

	


	while((fgets(line,1024,stdin))>0){
	
	int sta=sscanf(line,"%s%s%s",s1,s2,s3);
	if(sta!=2){
		printf("Too few or too many argments\n");e=1;
	}
	else if(!contain(s1,tree)){
		printf("The word %s is not in the file\n",s1);e=1;
	}
	else if(!contain(s2,tree)){
		printf("The word %s is not in the file\n",s2);e=1;
	}
	else{
	find(s1,s2,tree);
	}
	
	
	}
	
	
	


	
	ftree(tree);free(s1);free(s2);free(s3);
	return e;
}



/*
 *readf(str)-- read a file to the tree
 */
void readf(FILE *fp){
   char *line=malloc(1024*sizeof(char));
	char *s1 = malloc(65*sizeof(char)); char *s2 = malloc(65*sizeof(char));
	
	do{
	fscanf(fp,"%s%s",s1,s2);
	if(strcmp(s1,s2)==0){
	fprintf(stderr,"One object cannot be its own ancestor\n");
	exit(1);
	}

  	if(!contain(s1,tree)){  
  tree=(tr *)malloc(sizeof(tr));
  tree->name=strdup(s1); tree->par=NULL;
  tree->next=root;root=tree;
	}
	
	if(!contain(s2,tree)){
  tree=(tr *)malloc(sizeof(tr));
  tree->name=strdup(s2);  tree->par=NULL;
  tree->next=root;root=tree;

	}

	parent(s1,s2,tree);

	
	}while((fgets(line,1024,fp))>0);
	free(s1);free(s2);free(line);
}

/*
 *opfile(str)-- open a file and the name from the command
 */
void opfile(char *s){
	FILE *fp=NULL;
	if((fp=fopen(s,"r")) == NULL)
	{
	perror(s);
	exit(1);
	}
	else{
	readf(fp);}
	fclose(fp);
	return;
}



