#include "random/ruspma_rand.h"
#include "symbols/ruspma_symbols.h"

void ruspma_setup(void)
{
  ruspma_rand_init();
  ruspma_symbols_init();
}
