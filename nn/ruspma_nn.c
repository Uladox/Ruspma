#include "ruspma_nn_utils.h"
#include "ruspma_nn_struct.h"
#include <stdio.h>
#include <stdlib.h>

ruspma_nn *new_network(int input_size, int hidden_size,
			      int output_size, int hidden_num)
{
  int total_layers = hidden_num + 1;
  ruspma_nn *new_nn = malloc(sizeof(ruspma_nn));
  new_nn->weights = malloc(sizeof(ruspma_matrix *) * total_layers);
  new_nn->biases = malloc(sizeof(ruspma_matrix *) * total_layers);
  new_nn->layers = total_layers;

  ruspma_matrix **weights_pointer = new_nn->weights;
  ruspma_matrix **biases_pointer = new_nn->biases;
  *weights_pointer = rand_out_matrix(new_matrix_size(input_size, hidden_size));
  ++weights_pointer;
  *biases_pointer = rand_out_matrix(new_matrix_size(1, hidden_size));
  ++biases_pointer;
  int i;
  for(i = 1; i != hidden_num; ++i) {
    *weights_pointer = 
      rand_out_matrix(new_matrix_size(hidden_size, hidden_size));
    ++weights_pointer;
    *biases_pointer = rand_out_matrix(new_matrix_size(1, hidden_size));
    ++biases_pointer;
  }
  *weights_pointer = rand_out_matrix(new_matrix_size(hidden_size, output_size));
  *biases_pointer = rand_out_matrix(new_matrix_size(1, output_size));
  return new_nn;
}

void print_out_network(ruspma_nn *network)
{
  int i;
  printf(";;Weights\n");
  ruspma_matrix **weights_pointer = network->weights;
  for(i = 0; i != network->layers; ++i) {
    print_out_matrix(*weights_pointer);
    ++weights_pointer;
  }
  printf(";;Biases\n");
  ruspma_matrix **biases_pointer = network->biases;
  for(i = 0; i != network->layers; ++i) {
    print_out_matrix(*biases_pointer);
    ++biases_pointer;
  }
}

void free_network(ruspma_nn *network)
{
  int i;
  ruspma_matrix **weights_pointer = network->weights;
  ruspma_matrix **biases_pointer = network->biases;
  for(i = 0; i != network->layers; ++i) {
    free_matrix(*weights_pointer);
    free_matrix(*biases_pointer);
    ++weights_pointer;
    ++biases_pointer;
  }
  free(network->weights);
  free(network->biases);
  free(network);
}

ruspma_matrix *feedforward(ruspma_nn *network,
				   ruspma_matrix *input)
{
  int layers = network->layers;
  int i;
  ruspma_matrix *weights_out = input;
  ruspma_matrix **weights_pointer = network->weights;
  ruspma_matrix **biases_pointer = network->biases;
  for(i = 0; i != layers; ++i) {
    ruspma_matrix *dot
      = multiply_matrix(weights_out, *weights_pointer);
    if(i != 0)
      free_matrix(weights_out);
    ruspma_matrix *added =
      add_matrix(dot, *biases_pointer);
    free_matrix(dot);
    weights_out = sigmoid_matrix(added);
    free_matrix(added);
    ++weights_pointer;
    ++biases_pointer;
  }
  return weights_out;
}

void update_weights_backprop(double learning_rate,
			     ruspma_matrix **weights,
			     ruspma_matrix **biases,
			     ruspma_matrix *errors,
			     ruspma_matrix *inputs)
{
  //free_matrix(*weights_pointer);
  //*weights_pointer = multiply_matrix(transpose(*(layer_outputs -2)), *errors);
  ruspma_matrix *transposed = transpose(inputs);
  ruspma_matrix *changes = multiply_matrix(transposed, errors);
  ruspma_matrix *w_learned = multiply_scalar_matrix(learning_rate, changes);
  ruspma_matrix *newWeights = minus_matrix(*weights, w_learned);
  ruspma_matrix *newBiases = minus_matrix(*biases, errors);
  free_matrix(*weights);
  free_matrix(*biases);
  *biases = newBiases;
  *weights = newWeights;
  free_matrix(transposed);
  free_matrix(changes);
  free_matrix(w_learned);
  free_matrix(errors);
}

void *backpropagate(ruspma_nn *network,
		    ruspma_matrix *input,
		    ruspma_matrix *output,
		    double learning_rate)
{
  int layers = network->layers;
  ruspma_matrix **layer_outputs =
    malloc(sizeof(ruspma_matrix *) * layers);
  //notice similarity to feedforward
  ruspma_matrix *weights_out = input;
  ruspma_matrix **weights_pointer = network->weights;
  ruspma_matrix **biases_pointer = network->biases;
  int i;
  for(i = 0; i != layers; ++i) {
    ruspma_matrix *dot
      = multiply_matrix(weights_out, *weights_pointer);
    ruspma_matrix *added =
      add_matrix(dot, *biases_pointer);
    weights_out = sigmoid_matrix(added);
    free_matrix(dot);
    free_matrix(added);
    *layer_outputs = weights_out;
    ++weights_pointer;
    ++biases_pointer;
    ++layer_outputs;
  }
  --layer_outputs;
  ruspma_matrix **errors =
    malloc(sizeof(ruspma_matrix *) * layers);
  *errors = final_error(weights_out, output);
  free_matrix(weights_out);

  ruspma_matrix **error_pointer = errors;
  int e;
  for(e = 1; e != layers; ++e) {
    --layer_outputs;
    --weights_pointer;
    ++error_pointer;
    *error_pointer = hidden_error(*layer_outputs, *weights_pointer, *(error_pointer - 1));
  }
  ruspma_matrix **freeable_output = layer_outputs;
  --weights_pointer;
  biases_pointer = network->biases;
  update_weights_backprop(0.1, weights_pointer, biases_pointer, *error_pointer, input);
  //counter acts the ++layer_outputs on loop
  --layer_outputs;
  int j;
  for(j = 1; j != layers; ++j) {
    ++layer_outputs;
    ++weights_pointer;
    ++biases_pointer;
    --error_pointer;
    update_weights_backprop(learning_rate, weights_pointer,
			    biases_pointer, *error_pointer, 
			    *layer_outputs);
    free_matrix(*layer_outputs);
  }
  free(freeable_output);
  free(error_pointer);
}
