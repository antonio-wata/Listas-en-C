#include <stdlib.h>
#include <stdio.h>
#include "list.h"


int main(void){
	int i;
	struct node_struct * l = NULL;
	for(i = 0; i < 20; i++){
		struct node_struct * nuevo ;
		nuevo = newNode(i);
		nuevo->next = l;
		l = nuevo;
	}
	print_list(l);
	printf("\n");
	print_list(inversa(l));
	printf("\n");
	printf("%d\n", len_inter(l));
	printf("%d\n", len_rec(l));
	printf("%d\n", max(l));
	struct node_struct * next;

	while(l != NULL){
		next = l->next;
		free(l);
		l = next;
	}

	return 0;
}
