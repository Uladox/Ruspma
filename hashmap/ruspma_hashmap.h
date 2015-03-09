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
