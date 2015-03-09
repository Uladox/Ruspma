#ifndef RUSPMA_HASHMAP_STRUCTS
#define RUSPMA_HASHMAP_STRUCTS

// The maximun extries to bins before a rehash
#define DEFAULT_ENTRIES_TO_BINS 5
#define DEFAULT_SEED 37

typedef struct ruspma_bin
{
  char *key_type;
  int key_size;
  void *key;
  void *storage;
  struct ruspma_bin *next;
}ruspma_bin;

typedef struct ruspma_hashmap
{
  unsigned int bin_num;
  int entries_num;
  int *Primes_pointer;
  ruspma_bin **bins;
}ruspma_hashmap;
#endif
