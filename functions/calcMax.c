#include "../matrix.h"

//Função que calcula a soma maxima dos valores sem repetir linha ou coluna
int calcMax(Matrix *matrix, int rows, int cols) {
    int totalSum = 0;

    while (rows > 0 && cols > 0) {
        // Encontrar o maior valor na matriz
        int maxVal = INT_MIN;
        int maxRow, maxCol;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix->data[i][j] > maxVal) {
                    maxVal = matrix->data[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }

        // Adicionar o maior valor a soma total
        totalSum += maxVal;

        // Remover a linha e a coluna onde o maior valor esta localizado
        for (int i = maxRow; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                matrix->data[i][j] = matrix->data[i + 1][j];
            }
        }
        for (int j = maxCol; j < cols - 1; j++) {
            for (int i = 0; i < rows; i++) {
                matrix->data[i][j] = matrix->data[i][j + 1];
            }
        }

        // Atualizar o numero de linhas e colunas
        rows--;
        cols--;
    }

    return totalSum;
}
