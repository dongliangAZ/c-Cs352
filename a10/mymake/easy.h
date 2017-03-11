/*some head file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> 

typedef struct node{
char *str;
struct node * next;

}node;

typedef struct tcmd{
char *target;char *cmd;
struct tcmd * next;
}tcmd;

tcmd *base=NULL;
tcmd *tc;
/*
 * plist(*node)--print out a linked list
 */
void plist(node *n){
	node *t=n;
	
	while(t!=NULL){
	printf("%s\n",t->str);
	t=t->next;
	}
	
	return;
}

/*freel(node) --free a linked list*/
void freel(node *h){
	node *t=h;node *t1=NULL;
	 while(t!=NULL){
	t1=t->next;
	free(t->str);free(t);
	t=t1;
	}
}



/*
 * turn(s)--turn all the available chars to whitespace
 */
void turn(char *s){
	int i;
	for(i=0;i<strlen(s);i++)
	if(!isspace(s[i]))s[i] = ' ';
	return;
}

/*
 * isword(s)--return 1 if input string is a "word"
 * return 0 if it is not.
 */
int isword(char *aword){
	int i;
	for(i=0;i<strlen(aword);i++)
		if(!isgraph(aword[i]))return 0;

	if(aword[0]=='@'){
	if((strcmp(aword,"@target")==0)||(strcmp(aword,"@cmd")==0))return 1;
	else return 0;
	}
	return 1;

}

 typedef struct vertex_node_ {
     char *val; char *cmd;                       /* Holds a string and a cmd. */
     int v;
     struct edge_node_   *list_enode; /* This is a linked list for all connected edges. */
     struct vertex_node_ *next_vnode; /* This is the vertical linked list for all vertices. */
 } vertex_node;

 typedef struct edge_node_ {
     int v;
     char *val; 	 						
     struct edge_node_ *next_enode;   /* This is a linked list. */
 } edge_node;

 /* Root of the graph */
 vertex_node *graph_root = NULL;

 /* Add a Vertex to an Adjacency List */
 void adjlist_add_vertex (char *data,char *cm) {
     vertex_node *new_vnode, *vnode;

     vnode = graph_root;
     while (vnode && vnode->next_vnode) {
         /* Check, if the value already exists. */
         if (strcmp(vnode->val , data)==0) {
             
             return;
         }
         vnode = vnode->next_vnode;
     }

    
     new_vnode = (vertex_node *)malloc(sizeof(vertex_node));
	 
     if (!new_vnode) {
         return;
     }
     new_vnode->val = strdup(data);new_vnode->v=0; new_vnode->cmd = strdup(cm);
     new_vnode->list_enode = NULL;
     new_vnode->next_vnode = NULL;

     if (!graph_root) {
         graph_root = new_vnode;
         return;
     }
     vnode->next_vnode = new_vnode;
 }

 /* 
  * First, find the vnode for both vertices in the edge. We will 
  * add an enode to both of these vnodes.
  */
 void adjlist_add_edge (char *vertexA, char *vertexB) {
     vertex_node  *vnode;
	edge_node  *new_enode;
    
     for (vnode = graph_root; vnode != NULL; vnode = vnode->next_vnode) {
         if (strcmp(vnode->val , vertexA)==0) {
             break;
         }
     }
         
   	 
   	 if(vnode->list_enode==NULL){
   	 	new_enode = (edge_node *)malloc(sizeof(edge_node));
		new_enode->val=strdup(vertexB);
		new_enode->v=0;
   	 	new_enode->next_enode=vnode->list_enode;
		vnode->list_enode=new_enode;
   	 	
   	 }
     else{
     	edge_node *t=vnode->list_enode->next_enode;
		while(t!=NULL){
		if (strcmp(t->val , vertexB)==0) {
             break;
         }
			t=t->next_enode;
		}	
	new_enode = (edge_node *)malloc(sizeof(edge_node));
    	 new_enode->val = strdup(vertexB);new_enode->v=0;
	new_enode->next_enode=vnode->list_enode;
	vnode->list_enode=new_enode;
   	 
	}
     
 
 }




 /* Free the Adjacency List */
 void adjlist_free () {
     vertex_node *vnode = NULL; vertex_node *vnode2 = NULL;    edge_node *enode = NULL;edge_node *enode2 = NULL;
     vnode = graph_root;
     /* Walk the list of vertex nodes. */
     while (vnode) { 
         /* For each vertex node, walk the list of edge nodes. */
        vnode2=vnode->next_vnode;free(vnode->val); free(vnode->cmd);
	enode = vnode->list_enode;
         while (enode) {
             enode2=enode->next_enode;free(enode->val);free(enode);
             enode = enode2;
             
         }
         free(vnode);
         vnode = vnode2;
         
     }
     graph_root = NULL;
 }

/* Print the Adjacency List */
 void adjlist_print () {
     vertex_node *vnode = NULL;
     edge_node *enode = NULL;

     
     if (!graph_root) {
         printf(" Nothing to print. Return\n"); 
         return;
     }

     for (vnode = graph_root; vnode != NULL; vnode = vnode->next_vnode) {
         printf("\n\t%s ", vnode->val);
         for (enode =vnode->list_enode	 ; enode != NULL; enode = enode->next_enode) {
             printf(" %s", enode->val); 
         }
     }
     printf("\n");
 }
/*
 *reverse(node * n)-- reverse a linked list then return a new node hold it
 */
node* nreverse(node* root) {
  node* new_root = 0;
  while (root) {
    node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

/*
 *reverse(node * n)-- reverse a linked list then return a new node hold it
 */
edge_node* reverse(edge_node* root) {
  edge_node* new_root = 0;
  while (root) {
    edge_node* next = root->next_enode;
    root->next_enode = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}
/*
 *int visitcheck(s)
 */
int visitcheck(char *s){
vertex_node *temp=graph_root;
while(temp!=NULL){
	edge_node *t=temp->list_enode;
	while(t!=NULL){
	if((t->v)&&(strcmp(s,t->val)==0))return 1;
	t=t->next_enode;
	}
	temp=temp->next_vnode;
	}return 0;
}

/*dadada*/
void unixx(char *s){
	printf("%s\n",s);
	system(s);
}


/*gdfgf*/
void sis(char *s,node *n){
	node *t=n;
	while(t!=NULL&&strcmp(t->str,s)!=0)
	t=t->next;
	while(t!=NULL&&strcmp(t->str,"@cmd")!=0)
	t=t->next;
	unixx(t->next->str);
}




/*
 *void postt(v,s)
 */
void postt(char *target, node *n){
	vertex_node *temp=graph_root;int i=0;
	while(temp!=NULL){
	if(strcmp(temp->val,target)==0&&!(temp->v)){i=1;break;}
	temp=temp->next_vnode;
	}
	if(i){
	temp->v=1;//dotmc();
	edge_node *t=temp->list_enode;
	while(t!=NULL){
	if(t->v||visitcheck(t->val)){
	
	}else{
	t->v=1;postt(t->val,n);
	sis(t->val,n);
	}
	t=t->next_enode;
	}}}
/* check motipule targets*/
void checkm(vertex_node *vn){
	vertex_node *t=vn;vertex_node *t1;int i;
	while(t!=NULL){
	t1=vn;i=0;
	while(t1!=NULL){
	if(strcmp(t->val,t1->val)==0)i++;
	t1=t1->next_vnode;
	}if(i>1)
	{fprintf(stderr,"cant add more\n");exit(1);}
	t=t->next_vnode;
	}
}
