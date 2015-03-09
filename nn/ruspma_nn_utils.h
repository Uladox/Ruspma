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
