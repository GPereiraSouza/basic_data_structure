#include "../matrix.h"

//Função que libera todo o espaço alocado/realocado da memoria
void destroyMatrix(Matrix *matrix) {
    // Verifica se a matriz é valida
    if (matrix != NULL) {
        // Libera a memória alocada para cada linha da matriz
        for (int i = 0; i < matrix->rows; i++) {
            free(matrix->data[i]);
        }
        
        // Libera a memoria alocada para a matriz de dados
        free(matrix->data);

        // Libera a memoria alocada para a estrutura Matrix
        free(matrix);
    }
}
