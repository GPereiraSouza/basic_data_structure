#include "../matrix.h"
#include <stdio.h>
#include <stdlib.h>

void destroyMatrix(Matrix *matrix) {
    // Verifica se a matriz é válida
    if (matrix != NULL) {
        // Libera a memória alocada para cada linha da matriz
        for (int i = 0; i < matrix->rows; i++) {
            free(matrix->data[i]);
        }
        
        // Libera a memória alocada para a matriz de dados
        free(matrix->data);

        // Libera a memória alocada para a estrutura Matrix
        free(matrix);
    }
}
