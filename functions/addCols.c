#include "../matrix.h"

//Função que adiciona quatas colunas desejadas na matriz predefinida e adiciona 0 em seus dados
Matrix *addCols(Matrix *matrix, int numColsToAdd) {
    //Variavel criada para receber a matriz ja existente + a quantidade de colunas que quer adicionar
    int rows = matrix->rows;
    int newCols = matrix->cols + numColsToAdd;

    // Aloca memoria para cada linha da matriz expandida
    for (int i = 0; i < rows; i++) {
        // Realoca a linha atual para acomodar as novas colunas
        int *newRow = (int *)realloc(matrix->data[i], newCols * sizeof(int));
        if (newRow == NULL) {
            printf("Erro ao alocar memoria para a nova matriz.\n");
            // Libera a memoria alocada anteriormente
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
