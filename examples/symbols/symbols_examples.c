#include <stdio.h>
#include "../../symbols/ruspma_symbols.h"
#include "../../ruspma_setup.h"

int main(void)
{
  ruspma_setup();
  printf("%s ", ruspma_symbol_proc("john", 4)->name);
  if(ruspma_symbol_proc("john", 4) == 
     ruspma_symbol_proc("john", 4))
    printf("is john and ");

  printf("%s ", ruspma_keyword_proc("george", 6)->name);
  if(ruspma_keyword_proc("george", 6) == 
     ruspma_keyword_proc("george", 6))
    printf("is george.\n");

  ruspma_print_symbol(ruspma_symbol_proc("john", 4));
  printf("\n");
  ruspma_print_symbol(ruspma_keyword_proc("george", 6));
  printf("\n");
  return 0;
}
