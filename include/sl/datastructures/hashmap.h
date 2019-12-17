#ifndef _SL_DATASTRUCT_HASHMAP_
#define _SL_DATASTRUCT_HASHMAP_

#include <stdbool.h>

#define SL_HASHMAP_CAPACITY 8
#define SL_HASHMAP_THRESHOLD 0.5


typedef struct {
	void* keys[];
	void* vals[];
	size_t size;
	size_t capacity;
} sl_hashmap_t;

int sl_hash(const void* key, ) {
		
}

void sl_hashmap_add(sl_hashmap_t* map, const void* key, size_t key_size, const void* val, size_t val_size) {

	//first entry
	if(keys == NULL && vals == NULL) {
		map->capacity = SL_HASHMAP_CAPACITY;
		map->size = 0;
		map->keys = malloc(maps->capacity * key_size);
		map->vals = malloc(maps->capacity * val_size);
	}	

	map->size++;

	double load_factor = (double)map->size / (double)map->capacity;
	bool passed_threshold = (load_factor == SL_HASHMAP_THRESHOLD);
	if(passed_threshold) {	//dynamic resizing

	}
	else {
	
	}
}

#endif //_SL_DATASTRUCT_HASHMAP_
