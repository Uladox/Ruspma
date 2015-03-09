#include <math.h>
#include "../matrix/ruspma_matrix.h"

double sigmoid_element(double element)
{
  return 1/(1 + exp(-element));
}

double sigmoid_prime_element(double element)
{
  double sig = sigmoid_element(element);
  return sig * (1 - sig);
}

ruspma_matrix *sigmoid_matrix(ruspma_matrix *matrix)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix->rows, matrix->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer = matrix->matrix;
  int i;
  for(i = 0; i != matrix->rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != matrix->columns; ++e) {
      *new_matrix_element_pointer =
	sigmoid_element(*matrix_element_pointer);
      ++matrix_element_pointer;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

ruspma_matrix *sigmoid_prime_matrix(ruspma_matrix *matrix)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix->rows, matrix->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer = matrix->matrix;
  int i;
  for(i = 0; i != matrix->rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != matrix->columns; ++e) {
      *new_matrix_element_pointer =
	sigmoid_prime_element(*matrix_element_pointer);
      ++matrix_element_pointer;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

ruspma_matrix *sigmoid_matrix_bang(ruspma_matrix *matrix)
{
  double **matrix_row_pointer = matrix->matrix;
  int i;
  for(i = 0; i != matrix->rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != matrix->columns; ++e) {
      *matrix_element_pointer =
	sigmoid_element(*matrix_element_pointer);
      ++matrix_element_pointer;
    }

    ++matrix_row_pointer;
  }
  return matrix;
}

ruspma_matrix *ruspma_sig_prime(ruspma_matrix *output)
{
  ruspma_matrix *one_matrix = 
    num_out_matrix(new_matrix_size(output->rows, output->columns), 1);
  ruspma_matrix *one_minused = minus_matrix(one_matrix, output);
  ruspma_matrix *sigprime = hadamard_matrix(output, one_minused);
  free_matrix(one_matrix);
  free_matrix(one_minused);
  return sigprime;
}

ruspma_matrix *final_error(ruspma_matrix *output,
				  ruspma_matrix *desired)
{
  ruspma_matrix *sigprime = ruspma_sig_prime(output);
  ruspma_matrix *error = minus_matrix(output, desired);
  ruspma_matrix *layer_error = hadamard_matrix(error, sigprime);
  free_matrix(sigprime);
  free_matrix(error);
  return layer_error;
}

ruspma_matrix *hidden_error(ruspma_matrix *output,
				   ruspma_matrix *next_weights,
				   ruspma_matrix *next_errors)
{
  ruspma_matrix *sigprime = ruspma_sig_prime(output);
  ruspma_matrix *weights_tranposed = transpose(next_weights);
  ruspma_matrix *weights_errors = multiply_matrix(next_errors,
							 weights_tranposed);
  ruspma_matrix *this_error = hadamard_matrix(sigprime, weights_errors);
  free_matrix(sigprime);
  free_matrix(weights_tranposed);
  free_matrix(weights_errors);
  return this_error;
}
