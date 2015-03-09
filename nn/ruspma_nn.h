#ifndef RUSPMA_NN_H
#define RUSPMA_NN_H

#include "ruspma_nn_struct.h"

ruspma_nn *new_network(int input_size, int hidden_size,
		       int output_size, int hidden_num);

void print_out_network(ruspma_nn *network);

void free_network(ruspma_nn *network);

ruspma_matrix *feedforward(ruspma_nn *network,
			   ruspma_matrix *input);

void *backpropagate(ruspma_nn *network,
		    ruspma_matrix *input,
		    ruspma_matrix *output,
		    double learning_rate);
#endif
