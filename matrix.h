#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix{
    int rows;
    int cols;
    int **data;
} Matrix;

extern int predefinedMatrix[5][5];

int actions();
Matrix *createMatrix(int rows, int cols);
void loadPredefinedMatrix(Matrix *matrix);
void showMatrix(Matrix *matrix);
void destroyMatrix(Matrix *matrix);
Matrix *addRows(Matrix *matrix, int numRowsToAdd);
Matrix *addCols(Matrix *matrix, int numRowsToAdd);
Matrix *removeRowsCols(Matrix *matrix);
Matrix *printMatrix(Matrix *matrix);
Matrix *calcRowsCols(Matrix *matrix, int *totalSum);

#endif