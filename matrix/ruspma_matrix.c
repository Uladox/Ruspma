#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../random/ruspma_rand.h"
#include "ruspma_matrix.h"

void free_matrix(ruspma_matrix *matrix)
{
  double **matrix_row_pointer = matrix->matrix;
  int i;
  for(i = 0; i != matrix->rows; ++i) {
    free(*matrix_row_pointer);
    ++matrix_row_pointer;
    }
  free(matrix->matrix);
  free(matrix);
}

ruspma_matrix *new_matrix_size(int rows, int columns)
{
  ruspma_matrix *new_matrix = malloc(sizeof(ruspma_matrix));
  new_matrix->rows = rows;
  new_matrix->columns = columns;
  new_matrix->matrix = malloc(sizeof(double *) * rows);
  double **matrix_row_pointer = new_matrix->matrix;
  int i;
  for(i = 0; i != rows; ++i) {
    *matrix_row_pointer = malloc(sizeof(double) * columns);
    ++matrix_row_pointer;
  }
  return new_matrix;
}

ruspma_matrix *new_matrix_from(int rows, int columns, ...)
{

  ruspma_matrix *matrix = malloc(sizeof(ruspma_matrix));
  matrix->rows = rows;
  matrix->columns = columns;
  matrix->matrix = malloc(sizeof(double *) * rows);
  double **matrix_row_pointer = matrix->matrix;

  va_list row_arrays;
  va_start(row_arrays, rows);
  double *row_pointer = va_arg(row_arrays, double *);
  int i;
  for(i = 0; i != rows; ++i) {
    *matrix_row_pointer = malloc(sizeof(double) * columns);
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != matrix->columns; ++e) {
      *matrix_element_pointer = *row_pointer;
      ++matrix_element_pointer;
      ++row_pointer;
    }
    ++matrix_row_pointer;
    row_pointer = va_arg(row_arrays, double *);
  }
  va_end(row_arrays);
  return matrix;
}

ruspma_matrix *transpose(ruspma_matrix *matrix)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix->columns, matrix->rows);

  double **new_matrix_row = new_matrix->matrix;
  double **matrix_row = matrix->matrix;

  int rows = new_matrix->rows;
  int j;
  //go through each row in the new matrix
  for(j = 0; j != rows; ++j) {  
    double *new_matrix_element = *new_matrix_row;
    int i;
    for(i = 0; i != new_matrix->columns; ++i) {
      *new_matrix_element = *(*(matrix_row + i) + j);
    }
    ++new_matrix_row;
  }
  return new_matrix;  
}

ruspma_matrix *zero_out_matrix(ruspma_matrix *matrix)
{
  double **matrix_row_pointer = matrix->matrix;
  int rows = matrix->rows;
  int columns = matrix->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *matrix_element_pointer = 0.0;
      ++matrix_element_pointer;
    }
    ++matrix_row_pointer;
  }
  return matrix;
}

ruspma_matrix *num_out_matrix(ruspma_matrix *matrix, double num)
{
  double **matrix_row_pointer = matrix->matrix;
  int rows = matrix->rows;
  int columns = matrix->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *matrix_element_pointer = num;
      ++matrix_element_pointer;
    }
    ++matrix_row_pointer;
  }
  return matrix;
}

ruspma_matrix *rand_out_matrix(ruspma_matrix *matrix)
{
  double **matrix_row_pointer = matrix->matrix;
  int rows = matrix->rows;
  int columns = matrix->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      int make_negative_chance = (rand() % 2) ? 1 : -1;
      *matrix_element_pointer = 
	make_negative_chance * ruspma_rand_decimal();
      ++matrix_element_pointer;
    }
    ++matrix_row_pointer;
  }
  return matrix;
}

void print_out_matrix(ruspma_matrix *matrix)
{
  double **matrix_row_pointer = matrix->matrix;
  int rows = matrix->rows;
  int columns = matrix->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      printf("%f ", *matrix_element_pointer);
      ++matrix_element_pointer;
    }
    printf("\n");
    ++matrix_row_pointer;
  }
  printf("\n");
}

