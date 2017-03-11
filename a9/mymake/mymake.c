/*
 * File: mymake1.c
 * Author: Dong Liang
 * Purpose: In this part it is supposed to get the targets from the files and store them in a tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> 
#include <easy.h>

/*
 *checkfile(node * n)-- check if the file contain this target
 */
void checkfile(node *n){
	node *t=n;
	while(t!=NULL){
	
	if(strcmp(t->str,"@target")==0){
	t=t->next;t=t->next;
	
	if(strcmp(t->str,":")==0){
	t=t->next;	
	}else{
	fprintf(stderr,"Missing :\n");exit(1);
	}
	
	}
	
	else{
	t=t->next;
	}

	}
	
	return;
}


/*
 *check(char *s,node * n)-- check if the file contain this target
 */
void check(char *s,node *n){
	node *t=n;int i=0;
	while(t!=NULL){
	if(strcmp(t->str,s)==0){i=1;break;}
	t=t->next;
	}
	
	if(i==0){
	fprintf(stderr,"the target %s is not in the file\n",s);
	exit(1);
	}
	return;
	}

/*add the vertex nodes from the list*/
void addv(node *n){
	node *t=n;
	while(t!=NULL){

	if(strcmp(t->str,"@target")==0){
	t=t->next;
	adjlist_add_vertex(t->str);
	}
	
	t=t->next;
	}
}
/*add the  enodes from the list*/
void adde(node *n){
	node *t=n;
	while(t!=NULL){

	if(strcmp(t->str,"@target")==0){
	t=t->next;
	char *ver=strdup(t->str);
	
	t=t->next;t=t->next;
	while(strcmp(t->str,"@cmd")!=0){
		adjlist_add_edge (ver,t->str);
		t=t->next;
	}
	free(ver);
	}
	
	t=t->next;
	}


}
/* Get each list the right order*/
void reorder(void){
	vertex_node  *vnode;
	for (vnode = graph_root; vnode != NULL; vnode = vnode->next_vnode) {
        vnode->list_enode=reverse(vnode->list_enode);	
	
     	}

}

/*
 *main(i,char *)-- Get the commans from files and store them
 * in a tree.
 */

int main (int argc, char **argv)
{
	node *list;node *h=NULL;//head for the words in file
	
	//char *line=malloc(512*64*sizeof(char));
	char *word=malloc(64*sizeof(char));
	if(argc!=3){
	fprintf(stderr,"Usage:<filename><target>\n");
	exit(1);
	}
	char *target=strdup(argv[2]);
	FILE *fp=NULL;
	if((fp=fopen(argv[1],"r")) == NULL)
	{
	perror(argv[1]);
	exit(1);
	}
	else{
		while(fscanf(fp,"%s",word)>0){
		
		if(isword(word)==0){
		fprintf(stderr,"Illegle file\n");
		exit(1);
		}

			list=(node *)malloc(sizeof(node));
			list->str=strdup(word);
			list->next=h;h=list;
			}//
	}
	fclose(fp);free(word);
	check(target,list);
	node *rlist=nreverse(list);
	checkfile(rlist);
	addv(rlist);adde(rlist);reorder();checkm(graph_root);
	postt (target);printf("%s\n",target);
	adjlist_free ();freel(rlist);free(target);
	return 0;
}
