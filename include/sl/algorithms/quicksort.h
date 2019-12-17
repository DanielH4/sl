#ifndef _SL_ALGO_QSORT
#define _SL_ALGO_QSORT

#include "sl/algorithms/helper.h"

#include <stdbool.h>

//swaps values at pointers of generic type
void sl_swap(void* a, void* b, size_t item_size);

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

#endif //_SL_ALGO_QSORT
