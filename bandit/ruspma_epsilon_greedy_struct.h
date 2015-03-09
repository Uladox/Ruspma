#ifndef RUSPMA_EPSILON_GREEDY_STRUCT_H
#define RUSPMA_EPSILON_GREEDY_STRUCT_H

typedef struct ruspma_epgreedy
{
  double epsilon;
  int arms;
  int *counts;
  double *values;
}ruspma_epgreedy;

#endif
