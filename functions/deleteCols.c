#include "../matrix.h"

//Função que deleta as colunas desejadas da matriz predefinida, recebendo a matriz predefinida e o numero de colunas
Matrix *deleteCols(Matrix *matrix, int colstoDelete) {
    // Variavel para armazenar o novo número de colunas
    int colsDelete = matrix->cols - colstoDelete;
    int rows = matrix->rows;

    // Se todas as colunas forem removidas, defina a matriz como nula
    if (colsDelete == 0) {
        matrix->data = NULL;
        printf("\n |MATRIZ == NULL| \n");
        return NULL;
    } else {
        // Realoca memoria para a nova matriz reduzida
        for (int i = 0; i < rows; i++) {
            int *newRow = (int *)realloc(matrix->data[i], colsDelete * sizeof(int));

            // Se a realocação der erro, retorne NULL
            if (newRow == NULL) {
                printf("Erro ao realocar memoria para a nova matriz.\n");
                return NULL;
            }
            // Atualiza a referencia para a linha na matriz
            matrix->data[i] = newRow;
        }
    }

    // Atualiza o numero de colunas na matriz
    matrix->cols = colsDelete;

    return matrix;
}
