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

#ifndef RUSPMA_SOFTMAX_H
#define RUSPMA_SOFTMAX_H

#include "ruspma_softmax_struct.h"

ruspma_softmax *new_softmax(int arms);

void clear_softmax(ruspma_softmax *soft);

int select_arm_softmax(ruspma_softmax *soft);

void update_softmax(ruspma_softmax *soft, int chosen_arm,
		    double reward);

int best_arm_softmax(ruspma_softmax *soft);

#endif
