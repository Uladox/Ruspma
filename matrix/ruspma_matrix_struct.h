#ifndef RUSPMA_MATRIX_STRUCT_H
#define RUSPMA_MATRIX_STRUCT_H

typedef struct ruspma_matrix
{
  int rows;
  int columns;
  double **matrix;
}ruspma_matrix;

#endif
