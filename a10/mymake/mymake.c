/*author: Dong Liang
 *  mymake2
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

/*add vnodes from the list*/
void addv(node *n){
	node *t=n;node *p;
	while(t!=NULL){

	if(strcmp(t->str,"@target")==0){
	t=t->next;p=t;while(strcmp(p->str,"@cmd")!=0)p=p->next;p=p->next;
	adjlist_add_vertex(t->str,p->str);
	}
	
	t=t->next;
	}
}
/*add enodes from the list*/
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


/* Get commands*/
void getcm(node *n){
	node *t=n;char *s;char *c=malloc(512*sizeof(char));
	while(t!=NULL){
	if(strcmp(t->str,"@target")==0){
	t=t->next;s=strdup(t->str);
	while(strcmp(t->str,"@cmd")!=0)
		t=t->next;	
	
	t=t->next;t=t->next;
	while(strcmp(t->str,"@target")!=0){
		strcat(c,t->str);strcat(c," ");	
	}
	tc=(tcmd *)malloc(sizeof(tcmd));
	tc->target=strdup(s);base->cmd=strdup(c);
	tc->next=base;base=tc;free(s);c=NULL;
	}
	
	
	t=t->next;
	}
	free(c);
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
	checkfile(rlist);//getcm(rlist);
	addv(rlist);adde(rlist);reorder();checkm(graph_root);
	postt(target,rlist);
	adjlist_free ();freel(rlist);free(target);
	return 0;
}

