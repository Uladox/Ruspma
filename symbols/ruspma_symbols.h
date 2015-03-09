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
