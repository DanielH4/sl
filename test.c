#include "sl/algorithms/quicksort2.h"

#include <stdio.h>
#include <string.h>

typedef struct node_t {
	void* data;
	const char* type_name;
	struct node_t* next;
} node_t;

node_t* create_node(void* data, const char* type_name, size_t nbytes) {
	node_t *pnode = malloc(sizeof(node_t));
	pnode->data = malloc(sizeof(nbytes));
	pnode->type_name = malloc(strlen(type_name));

	memcpy(pnode->data, data, nbytes);
	strcpy(pnode->type_name, type_name);
	pnode->next = NULL;

	return pnode;
}

int compare_nodes(const void* node1, const void* node2) {
	node_t *pnode1 = (node_t*)node1;
	node_t *pnode2 = (node_t*)node2;

	if(strcmp(pnode1->type_name, pnode2->type_name) == 0) {
	
		int x1 = *(int*)pnode1->data;
		int x2 = *(int*)pnode2->data;
	
		printf("Comparing: %i %i", x1, x2);

		if(x1 < x2)
			return -1;
		if(x1 > x2)
			return 1;

		return 0;			
	}
	else {
		
		if(strcmp(pnode1->type_name, "char") == 0)
			return -1;

		return 1;
	}
}

void print_nodes(const node_t* head) {

	node_t *pnode = head;

	while(pnode) {

		if(strcmp(pnode->type_name, "int") == 0)
			printf("%i ", *(int*)pnode->data);
		else
			printf("%c ", *(char*)pnode->data);

		pnode = pnode->next;		
	}
	printf("\n");
}


int main() {
	
	int arr_size = 6;
	void* arr[arr_size];
	
	for(int i = 0; i < arr_size/2; i++) {
		int *x = malloc(sizeof(int));
		*x = arr_size - i;
		arr[i] = x;
	}

	for(int i = arr_size/2; i < arr_size; i++) {
		char *c = malloc(sizeof(char));
		*c = (char)(102-i);
		arr[i] = c;
	}

	node_t *head = create_node(arr[0], "int", sizeof(int));
	head->next = create_node(arr[5], "char", sizeof(char));

	void* nodes[2];
	nodes[0] = head;
	nodes[1] = head->next;

	print_nodes(head);
	printf("Location nodes[0]: %p\nLocation nodes[1]: %p\n", nodes[0], nodes[1]);

	sl_qsort(nodes, 0, 1, *compare_nodes);

	print_nodes(head);
	printf("Location nodes[0]: %p\nLocation nodes[1]: %p\n", nodes[0], nodes[1]);

	node_t *pnode = (node_t*)nodes[0];
	printf("nodes[0]: data=%c next=%p\n", *(char*)pnode->data, pnode->next);

	pnode = (node_t*)nodes[1];
	printf("nodes[0]: data=%c next=%p\n", *(char*)pnode->data, pnode->next);

}
