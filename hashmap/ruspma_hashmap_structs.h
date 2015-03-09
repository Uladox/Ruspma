/*    This file is part of Ruspma.
 *
 *    Ruspma is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Ruspma is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Ruspma.  If not, see <http://www.gnu.org/licenses/>.
 */

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
