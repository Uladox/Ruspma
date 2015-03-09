#include "ruspma_hashmap_structs.h"
#include <stdlib.h>
#include <string.h>

unsigned int Hashmap_Primes[29] =
  {
    8 + 3, 16 + 3, 32 + 5, 64 + 3, 128 + 3, 256 + 27, 512 + 9, 1024 + 9, 2048 + 5, 4096 + 3,
    8192 + 27, 16384 + 43, 32768 + 3, 65536 + 45, 131072 + 29, 262144 + 3, 524288 + 21, 1048576 + 7,
    2097152 + 17, 4194304 + 15, 8388608 + 9, 16777216 + 43, 33554432 + 35, 67108864 + 15,
    134217728 + 29, 268435456 + 3, 536870912 + 11, 1073741824 + 85, 0
  };

void rehash(ruspma_hashmap *);

ruspma_bin *new_bin(int key_size, char *key_type, void *key, void *storage)
{
  ruspma_bin *new = malloc(sizeof(ruspma_bin));
  new->key = malloc(key_size);
  char *new_key = (char *)new->key;
  char *old_key = (char *)key;
  int i;
  for(i = 0; i != key_size; ++i) {
    *new_key = *old_key;
    ++new_key;
    ++old_key;
  }
  new->key_size = key_size;
  new->storage = storage;
  new->key_type = key_type;
  new->next = NULL;
}

ruspma_bin *new_bin_old_key(int key_size, char *key_type, void *key, void *storage)
{
  ruspma_bin *new = malloc(sizeof(ruspma_bin));
  new->key = key;
  new->key_size = key_size;
  new->key_type = key_type;
  new->storage = storage;
  new->next = NULL;
}

void bin_free(ruspma_bin *bin)
{
  free(bin->key);
  free(bin);
}

void bin_safe_free(ruspma_bin *bin)
{
  free(bin);
}

ruspma_hashmap *new_hashmap(void)
{
  ruspma_hashmap *new = malloc(sizeof(ruspma_hashmap));
  new->bin_num = Hashmap_Primes[0];
  new->bins = malloc(sizeof(ruspma_bin *) * Hashmap_Primes[0]);
  new->entries_num = 0;
  new->Primes_pointer = Hashmap_Primes;
  ruspma_bin **bin_ptr = new->bins;
  int i;
  for(i = 0; i != Hashmap_Primes[0]; ++i) {
    *bin_ptr = NULL;
    ++bin_ptr;
  }
  return new;
}

ruspma_hashmap *new_hashmap_seq(int sequence)
{
  ruspma_hashmap *new = malloc(sizeof(ruspma_hashmap));
  new->bin_num = Hashmap_Primes[sequence];
  new->bins = malloc(sizeof(ruspma_bin *) * Hashmap_Primes[sequence]);
  new->entries_num = 0;
  new->Primes_pointer = Hashmap_Primes + sequence;
  ruspma_bin **bin_ptr = new->bins;
  int i;
  for(i = 0; i != Hashmap_Primes[sequence]; ++i) {
    *bin_ptr = NULL;
    ++bin_ptr;
  }
  return new;
}

void free_hashmap(ruspma_hashmap *hashmap)
{
  ruspma_bin **current_top_bin = hashmap->bins;
  unsigned int bin_num = hashmap->bin_num;
  unsigned int i;
  for(i = 0; i != bin_num; ++i) {
    ruspma_bin *current_bin = *current_top_bin;
    while(current_bin != NULL) {
      ruspma_bin *current_bin_holder = current_bin;
      current_bin = current_bin->next;
      bin_free(current_bin_holder);
    }
    ++current_top_bin;
  }
  free(hashmap->bins);
  free(hashmap);
}

//true if same, else false
int check_same(ruspma_bin *bin, char *key_type, void *key, int size)
{
  if(bin->key_size != size)
    return 0;

  if(strcmp(bin->key_type, key_type) != 0)
    return 0;
  const unsigned char * key_data = (const unsigned char *)key;
  const unsigned char * bin_key_data = (const unsigned char *)bin->key;

  int count_size;
  for(count_size = size; count_size != 0; --count_size) {
    if(*key_data != *bin_key_data)
      return 0;
    ++key_data;
    ++bin_key_data;
  }
  return 1;
}

ruspma_bin *get_else_new_top_bin(ruspma_hashmap *hashmap, ruspma_bin *top_bin, char *key_type, void *key, int key_size)
{
  if(check_same(top_bin, key_type, key, key_size))
    return top_bin;

  ruspma_bin *next_bin = top_bin;
  if(top_bin->next != NULL) {
    next_bin = top_bin->next;
    int loop = 1;
    while(loop) {
      if(check_same(next_bin, key_type, key, key_size))
	return next_bin;

      if(next_bin->next == NULL)
	loop = 0;
      else
	next_bin = next_bin->next;
    }
  }
  next_bin->next = new_bin(key_size, key_type, key, NULL);
  ++(hashmap->entries_num);
  return next_bin->next;
}

