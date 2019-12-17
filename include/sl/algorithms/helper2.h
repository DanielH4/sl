#ifndef _SL_ALGO_HELPER_
#define _SL_ALGO_HELPER_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

//swaps values at pointers of generic type
void sl_pswap(void** a, void** b) {
	void *temp = *a;
	*a = *b;
	*b = temp;
}

void sl_swap(void* a, void* b, size_t item_size) {
	char buffer[item_size];
	memcpy(buffer, a, item_size);
	memcpy(a, b, item_size);
	memcpy(b, buffer, item_size);
}

//prints an array of generic type
//user supplied pointer to function specifiying how the elements should be printed
void sl_printarr(void* arr[], int nitems, size_t item_size, void (*print_type)(const void*)) {
	for(int i = 0; i < nitems; i++) {
		print_type(arr[i]);
	}
	printf("\n");
}

//takes an array of generic type and returns true if sorted
bool sl_is_sorted(void* arr, int nitems, size_t item_size, int (*compare)(const void*, const void*)) {

	void *last_element = arr;

	for(int i = 1; i < nitems; i++) {

		void *curr_element = ((char*)arr) + (i * item_size);

		if(compare(last_element, curr_element) == 1)
			return false;						
		else
			last_element = curr_element;
	}

	return true;
}

#endif //_SL_ALGO_HELPER_
