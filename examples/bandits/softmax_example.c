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

#include "../../bandit/ruspma_softmax.h"


double arm1(void)
{
  return ruspma_rand_decimal() / 0.002;
}

double arm2(void)
{
  return ruspma_rand_decimal();
}

void main(void)
{

  ruspma_rand_init();
  ruspma_softmax *ep = new_softmax(2);
  clear_softmax(ep);
  double reward = arm1();
  int chosen_arm = 0;
  update_softmax(ep, chosen_arm, reward);
  int i;
  for(i = 0; i != 1000; ++i) {
    chosen_arm = select_arm_softmax(ep);
    reward = (chosen_arm == 0) ? (arm1()) : (arm2());
    update_softmax(ep, chosen_arm, reward);
  }
  printf("%i\n", best_arm_softmax(ep));
}
