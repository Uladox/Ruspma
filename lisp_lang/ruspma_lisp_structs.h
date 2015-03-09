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
