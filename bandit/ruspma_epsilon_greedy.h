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

#ifndef RUSPMA_EPSILON_GREEDY_H
#define RUSPMA_EPSILON_GREEDY_H

#include "ruspma_epsilon_greedy_struct.h"

ruspma_epgreedy *new_epsilon_greedy(int arms, double epsilon);

void free_epsilon_greedy(ruspma_epgreedy *greed);

void clear_epsilon_greedy(ruspma_epgreedy *greed);

int select_arm_epsilon_greedy(ruspma_epgreedy *greed);

void update_epsilon_greedy(ruspma_epgreedy *greed, 
			   int chosen_arm, double reward);

int best_arm_epsilon_greedy(ruspma_epgreedy *greed);

#endif
