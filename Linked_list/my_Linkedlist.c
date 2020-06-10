#include "my_Linkedlist.h"

static size_t node_size = sizeof(node_t);

node_t* create_node_malloc( int my_var, int my_key) {
	node_t* new_node = (node_t*)malloc(node_size);
	if (new_node == NULL) {
		printf("***memory allocatoin is failed. terminate program***\n input anykey : ");
		getchar();
		exit(1);
	}
	new_node->var = my_var;
	new_node->key = my_key;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

void print_nodes(node_t* head) {
	if (head == NULL) {
		printf("***head_node is NULL. ***\n");
		return ;
	}
	node_t* np = head;
	printf("val : %d, key : %d\n", np->var, np->key);
	if (np->next == NULL) {
		return;
	}
	print_nodes(np->next);
}

node_t* insert_next(node_t* flag_node ,int my_var, int my_key) {
	if (flag_node == NULL) {
		printf("***flag node is NULL. default return NULL.***\n");
		return NULL;
	}
	node_t* np = flag_node->next;
	node_t* new_node = (node_t*)malloc(node_size);
	if (new_node == NULL) {
		printf("***memory allocatoin is failed. terminate program***\n input anykey : ");
		getchar();
		exit(1);
	}

	if(np !=NULL){
		np->prev = new_node;
		new_node->next = np;
	}
	else {
		new_node->next = NULL;
	}
	
	new_node->prev = flag_node;
	flag_node->next = new_node;
	

	new_node->var = my_var;
	new_node->key = my_key;
	

	return new_node;
}

node_t* insert_prev(node_t* flag_node, int my_var, int my_key){
	node_t* pp = flag_node->prev;
	node_t* new_node = (node_t*)malloc(node_size);
	if (new_node == NULL) {
		printf("***memory allocatoin is failed. terminate program***\n input anykey : ");
		getchar();
		exit(1);
	}

	if (pp != NULL) {
		printf("***Don't touch head***\n input anykey : ");
		getchar();
		return NULL;
	}
	pp->next = new_node;
	new_node->prev = pp;

	new_node->next = flag_node;
	flag_node->prev = new_node;

	new_node->var = my_var;
	new_node->key = my_key;

	return new_node;
}

void delete_node(node_t* target_node) {
	if (target_node == NULL) {
		printf("***target_node is NULL***\n");
		return;
	}
	node_t* pp = target_node->prev;
	node_t* np = target_node->next;

	pp->next = np;
	np->prev = pp;

	target_node->prev = NULL;
	target_node->next = NULL;

	free(target_node);
	target_node = NULL;

	return;
}

void destroy(node_t* head) {
	if (head == NULL) {
		printf("***head is NULL***\n");
		return;
	}
	node_t* np= head->next;
	node_t* pp = head -> prev;
	if (np->next != NULL) {
		destroy(np);
	} 
	free(np);
	np = NULL;
	head->next = NULL;
	if (pp == NULL) {
		goto LAST;
	}
	else {
		return;
	}
LAST:
	free(head);
	head = NULL;

	return;
}