// You should never need to use this so long name is okay
ruspma_bin *get_else_new_top_bin_old_key(ruspma_hashmap *hashmap, ruspma_bin *top_bin, char *key_type, void *key, int key_size)
{
  if(check_same(top_bin, key_type, key, key_size))
    return top_bin;

  ruspma_bin *next_bin = top_bin;
  if(top_bin->next != NULL) {
    next_bin = top_bin->next;
    int loop = 1;
    while(loop) {
      if(check_same(next_bin, key_type, key, key_size))
	return next_bin;

      if(next_bin->next == NULL)
	loop = 0;
      else
	next_bin = next_bin->next;
    }
  }
  next_bin->next = new_bin_old_key(key_size, key_type, key, NULL);
  ++(hashmap->entries_num);
  return next_bin->next;
}

void add_to_hashmap(ruspma_hashmap *hashmap, char *key_type,
		    void *key, int key_size, void *storage)
{
  if(hashmap->entries_num / hashmap->bin_num >= DEFAULT_ENTRIES_TO_BINS)
    rehash(hashmap);
  unsigned int row = MurmurHash2(key, key_size, DEFAULT_SEED) % hashmap->bin_num;
  ruspma_bin *top_bin = hashmap->bins[row];
  if(top_bin == NULL) {
    hashmap->bins[row] = new_bin(key_size, key_type, key, storage);
    ++(hashmap->entries_num);
    return;
  }

  ruspma_bin *new = get_else_new_top_bin(hashmap, top_bin, key_type, key, key_size);
  new->storage = storage;
}

void add_to_hashmap_old_key(ruspma_hashmap *hashmap, char *key_type, 
			    void *key, int key_size, void *storage)
{
  if(hashmap->entries_num / hashmap->bin_num >= DEFAULT_ENTRIES_TO_BINS)
    rehash(hashmap);
  unsigned int row = MurmurHash2(key, key_size, DEFAULT_SEED) % hashmap->bin_num;
  ruspma_bin *top_bin = hashmap->bins[row];
  if(top_bin == NULL) {
    hashmap->bins[row] = new_bin_old_key(key_size, key_type, key, storage);
    ++(hashmap->entries_num);
    return;
  }

  ruspma_bin *new = get_else_new_top_bin_old_key(hashmap, top_bin, key_type, key, key_size);
  new->storage = storage;
}

void *get_hashmap(ruspma_hashmap *hashmap, char *key_type, void *key, int key_size)
{
  unsigned int row = MurmurHash2(key, key_size, DEFAULT_SEED) % hashmap->bin_num;

  ruspma_bin *top_bin = hashmap->bins[row];
  if(top_bin == NULL)
    return NULL;
  if(check_same(top_bin, key_type, key, key_size))
    return top_bin->storage;

  ruspma_bin *next_bin = top_bin->next;
  while(next_bin != NULL) {
    if(check_same(next_bin, key_type, key, key_size))
      return next_bin->storage;
    next_bin = next_bin->next;
  }
    return NULL;
}

void rehash(ruspma_hashmap *hashmap)
{
  unsigned int old_bin_num = hashmap->bin_num;
  ruspma_bin **old_bins = hashmap->bins;

  hashmap->entries_num = 0;
  ++(hashmap->Primes_pointer);
  unsigned int new_bin_num = *(hashmap->Primes_pointer);
  hashmap->bin_num = new_bin_num;
  ruspma_bin **rehashed_bins = malloc(sizeof(ruspma_bin *) * new_bin_num);
  hashmap->bins = rehashed_bins;

  unsigned int j;
  for(j = 0; j != new_bin_num; ++j) {
    *rehashed_bins = NULL;
    ++rehashed_bins;
  }

  ruspma_bin **current_top_bin = old_bins;
  unsigned int i;
  for(i = 0; i != old_bin_num; ++i) {
    ruspma_bin *current_bin = *current_top_bin;
    while(current_bin != NULL) {
      add_to_hashmap_old_key(hashmap,
			     current_bin->key_type,
			     current_bin->key, 
			     current_bin->key_size,
			     current_bin->storage);
      ruspma_bin *current_bin_holder = current_bin;
      current_bin = current_bin->next;
      bin_safe_free(current_bin_holder);
    }
    ++current_top_bin;
  }
  free(old_bins);
}
