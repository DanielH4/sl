#ifndef _SL_ALGO_QSORT
#define _SL_ALGO_QSORT

#include "sl/algorithms/helper2.h"

#include <stdbool.h>

//swaps values at pointers of generic type
//void sl_swap(void* a, void* b);
void sl_pswap(void** a, void** b);

//partitions the array into following element organisation: lesser | pivot | greater/equal
//returns index of pivot
int sl_qsort_partition(void* arr[], int low, int high, int (*compare)(const void*, const void*)) {

	void *pivot = arr[high];
	
	int lesser = low - 1;	//index indicating split between elements: lesser | pivot | greater/equal. Starts at "no index".

	for(int i = low; i < high; i++) {

		//swap smaller elements with element after lesser index
		//all smaller elements moved to the left
		if(compare(arr[i], pivot) == -1) {
			sl_pswap(&arr[i], &arr[++lesser]);
		}
	}

	sl_pswap(&arr[++lesser], &pivot);

	return lesser;																//returns index of new pivot location
}

void sl_qsort(void* arr[], int low, int high, int (*compare)(const void*, const void*)) {

	if(low < high) {

		int p = sl_qsort_partition(arr, low, high, *compare);	//pivot index

		sl_qsort(arr, low, p-1, *compare);						//recursively sort elements lesser than pivot

		sl_qsort(arr, p+1, high, *compare);						//recursively sort elements greater than, or equal to, pivot
	}

	return;
}

#endif //_SL_ALGO_QSORT
