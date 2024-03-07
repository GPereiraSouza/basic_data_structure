#include "../matrix.h"

void showMatrix(Matrix *matrix) {
    // Itera sobre cada linha da matriz
    for (int i = 0; i < matrix->rows; i++) {
        // Imprime a borda esquerda da linha
        printf("+");
        
        // Itera sobre cada elemento da linha
        for (int j = 0; j < matrix->cols; j++) {
            // Imprime o valor do elemento e adiciona espaçamento para alinhamento
            printf(" %3d ", matrix->data[i][j]);
            
            // Se não for a última coluna, imprime a barra vertical
            if (j < matrix->cols - 1) {
                printf("|");
            }
        }
        
        // Imprime a borda direita da linha
        printf("+\n");
    }
}
