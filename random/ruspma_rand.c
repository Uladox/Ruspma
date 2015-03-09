#include <time.h>
#include <stdlib.h>

void ruspma_rand_init()
{
  srand(time(NULL));
  rand();
}

int ruspma_rand_from_range(int range)
{
  return rand() % range;
}

double ruspma_rand_decimal()
{
  return (double)rand() / (double)RAND_MAX;
}
