#include "matrix.h"

//Função que adiciona quatas linhas desejadas na matriz predefinida e adiciona 0 em seus dados
Matrix *addRows(Matrix *matrix, int numRowsToAdd) {
    int newRows = matrix->rows + numRowsToAdd;
    int cols = matrix->cols;

    // Aloca memória para a nova matriz expandida
    int **newData = (int **)malloc(newRows * sizeof(int *));
    if (newData == NULL) {
        printf("Erro ao alocar memória para a nova matriz.\n");
        return NULL;
    }

    // Copia os elementos da matriz original para a nova matriz
    for (int i = 0; i < matrix->rows; i++) {
        newData[i] = (int *)malloc(cols * sizeof(int));
        if (newData[i] == NULL) {
            printf("Erro ao alocar memória para a nova matriz.\n");
            // Libera a memória alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(newData[j]);
            }
            free(newData);
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            newData[i][j] = matrix->data[i][j];
        }
    }

    // Inicializa as novas linhas adicionadas com zeros
    for (int i = matrix->rows; i < newRows; i++) {
        newData[i] = (int *)calloc(cols, sizeof(int));
        if (newData[i] == NULL) {
            printf("Erro ao alocar memória para a nova matriz.\n");
            // Libera a memória alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(newData[j]);
            }
            free(newData);
            return NULL;
        }
    }

    // Libera a memória alocada para a matriz original
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);

    // Atribui a nova matriz expandida à estrutura Matrix
    matrix->rows = newRows;
    matrix->data = newData;

    return matrix;
}

//Função que adiciona quatas colunas desejadas na matriz predefinida e adiciona 0 em seus dados
Matrix *addCols(Matrix *matrix, int numColsToAdd) {
    int rows = matrix->rows;
    int newCols = matrix->cols + numColsToAdd;

    // Aloca memória para cada linha da matriz expandida
    for (int i = 0; i < rows; i++) {
        // Realoca a linha atual para acomodar as novas colunas
        int *newRow = (int *)realloc(matrix->data[i], newCols * sizeof(int));
        if (newRow == NULL) {
            printf("Erro ao alocar memória para a nova matriz.\n");
            // Libera a memória alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            return NULL;
        }
        // Atualiza a referência para a linha na matriz
        matrix->data[i] = newRow;

        // Preenche as novas colunas com zeros
        for (int j = matrix->cols; j < newCols; j++) {
            matrix->data[i][j] = 0;
        }
    }

    // Atualiza o número de colunas na matriz
    matrix->cols = newCols;

    return matrix;
}
