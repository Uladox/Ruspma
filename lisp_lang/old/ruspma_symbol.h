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
