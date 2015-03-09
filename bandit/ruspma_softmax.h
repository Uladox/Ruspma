#ifndef RUSPMA_SOFTMAX_H
#define RUSPMA_SOFTMAX_H

#include "ruspma_softmax_struct.h"

ruspma_softmax *new_softmax(int arms);

void clear_softmax(ruspma_softmax *soft);

int select_arm_softmax(ruspma_softmax *soft);

void update_softmax(ruspma_softmax *soft, int chosen_arm,
		    double reward);

int best_arm_softmax(ruspma_softmax *soft);

#endif
