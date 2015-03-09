#include <stdlib.h>
#include "../random/ruspma_rand.h"
#include "../array_sort/ruspma_array_sort.h"
#include "ruspma_epsilon_greedy_struct.h"

ruspma_epgreedy *new_epsilon_greedy(int arms, double epsilon)
{
  ruspma_epgreedy *new_greed = 
    malloc(sizeof(ruspma_epgreedy));
  new_greed->epsilon = epsilon;
  new_greed->arms = arms;
  new_greed->counts = malloc(sizeof(int) * arms);
  new_greed->values = malloc(sizeof(double) * arms);
  return new_greed;
}

void free_epsilon_greedy(ruspma_epgreedy *greed)
{
  free(greed->counts);
  free(greed->values);
  free(greed);
}

void clear_epsilon_greedy(ruspma_epgreedy *greed)
{
  int arms = greed->arms;
  int *counts = greed->counts;
  double *values = greed->values;
  int i;
  for(i = 0; i != arms; ++i) {
    *counts = 0;
    *values = 0.0;
    ++counts;
    ++values;
  }
}

int select_arm_epsilon_greedy(ruspma_epgreedy *greed)
{
  if(ruspma_rand_decimal() > greed->epsilon)
    return largest_range_pos_double(greed->values, greed->arms);

  return ruspma_rand_from_range(greed->arms);
}

void update_epsilon_greedy(ruspma_epgreedy *greed, 
			   int chosen_arm, double reward)
{
  greed->counts[chosen_arm] += 1;
  int counts_now = greed->counts[chosen_arm];
  
  double value = greed->values[chosen_arm];
  greed->values[chosen_arm] = 
    ((counts_now - 1) / (double)counts_now) * value +
    (1.0 / (double)counts_now) * reward;
}

int best_arm_epsilon_greedy(ruspma_epgreedy *greed)
{
  return largest_range_pos_double(greed->values, greed->arms);
}
