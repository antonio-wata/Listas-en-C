#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <assert.h>


struct node_struct * newNode(int v){
	struct node_struct *n = (struct node_struct*) malloc(sizeof(struct node_struct));
	assert(n != NULL);
	(*n).value = v;
	n->value = v;
	n->next = NULL;
	return n;
}


void deleteNode(struct node_struct *n){
	free(n);
}


void print_list(struct node_struct* l){
	printf("[");
	for(; l != NULL; l= l->next){
		printf("%d%c ", l->value, l->next != NULL ? ',': ']');
	}
}


int len_inter(struct node_struct* node){
	int contador = 0;
	while(node != NULL){
		contador ++;
		node = node->next;
	}
	return contador;
}


int len_rec(struct node_struct* node){
	if(node == NULL)
		return 0;
	if(node->next == NULL)
		return 1;
	else
		return 1+len_rec(node->next);
}


int max(struct node_struct * nodo){
	int max_n = nodo->value;
	while(nodo != NULL){
		if(nodo->value > max_n)
			max_n = nodo->value;
		nodo = nodo->next;
	}
	return max_n;
}


struct node_struct * inversa(struct node_struct* nodo){
	struct node_struct* prev = NULL;
	struct node_struct* temp = NULL;
	if(nodo == NULL)
		return NULL;
	while(nodo != NULL){
		prev = newNode(nodo->value);
		prev->next = temp;
		temp = prev;
		nodo = nodo->next;
	}
	return temp;
}