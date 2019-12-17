#ifndef _SL_ALGO_
#define _SL_ALGO_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

/* ### HELPER FUNCTIONS ### */

//swaps values at pointers of generic type
void sl_swap(void* a, void* b, size_t item_size) {
	char buffer[item_size];
	memcpy(buffer, a, item_size);
	memcpy(a, b, item_size);
	memcpy(b, buffer, item_size);
}

//prints an array of generic type
//user supplied pointer to function specifiying how the elements should be printed
void sl_printarr(void* arr, int nitems, size_t item_size, void (*print_type)(const void*)) {
	for(int i = 0; i < nitems; i++) {
		void *element = ((char*)arr) + (i * item_size);
		print_type(element);
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

/* ### /HELPER FUNCTIONS ### */

/* ### QUICKSORT ### */

//partitions the array into following element organisation: lesser | pivot | greater/equal
//returns index of pivot
int sl_qsort_partition(void* arr, int low, int high, size_t item_size, int (*compare)(const void*, const void*)) {

	void *pivot = ((char*)arr) + (high * item_size);
	
	int lesser = low - 1;	//index indicating split between elements: lesser | pivot | greater/equal. Starts at "no index".

	for(int i = low; i < high; i++) {

		void *element = ((char*)arr) + (i * item_size);

		//swap smaller elements with element after lesser index
		//all smaller elements moved to the left
		if(compare(element, pivot) == -1) {
			lesser++;															//found an element lesser than pivot	
			void *element_after_lesser = ((char*)arr) + (lesser * item_size);
			sl_swap(element, element_after_lesser, item_size);
		}
	}

	lesser++;																	//increment to appropriate split index
	void *element_after_lesser = ((char*)arr) + (lesser * item_size);
	sl_swap(element_after_lesser, pivot, item_size);							//swaps pivot to its sorted index

	return lesser;																//returns index of new pivot location
}

void sl_qsort(void* arr, int low, int high, size_t item_size, int (*compare)(const void*, const void*)) {
	if(low < high) {
		int p = sl_qsort_partition(arr, low, high, item_size, *compare);	//pivot index
		sl_qsort(arr, low, p-1, item_size, *compare);						//recursively sort elements lesser than pivot
		sl_qsort(arr, p+1, high, item_size, *compare);						//recursively sort elements greater than, or equal to, pivot
	}

	return;
}

/*	### /QUICKSORT ###	*/

#endif	//_SL_ALGO_
