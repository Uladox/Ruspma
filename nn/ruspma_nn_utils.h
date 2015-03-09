#ifndef RUSPMA_NN_UTILS_H
#define RUSPMA_NN_UTILS_H

#include "../matrix/ruspma_matrix.h"
#include <math.h>

double sigmoid_element(double element);

double sigmoid_prime_element(double element);

ruspma_matrix *sigmoid_matrix(ruspma_matrix *matrix);

ruspma_matrix *sigmoid_prime_matrix(ruspma_matrix *matrix);

ruspma_matrix *sigmoid_matrix_bang(ruspma_matrix *matrix);

ruspma_matrix *ruspma_sig_prime(ruspma_matrix *output);

ruspma_matrix *final_error(ruspma_matrix *output,
			   ruspma_matrix *desired);

ruspma_matrix *hidden_error(ruspma_matrix *output,
			    ruspma_matrix *next_weights,
			    ruspma_matrix *next_errors);
#endif
