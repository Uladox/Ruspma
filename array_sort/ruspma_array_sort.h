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
