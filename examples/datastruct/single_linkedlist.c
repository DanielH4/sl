#include <sl_datastruct.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printlist(sl_linkedlist_t* list) {
	sl_node_t *pnode = list->head;
	while(pnode != NULL) {
		printf("%i ", *(int*)pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
}

bool is_equal_int(const void* x1, const void* x2) {
	if(*(int*)x1 == *(int*)x2) {
		return true;
	}
	
	return false;
}

void printlist_func(const void* data) {
	printf("%i ", *(int*)data);
}

int main() {

	sl_linkedlist_t list = {};
	printf("List empty: %d\n", sl_linkedlist_isempty(&list));
	int alen = 3;
	int arr[3] = {10, 20, 30};
	printf("Filling list with values: ");
	for(int i = 0; i < alen; i++) {
		printf("%i ", arr[i]);
	}
	printf("\n");
	for(int i = 0; i < 3; i++) {
		sl_linkedlist_add(&list, &arr[i], sizeof(int));
	}
	printf("List empty: %d\n", sl_linkedlist_isempty(&list));
	printf("List length: %i\n", list.length);
	printlist(&list);
	printf("\n");

	int val = 70;
	printf("Inserting %i into index 0...\n", val);
	sl_linkedlist_insert(&list, &val, sizeof(int), 0);		//optional bool return value if index is out of range
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");

	val = 90;
	printf("Inserting %i into last index...\n", val);
	sl_linkedlist_insert(&list, &val, sizeof(int), list.length);		//optional bool return value if index is out of range
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");

	val = 90;
	printf("Does %i exist in list? %i\n", val, sl_linkedlist_exists(&list, &val, sizeof(int)));

	val = 40;
	printf("Does %i exist in list? %i\n", val, sl_linkedlist_exists(&list, &val, sizeof(int)));
	printf("\n");

	/*
	val = 70;
	printf("Remove %i from list\n", val);
	sl_linkedlist_remove(&list, &val, *is_equal_int);
	printlist(&list);
	printf("List length: %i\n", list.length);

	printf("\n");

	val = 90;
	printf("Remove %i from list\n", val);
	sl_linkedlist_remove(&list, &val, *is_equal_int);
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");

	val = 90;
	printf("Remove %i from list\n", val);
	sl_linkedlist_remove(&list, &val, *is_equal_int);
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");

	printf("Remove first element\n");
	sl_linkedlist_remove_index(&list, 0);
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");
	
	printf("Remove last element\n");
	sl_linkedlist_remove_index(&list, list.length-1);
	printlist(&list);
	printf("List length: %i\n", list.length);
	printf("\n");
	*/

	printf("Print linked list using print func.\n");
	sl_linkedlist_print(&list, *printlist_func);
	sl_linkedlist_destroy(&list);

	return 0;
}
