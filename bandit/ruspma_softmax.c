#include <math.h>
#include <stdlib.h>
#include "../array_sort/ruspma_array_sort.h"
#include "ruspma_softmax_struct.h"

ruspma_softmax *new_softmax(int arms)
{
  ruspma_softmax *new_soft = 
    malloc(sizeof(ruspma_softmax));
  new_soft->arms = arms;
  new_soft->counts = malloc(sizeof(int) * arms);
  new_soft->values = malloc(sizeof(double) * arms);
  return new_soft;
}

void clear_softmax(ruspma_softmax *soft)
{
  int arms = soft->arms;
  int *counts = soft->counts;
  double *values = soft->values;
  int i;
  for(i = 0; i != arms; ++i) {
    *counts = 0;
    *values = 0.0;
    ++counts;
    ++values;
  }
}

int select_arm_softmax(ruspma_softmax *soft)
{
  /* note this code is unelegant in c */
  int arms = soft->arms;
  double t = sum_array_int(soft->counts, arms);
  double temperature = 1 / log(t + 0.0000001);
  double *presums = malloc(sizeof(double) * arms);
  double *presums_counter = presums;
  double *values_counter = soft->values;
  int i;
  for(i = 0; i != arms; ++i) {
    *presums_counter = exp(*values_counter / temperature);
    ++presums_counter;
    ++values_counter;
  }
  double sums = sum_array_double(presums, arms);
  /* I reuse pointers, I am lazy like that. Efficiancy
     crazy, and lazy. The macros are for "easier"
     readability. */
#define ruspma_soft_max_probs presums
#define ruspma_soft_max_probs_counter presums_counter
  ruspma_soft_max_probs_counter = ruspma_soft_max_probs;
  values_counter = soft->values;
  for(i = 0; i != arms; ++i) {
    *ruspma_soft_max_probs_counter
      = exp(*values_counter / temperature) / sums;
    ++ruspma_soft_max_probs_counter;
    ++values_counter;
  }
  return categorical_draw(ruspma_soft_max_probs, arms);
#undef ruspma_soft_max_probs_counter
#undef ruspma_soft_max_probs
}

void update_softmax(ruspma_softmax *soft, int chosen_arm,
		    double reward)
{
  soft->counts[chosen_arm] += 1;
  int counts_now = soft->counts[chosen_arm];
  
  double value = soft->values[chosen_arm];
  soft->values[chosen_arm] = 
    ((counts_now - 1) / (double)counts_now) * value +
    (1.0 / (double)counts_now) * reward;
}

int best_arm_softmax(ruspma_softmax *soft)
{
  return largest_range_pos_double(soft->values, soft->arms);
}
