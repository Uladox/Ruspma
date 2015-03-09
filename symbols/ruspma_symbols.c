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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../hashmap/ruspma_hashmap.h"
#include "ruspma_symbols_struct.h"

ruspma_hashmap *GrandSymbolMap;
ruspma_hashmap *GrandKeywordMap;

char *SymbolTypeName = "Symbol";
char *KeywordTypeName = "Keyword";

char *complete_string(char *name, int length)
{
  char *new_str = malloc(length + 1);
  strncpy(new_str, name, length);
  new_str[length] = '\0';
  return new_str;
}

ruspma_symbol *new_symbol(char *name, int length, int type)
{
  ruspma_symbol *new_symbol = malloc(sizeof(ruspma_symbol));
  new_symbol->name = complete_string(name, length);
  new_symbol->type = type;
  return new_symbol;
}

void ruspma_symbols_init(void)
{
  GrandSymbolMap = new_hashmap_seq(8);
  GrandKeywordMap = new_hashmap_seq(4);
}

ruspma_symbol *ruspma_symbol_proc(char *name, int length)
{
  int name_size = length;
  ruspma_symbol *map_symbol = get_hashmap(GrandSymbolMap, SymbolTypeName, name, name_size);
  if(map_symbol == NULL) {
    add_to_hashmap(GrandSymbolMap, SymbolTypeName, name, name_size, 
		   new_symbol(name, length, RUSPMA_SYMBOL));
    map_symbol = get_hashmap(GrandSymbolMap, SymbolTypeName, name, name_size);
  }
  return map_symbol;
}

ruspma_symbol *ruspma_keyword_proc(char *name, int length)
{
  int name_size = length;
  ruspma_symbol *map_symbol = get_hashmap(GrandKeywordMap, KeywordTypeName, name, name_size);
  if(map_symbol == NULL) {
    add_to_hashmap(GrandKeywordMap, KeywordTypeName, name, name_size, 
		   new_symbol(name, length, RUSPMA_KEYWORD));
    map_symbol = get_hashmap(GrandKeywordMap, KeywordTypeName, name, name_size);
  }
  return map_symbol;
}

void ruspma_print_symbol(ruspma_symbol *symbol)
{
  if(symbol->type == RUSPMA_SYMBOL)
    printf("'");
  else if(symbol->type == RUSPMA_KEYWORD)
    printf(":");
  printf("%s", symbol->name);
}
