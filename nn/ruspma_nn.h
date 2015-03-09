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
