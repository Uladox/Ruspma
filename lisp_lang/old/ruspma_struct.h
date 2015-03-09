#ifndef RUSPMA_STRUCT_H
#define RUSPMA_STRUCT_H

enum { RUS_SYM, RUS_LIST, RUS_FUNC }

typedef struct ruspma_lobj
{
  int type;
  struct ruspma_lobj *next;
  struct ruspma_lobj *list;
}ruspma_lobj;

#endif
