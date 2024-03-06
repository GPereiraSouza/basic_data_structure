#include "matrix.h"

// Função para alterar um elemento específico na matriz
void setMatrixElement(Matrix *matrix, int row, int col, int value) {
    // Verifica se a matriz e a matriz de dados são válidas
    if (matrix != NULL && matrix->data != NULL) {
        // Verifica se os índices da linha e coluna estão dentro dos limites da matriz
        if (row > 0 && row <= matrix->rows && col > 0 && col <= matrix->cols) {
            // Atualiza o valor do elemento na posição especificada
            matrix->data[row - 1][col - 1] = value;
            printf("\nElemento [%d][%d] atualizado para %d\n", row, col, value);
        } else {
            printf("Erro: Indices de linha ou coluna fora dos limites da matriz.\n");
        }
    } else {
        printf("Erro: Matriz inválida.\n");
    }
}
