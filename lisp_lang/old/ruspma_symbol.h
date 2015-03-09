#ifndef RUSPMA_SYMBOL_H
#define RUSPMA_SYMBOL_H

#include "ruspma_hashmap.h"
#include "ruspma_struct.h"
#include "string.h"

ruspma_symmap Grand_symmap;

ruspma_lobj *get_symbol(char *symbol_name, int length)
{
  ruspma_lobj *object = get_hashmap(&Grand_symmap, symbol_name, 
}

#endif
