#ifndef _SL_DATASTRUCT_
#define _SL_DATASTRUCT_
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

/*	### SINGLY-LINKED LIST ### */

//singly-linked node type
typedef struct sl_node_t {
	void *data;
	struct sl_node_t *next;	
} sl_node_t;

//singly-linked list type
typedef struct {
	int length;
	sl_node_t *head;	
} sl_linkedlist_t;

//returns true if list does not contain any nodes
bool sl_linkedlist_isempty(sl_linkedlist_t* list) {
	if(!list->head)
		return true;	
	return false;
}

bool sl_linkedlist_exists(sl_linkedlist_t* list, void* entry, size_t nbytes) {

	sl_node_t *pnode = list->head;

	while(pnode) {
		
		if(strncmp(entry, pnode->data, nbytes) == 0)
			return true;	//found

		pnode = pnode->next;
	}

	return false;
}

//inserts node in list at specified index
//returns false if index out of range, and no node inserted
bool sl_linkedlist_insert(sl_linkedlist_t* list, void* data, size_t nbytes, int index) {
	if(index > list->length) 
		return false;
	
	sl_node_t *new_node = malloc(sizeof(sl_node_t));
	new_node->data = malloc(nbytes);

	//copy contents of data into new node's data pointer
	memcpy(new_node->data, data, nbytes);

	//empty list
	if(!list->head) {
		new_node->next = NULL;
		list->head = new_node;
		list->length = 1;
	}
	else if(index == 0) {
		new_node->next = list->head;
		list->head = new_node;
		list->length++;
	}
	else {
		sl_node_t *pprev = list->head;	//pointer to previous node

		//traverse list updating ptr until index is met
		for(int i = 1; i != index; i++)
			pprev = pprev->next;

		//insert node
		new_node->next = pprev->next;	
		pprev->next = new_node;

		list->length++;
	}
			
	return true;
}

//add new node as head of list
//calls function sl_linkedlist_insert_node with index=0
void sl_linkedlist_add(sl_linkedlist_t* list, void* data, size_t nbytes) {
	sl_linkedlist_insert(list, data, nbytes, 0);
	return;
}

void sl_linkedlist_node_destroy(sl_node_t* node) {
	free(node);
}

//removes first node with entry value from list
//returns true if entry existed in list and was removed, otherwise returns false
bool sl_linkedlist_remove(sl_linkedlist_t* list, void* entry, bool (*is_equal)(const void*, const void*)) {
	sl_node_t **indirect = &list->head;	

	int i = 0;
	while(i < list->length && !is_equal((*indirect)->data, entry)) {
		indirect = &(*indirect)->next;
		i++;
	}

	if(i == list->length)
		return false;
	else {
		sl_node_t *temp = *indirect;
		*indirect = (*indirect)->next;	
		free(temp);
		list->length--;
	}

	return true;
}

//removes index from list if not out of range
bool sl_linkedlist_remove_index(sl_linkedlist_t* list, int index) {

	//out of range
	if(index >= list->length || index < 0)
		return false;
	
	sl_node_t **indirect = &list->head;

	for(int i = 0; i != index; i++)
		indirect = &(*indirect)->next;

	sl_node_t *temp = *indirect;
	*indirect = (*indirect)->next;
	free(temp);
	list->length--;

	return true;
}

void sl_linkedlist_destroy(sl_linkedlist_t* list) {
	sl_node_t *pnode = list->head;
	while(pnode) {
		sl_node_t *temp = pnode;
		pnode = pnode->next;
		free(temp);	
		list->length--;
	}
}

void sl_linkedlist_print(sl_linkedlist_t* list, void (*print_func)(const void* data)) {
	sl_node_t *pnode = list->head;
	while(pnode) {
		print_func(pnode->data);
		pnode = pnode->next;	
	}
	printf("\n");
}

/* ### /SINGLY-LINKED LIST ### */

#endif	//_SL_DATASTRUCT_
