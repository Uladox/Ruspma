#ifndef RUSPMA_EPSILON_GREEDY_H
#define RUSPMA_EPSILON_GREEDY_H

#include "ruspma_epsilon_greedy_struct.h"

ruspma_epgreedy *new_epsilon_greedy(int arms, double epsilon);

void free_epsilon_greedy(ruspma_epgreedy *greed);

void clear_epsilon_greedy(ruspma_epgreedy *greed);

int select_arm_epsilon_greedy(ruspma_epgreedy *greed);

void update_epsilon_greedy(ruspma_epgreedy *greed, 
			   int chosen_arm, double reward);

int best_arm_epsilon_greedy(ruspma_epgreedy *greed);

#endif
