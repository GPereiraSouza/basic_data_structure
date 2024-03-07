#include "../matrix.h"

Matrix *deleteCols(Matrix *matrix, int colstoDelete) {
    int colsDelete = matrix->cols - colstoDelete;
    int rows = matrix->rows;

    // Aloca memória para a nova matriz expandida
    int **newData = (int **)malloc(rows * sizeof(int *));
    if (newData == NULL) {
        printf("Erro ao alocar memória para a nova matriz.\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        newData[i] = (int *)malloc(colsDelete * sizeof(int));
        if (newData[i] == NULL) {
            printf("Erro ao alocar memória para a nova matriz.\n");
            // Libera a memória alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(newData[j]);
            }
            free(newData);
            return NULL;
        }
        // Copia os elementos da matriz original para a nova matriz, ignorando as colunas que devem ser excluídas
        int newColIndex = 0; // Índice da coluna na nova matriz
        for (int j = 0; j < matrix->cols; j++) {
            if (j != colstoDelete) {
                newData[i][newColIndex] = matrix->data[i][j];
                newColIndex++;
            }
        }
    }

    // Libera a memória alocada para a matriz original
    for (int i = 0; i < rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);

    // Atribui a nova matriz expandida à estrutura Matrix
    matrix->cols = colsDelete;
    matrix->data = newData;

    return matrix;
}
