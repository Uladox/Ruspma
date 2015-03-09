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


#include "../random/ruspma_rand.h"

int largest_range_pos_int(int *range, int length)
{
  if(length == 0)
    return -1;
  int largest_num;
  int largest_pos;
  largest_num = *range;
  largest_pos = 0;
  ++range;
  int i;
  for(i = 1; i != length; ++i) {
    if(*range > largest_num) {
      largest_num = *range;
      largest_pos = i;
    }
    ++range;
  }
  return largest_pos;
}

int largest_range_pos_double(double *range, int length)
{
  if(length == 0)
    return -1;
  double largest_num;
  int largest_pos;
  largest_num = *range;
  largest_pos = 0;
  ++range;
  int i;
  for(i = 1; i != length; ++i) {
    if(*range > largest_num) {
      largest_num = *range;
      largest_pos = i;
    }
    ++range;
  }
  return largest_pos;
}

int smallest_range_pos_double(double *range, int length)
{
  if(length == 0)
    return -1;
  double largest_num;
  int largest_pos;
  largest_num = *range;
  largest_pos = 0;
  ++range;
  int i;
  for(i = 1; i != length; ++i) {
    if(*range < largest_num) {
      largest_num = *range;
      largest_pos = i;
    }
    ++range;
  }
  return largest_pos;
}

int smallest_range_pos_int(int *range, int length)
{
  if(length == 0)
    return -1;
  int largest_num;
  int largest_pos;
  largest_num = *range;
  largest_pos = 0;
  ++range;
  int i;
  for(i = 1; i != length; ++i) {
    if(*range < largest_num) {
      largest_num = *range;
      largest_pos = i;
    }
    ++range;
  }
  return largest_pos;
}

int sum_array_int(int *range, int length)
{
  if(length == 0)
    return -1;
  int sum;
  int i;
  for(i = 0; i != length; ++i) {
    sum += *range;
    ++range;
  }
  return sum;
}

double sum_array_double(double *range, int length)
{
  if(length == 0)
    return -1;
  double sum;
  int i;
  for(i = 0; i != length; ++i) {
    sum += *range;
    ++range;
  }
  return sum;
}

int categorical_draw(double *probs, int length)
{
  double compare_prob = ruspma_rand_decimal();
  double culm_prob = 0.0;
  int i;
  for(i = 0; i != length; ++i) {
    culm_prob += probs[i];
    if(culm_prob > compare_prob)
      return i;
  }
  return length - 1;
}
