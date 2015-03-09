#ifndef RUSPMA_NN_STRUCT_H
#define RUSPMA_NN_STRUCT_H

#include "../matrix/ruspma_matrix.h"
typedef struct ruspma_nn
{
  int layers;
  ruspma_matrix **weights;
  ruspma_matrix **biases;
}ruspma_nn;

#endif
