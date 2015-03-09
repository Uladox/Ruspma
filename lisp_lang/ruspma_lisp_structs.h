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

#ifndef RUSPMA_LISP_STRUCT
#define RUSPMA_LISP_STRUCT

#include "../symbols/ruspma_symbols.h"

typedef struct ruspma_list
{
  struct ruspma_cell *first_cell;
}ruspma_list;

typedef struct ruspma_atom
{
  int type;
  union object {
    ruspma_symbol symbol;
  }object;

}ruspma_atom;

typedef struct ruspma_value
{
  int type;
  union object
  {
    ruspma_list list;
    ruspma_atom atom;
  }object;

}ruspma_value;

typedef struct ruspma_cell
{
  ruspma_value *car;
  ruspma_value *cdr;
}ruspma_cell;

#endif
