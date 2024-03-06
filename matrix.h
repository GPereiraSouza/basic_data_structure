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

int actions(Matrix *matrix);

Matrix *createMatrix(int rows, int cols);

void loadPredefinedMatrix(Matrix *matrix);

void showMatrix(Matrix *matrix);

void destroyMatrix(Matrix *matrix);

void setMatrixElement(Matrix *matrix, int row, int col, int value);

Matrix *addRows(Matrix *matrix, int numRowsToAdd);

Matrix *addCols(Matrix *matrix, int numColsToAdd);

Matrix *deleteRows(Matrix *matrix, int rowstoDelete);

Matrix *deleteCols(Matrix *matrix, int colstoDelete);

Matrix *calcMax(Matrix *matrix, int *totalSum);

#endif