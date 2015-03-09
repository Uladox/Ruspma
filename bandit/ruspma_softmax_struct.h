#ifndef RUSPMA_SOFTMAX_STRUCT_H
#define RUSPMA_SOFTMAX_STRUCT_H

typedef struct ruspma_softmax
{
  int arms;
  int *counts;
  double *values;
}ruspma_softmax;

#endif
