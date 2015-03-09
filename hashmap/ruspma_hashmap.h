#ifndef RUSPMA_HASHMAP_H
#define RUSPMA_HASHMAP_H

#include "MurmurHash2.h"
#include "ruspma_hashmap_structs.h"

ruspma_hashmap *new_hashmap_seq(int);

ruspma_hashmap *new_hashmap(void);

void free_hashmap(ruspma_hashmap *hashmap);

void add_to_hashmap(ruspma_hashmap *hashmap, char *key_type,
		    void *key, int key_size, void *storage);

void add_to_hashmap_old_key(ruspma_hashmap *hashmap, char *key_type,
			    void *key, int key_size, void *storage);

void *get_hashmap(ruspma_hashmap *hashmap, char *key_type, void *key, int key_size);

#endif
