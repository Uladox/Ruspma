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
