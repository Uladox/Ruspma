#ifndef RUSPMA_VECTMAP_STRUCT_H
#define RUSPMA_VECMTAP_STRUCT_H

#include "../matrix/ruspma_matrix.h"

typedef struct ruspma_vectmap
{
  int vectors_num;
  ruspma_matrix **vectors;
}ruspma_vectmap;

#endif
