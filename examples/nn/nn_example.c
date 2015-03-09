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
