#include "../matrix.h"

//Função que adiciona quatas linhas desejadas na matriz predefinida e adiciona 0 em seus dados
Matrix *addRows(Matrix *matrix, int numRowsToAdd) {
    // Variavel para armazenar o novo numero de linhas
    int newRows = matrix->rows + numRowsToAdd;
    int cols = matrix->cols;

    // Realoca a matriz para acomodar as novas linhas
    int **newData = (int **)realloc(matrix->data, newRows * sizeof(int *));

    //Se a realocação der erro ira aparecer esse erro
    if (newData == NULL) {
        printf("Erro ao alocar memoria para a nova matriz.\n");
        return NULL;
    }

    // Inicializa as novas linhas adicionadas com zeros
    for (int i = matrix->rows; i < newRows; i++) {
        newData[i] = (int *)calloc(cols, sizeof(int));
        if (newData[i] == NULL) {
            printf("Erro ao alocar memoria para a nova matriz.\n");
            // Libera a memória alocada anteriormente
            for (int j = matrix->rows; j < i; j++) {
                free(newData[j]);
            }
            free(newData);
            return NULL;
        }
    }

    // Atualiza a estrutura Matrix com os novos dados
    matrix->rows = newRows;
    matrix->data = newData;

    return matrix;
}
