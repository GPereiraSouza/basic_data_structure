#include "../matrix.h"

//Função que deleta as linhas desejadas da matriz predefinida, recebendo a matriz predefinida e o numero de linhas
Matrix *deleteRows(Matrix *matrix, int rowsToDelete) {
    //Variavel para armazenar o novo numero de linhas
    int rows = matrix->rows - rowsToDelete;
    int cols = matrix->cols;

    if (rows == 0) {
        // Se todas as linhas forem removidas, defina a matriz como nula
        matrix->data = NULL;
        printf("\n |MATRIZ == NULL| \n");
        return NULL;
    } else {
        // Realoca memoria para a nova matriz reduzida
        int **newData = (int **)realloc(matrix->data, rows * sizeof(int *));
        // Se a realocação der erro, retorne NULL
        if (newData == NULL) {
            printf("Erro ao realocar memoria para a nova matriz.\n");
            return NULL;
        }
        // Atualiza o numero de linhas na matriz
        matrix->rows = rows;
        matrix->data = newData;
    }

    return matrix;
}
