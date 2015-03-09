#ifndef RUSPMA_MATRIX_H
#define RUSPMA_MATRIX_H

#include "ruspma_matrix_struct.h"

void free_matrix(ruspma_matrix *matrix);

ruspma_matrix *new_matrix_size(int rows, int columns);

ruspma_matrix *new_matrix_from(int rows, int columns, ...);

ruspma_matrix *transpose(ruspma_matrix *matrix);

ruspma_matrix *zero_out_matrix(ruspma_matrix *matrix);

ruspma_matrix *num_out_matrix(ruspma_matrix *matrix, double num);

ruspma_matrix *rand_out_matrix(ruspma_matrix *matrix);

void print_out_matrix(ruspma_matrix *matrix);

ruspma_matrix *add_matrix(ruspma_matrix *matrix1,
			  ruspma_matrix *matrix2);

ruspma_matrix *minus_matrix(ruspma_matrix *matrix1,
			    ruspma_matrix *matrix2);

ruspma_matrix *multiply_scalar_matrix(double scalar, 
				      ruspma_matrix *matrix);

struct  ruspma_matrix *hadamard_matrix(ruspma_matrix *matrix1,
				       ruspma_matrix *matrix2);

ruspma_matrix *multiply_matrix(ruspma_matrix *matrix1,
			       ruspma_matrix *matrix2);
#endif
