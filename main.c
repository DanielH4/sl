#include "sl/algorithms/quicksort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_int(const void* a, const void* b) {

	//cast to int pointers
	int *aa = (int*)a;
	int *bb = (int*)b;

	if(*aa < *bb)
		return -1;
	if(*aa > *bb)
		return 1;

	return 0;
}

void print_int(const void *element) {
	printf("%i ", *(int*)element);
}

void print_char(const void *element) {
	printf("%c ", *(char*)element);
}

int compare_chars(const void* a, const void* b) {
	char *aa = (char*)a;
	char *bb = (char*)b;

	if(*aa < *bb)
		return -1;
	if(*aa > *bb)
		return 1;

	return 0;
}

void test_qsort_chars() {

	time_t t;
	srand((unsigned)time(&t));

	int arr_size = 10;
	char arr[arr_size];

	//fill array with random values
	for(int i = 0; i < arr_size; i++) {
		int r = (rand() % (122 - 97 + 1)) + 97;	//ascii a-z
		arr[i] = (char)r;	
	}

	printf("Sorted?: %i\n", sl_is_sorted(arr, arr_size, sizeof(char), *compare_chars));		
	sl_printarr(arr, arr_size, sizeof(char), *print_char);

	printf("\n");

	sl_qsort(arr, 0, arr_size-1, sizeof(char), *compare_chars);
	printf("Sorted?: %i\n", sl_is_sorted(arr, arr_size, sizeof(char), *compare_chars));		
	sl_printarr(arr, arr_size, sizeof(char), *print_char);

	return;
}


void test_qsort_ints() {

	time_t t;
	srand((unsigned)time(&t));

	int arr_size = 10;
	int arr[arr_size];
	for(int i = 0; i < arr_size; i++) {
		arr[i] = rand() % 100;
	}
	printf("Sorted?: %i\n", sl_is_sorted(arr, arr_size, sizeof(int), *compare_int));
	sl_printarr(arr, arr_size, sizeof(int), *print_int);
	printf("\n");

	sl_qsort(arr, 0, arr_size-1, sizeof(int), *compare_int);
	printf("Sorted?: %i\n", sl_is_sorted(arr, arr_size, sizeof(int), *compare_int));
	sl_printarr(arr, arr_size, sizeof(int), *print_int);

	return;
}

int main() {
	
	test_qsort_chars();

	printf("\n");

	test_qsort_ints();
			
	return 0;
}


