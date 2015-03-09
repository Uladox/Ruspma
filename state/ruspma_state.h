#ifndef RUSPMA_STATE_H
#define RUSPMA_STATE_H

#include "../bandit/softmax.h"

typedef struct ruspma_action
{
  double q_value;

  int policy_t;
  void *policy;

  struct ruspma_state (*action)(struct ruspma_state *);

  struct ruspma_action *next_action;
}ruspma_action;

typedef struct ruspma_state
{
  int actions_num;
  ruspma_action *actions_list;
  
}ruspma_state;

#endif
