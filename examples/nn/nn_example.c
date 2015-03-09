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

#include "../../nn/ruspma_nn.h"
#include "../../random/ruspma_rand.h"

int main(int args, char**argv)
{
  ruspma_rand_init();
  double in1[2] = {(double)0.5, (double)0.4};
  double in2[2] = {(double)0.2, (double)0.9};
  double out1[2] = {(double)1.0, (double)0.0};
  double out2[2] = {(double)0.0, (double)1.0};

  struct ruspma_matrix *in1_m = 
    new_matrix_from(1, 2,
		    in1);
  struct ruspma_matrix *in2_m = 
    new_matrix_from(1, 2,
		    in2);
  struct ruspma_matrix *out1_m = 
    new_matrix_from(1, 2,
		    out1);
  struct ruspma_matrix *out2_m = 
    new_matrix_from(1, 2,
		    out2);

  struct ruspma_nn *k =
    new_network(2,11,2,1);

  int mm;
  for (mm = 0; mm != 1500; ++mm) {
    backpropagate(k, in1_m, out1_m, 6.5);
    backpropagate(k, in2_m, out2_m, 6.5);

  }

  print_out_matrix(feedforward(k, in1_m));
  print_out_matrix(feedforward(k, in2_m));

  free_network(k);

}
