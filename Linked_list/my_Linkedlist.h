#ifndef MY_LINKEDLIST_H
#define MY_LINKEDLIST_H

typedef struct node{
	int var; 
	int key;
	struct node* next;
	struct node* prev;
}node_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#include <stdio.h>
#include <stdlib.h>



node_t* create_node_malloc(int my_var, int my_key);
node_t* insert_next(struct node* , int my_var, int my_key);
node_t* insert_prev(struct node* , int my_var, int my_key);
void delete_node(struct node* );
void print_nodes(struct node* );
void destroy(struct node*);





#endif


