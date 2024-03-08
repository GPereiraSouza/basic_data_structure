#include "../matrix.h"

//Função que deleta as colunas desejadas da matriz predefinida, recebendo a matriz predefinida e o numero de colunas
Matrix *deleteCols(Matrix *matrix, int colstoDelete) {
    //Variavel para armazenar o novo numero de colunas
    int colsDelete = matrix->cols - colstoDelete;
    int rows = matrix->rows;

    // Realoca memória para a nova matriz expandida
    for (int i = 0; i < rows; i++) {
        int *newRow = (int *)realloc(matrix->data[i], colsDelete * sizeof(int));

        //Se a realocação der erro ira aparecer esse erro 
        if (newRow == NULL) {
            printf("Erro ao realocar memoria para a nova matriz.\n");
            // Libera a memoria alocada anteriormente
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            return NULL;
        }
        // Atualiza a referencia para a linha na matriz
        matrix->data[i] = newRow;
    }

    // Atualiza o numero de colunas na matriz
    matrix->cols = colsDelete;

    return matrix;
}