ruspma_matrix *add_matrix(ruspma_matrix *matrix1,
				 ruspma_matrix *matrix2)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix1->rows, matrix1->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer1 = matrix1->matrix;
  double **matrix_row_pointer2 = matrix2->matrix;
  int rows = matrix1->rows;
  int columns = matrix1->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer1 = *matrix_row_pointer1;
    double *matrix_element_pointer2 = *matrix_row_pointer2;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *new_matrix_element_pointer =
	*matrix_element_pointer1 +
	*matrix_element_pointer2;

      ++matrix_element_pointer1;
      ++matrix_element_pointer2;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer1;
    ++matrix_row_pointer2;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

ruspma_matrix *minus_matrix(ruspma_matrix *matrix1,
				   ruspma_matrix *matrix2)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix1->rows, matrix1->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer1 = matrix1->matrix;
  double **matrix_row_pointer2 = matrix2->matrix;
  int rows = matrix1->rows;
  int columns = matrix1->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer1 = *matrix_row_pointer1;
    double *matrix_element_pointer2 = *matrix_row_pointer2;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *new_matrix_element_pointer =
	*matrix_element_pointer1 -
	*matrix_element_pointer2;

      ++matrix_element_pointer1;
      ++matrix_element_pointer2;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer1;
    ++matrix_row_pointer2;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

ruspma_matrix *multiply_scalar_matrix(double scalar, 
					     ruspma_matrix *matrix)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix->rows, matrix->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer = matrix->matrix;
  int rows = matrix->rows;
  int columns = matrix->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer = *matrix_row_pointer;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *new_matrix_element_pointer =
	*matrix_element_pointer *
        scalar;

      ++matrix_element_pointer;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

struct  ruspma_matrix *hadamard_matrix(ruspma_matrix *matrix1,
				       ruspma_matrix *matrix2)
{
  ruspma_matrix *new_matrix = 
    new_matrix_size(matrix1->rows, matrix1->columns);
  double **new_matrix_row_pointer = new_matrix->matrix;
  double **matrix_row_pointer1 = matrix1->matrix;
  double **matrix_row_pointer2 = matrix2->matrix;
  int rows = matrix1->rows;
  int columns = matrix1->columns;
  int i;
  for(i = 0; i != rows; ++i) {
    double *matrix_element_pointer1 = *matrix_row_pointer1;
    double *matrix_element_pointer2 = *matrix_row_pointer2;
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    for(e = 0; e != columns; ++e) {
      *new_matrix_element_pointer =
	*matrix_element_pointer1 *
	*matrix_element_pointer2;

      ++matrix_element_pointer1;
      ++matrix_element_pointer2;
      ++new_matrix_element_pointer;
    }

    ++matrix_row_pointer1;
    ++matrix_row_pointer2;
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}

/* Note I normally do not mass comment code however this code
   is tricky, so I will.
*/
ruspma_matrix *multiply_matrix(ruspma_matrix *matrix1,
				      ruspma_matrix *matrix2)
{
  int new_rows = matrix1->rows;
  int new_columns = matrix2->columns;
  int matrix1_columns = matrix1->columns;
  ruspma_matrix *new_matrix = 
    new_matrix_size(new_rows, new_columns);

  double **new_matrix_row_pointer = new_matrix->matrix;
  int j;
  //go through each row in the new matrix
  for(j = 0; j != new_rows; ++j) {   
    double *new_matrix_element_pointer = *new_matrix_row_pointer;
    int e;
    //go through each element in the row
    for(e = 0; e != new_columns; ++e) {
      double **matrix2_row_pointer = matrix2->matrix;
      double *matrix2_element_pointer = *matrix2_row_pointer;
      //go to matrix1's current row
      double *matrix1_element_pointer = *(matrix1->matrix + j);
      double sum = 0;
      int i;
      //go through each element in matrix1's current row
      for(i = 0; i != matrix1_columns; ++i) {
	sum += *matrix1_element_pointer * *(*matrix2_row_pointer + e);
	++matrix1_element_pointer;
	//go the next row in current column in matrix2
	++matrix2_row_pointer;
      }
      *new_matrix_element_pointer = sum;
      ++new_matrix_element_pointer;
    }
    ++new_matrix_row_pointer;
  }
  return new_matrix;
}
