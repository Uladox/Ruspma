#ifndef RUSPMA_UCB1_H
#define RUSPMA_UCB1_H

#include <stdlib.h>
#include "../general.h"

struct ucb1
{
  int arms;
  int *counts;
  double *values;
};

struct ucb1 *new_ucb1(int arms)
{
  struct ucb1 *new_ucb1 = 
    malloc(sizeof(struct ucb1));
  new_ucb1->arms = arms;
  new_ucb1->counts = malloc(sizeof(int) * arms);
  new_ucb1->values = malloc(sizeof(double) * arms);
  return new_ucb1;
}

void free_ucb1(struct ucb1 *bound)
{
  free(bound->counts);
  free(bound->values);
  free(bound);
}

void clear_ucb1(struct ucb1 *bound)
{
  int arms = bound->arms;
  int *counts = bound->counts;
  double *values = bound->values;
  int i;
  for(i = 0; i != arms; ++i) {
    *counts = 0;
    *values = 0.0;
    ++counts;
    ++values;
  }
}

int select_arm_ucb1(struct ucb1 *bound)
{
  int least_chosen = smallest_range_pos_int(bound->counts);
  if(bound->counts[least_chosen] == 0)
    return least_chosen;
  
}

#endif
