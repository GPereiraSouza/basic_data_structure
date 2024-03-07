#include "../matrix.h"


Matrix *createMatrix(int rows, int cols) {
    // Aloca memória para a estrutura Matrix
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        printf("Erro: falha na alocação de memória para a matriz.\n");
        return NULL;
    }

    // Define o número de linhas e colunas da matriz
    matrix->rows = rows;
    matrix->cols = cols;

    // Aloca memória para a matriz de dados
    matrix->data = (int**)malloc(rows * sizeof(int*));
    if (matrix->data == NULL) {
        printf("Erro: falha na alocação de memória para a matriz de dados.\n");
        free(matrix); // Libera a memória alocada para a estrutura Matrix
        return NULL;
    }

    // Aloca memória para cada linha da matriz
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
        if (matrix->data[i] == NULL) {
            printf("Erro: falha na alocação de memória para a linha %d da matriz.\n", i);
            // Libera a memória alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    // Inicializa a matriz de dados com zeros (opcional)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = 0;
        }
    }

    return matrix;
}
