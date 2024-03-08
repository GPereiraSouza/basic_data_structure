#include "../matrix.h"

//Função que deleta as linhas desejadas da matriz predefinida, recebendo a matriz predefinida e o numero de linhas
Matrix *deleteRows(Matrix *matrix, int rowsToDelete) {
    //Variavel para armazenar o novo numero de linhas
    int rows = matrix->rows - rowsToDelete;
    int cols = matrix->cols;

    // Realoca memoria para a nova matriz reduzida
    int **newData = (int **)realloc(matrix->data, rows * sizeof(int *));

    //Se a realocaçao der erro ira aparecer esse erro
    if (newData == NULL) {
        printf("Erro ao realocar memoria para a nova matriz.\n");
        return NULL;
    }

    // Atualiza o numero de linhas na matriz
    matrix->rows = rows;
    matrix->data = newData;

    return matrix;
}
