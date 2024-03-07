#include "../matrix.h"

//Função que deleta a linha desejada da matriz predefinida
Matrix *deleteRows(Matrix *matrix, int rowstoDelete){
    int rowsDelete = matrix->rows - rowstoDelete;
    int cols = matrix->cols;

    //Aloca memória para a nova matriz expandida
    int **newData = (int **)malloc(rowsDelete * sizeof(int *));
    if(newData == NULL){
        printf("Erro ao alocar memória para a nova matriz.\n");
        return NULL;
    }

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
    
     // Libera a memória alocada para a matriz original
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);

    // Atribui a nova matriz expandida à estrutura Matrix
    matrix->rows = rowsDelete;
    matrix->data = newData;

    return matrix;
}
