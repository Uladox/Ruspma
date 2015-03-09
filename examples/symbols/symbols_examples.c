/*    This file is part of Ruspma.
 *
 *    Ruspma is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Ruspma is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Ruspma.  If not, see <http://www.gnu.org/licenses/>.
 */

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
