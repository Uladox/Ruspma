#ifndef RUSPMA_SYMBOLS_H
#define RUSPMA_SYMBOLS_H

#include "../hashmap/ruspma_hashmap.h"
#include "ruspma_symbols_struct.h"

extern ruspma_hashmap *GrandSymbolMap;
extern ruspma_hashmap *GrandKeywordMap;

void ruspma_symbols_init(void);

ruspma_symbol *ruspma_symbol_proc(char *name, int length);

ruspma_symbol *ruspma_keyword_proc(char *name, int length);

void ruspma_print_symbol(ruspma_symbol *symbol);

#endif
