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

#ifndef RUSPMA_ARRAY_SORT_H
#define RUSPMA_ARRAY_SORT_H

int largest_range_pos_int(int *range, int length);

int largest_range_pos_double(double *range, int length);

int smallest_range_pos_double(double *range, int length);

int smallest_range_pos_int(int *range, int length);

int sum_array_int(int *range, int length);

double sum_array_double(double *range, int length);

int categorical_draw(double *probs, int length);

#endif
