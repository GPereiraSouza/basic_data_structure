#include "../matrix.h"

//Função que calcula a soma dos maiores valores sem repetir linhas ou colunas
int calcMax(Matrix *matrix, int rows, int cols, int *totalSum) {
    int maxSumWithoutSharing = 0;

    // Itera pelas células da matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calcula a soma máxima considerando apenas os valores que não compartilham linha ou coluna
            int sum = matrix->data[i][j];
            if (i > 0) {
                sum += matrix->data[i - 1][j];
            }
            if (j > 0) {
                sum += matrix->data[i][j - 1];
            }
            if (i > 0 && j > 0) {
                sum -= matrix->data[i - 1][j - 1];
            }

            // Atualiza a soma máxima encontrada até o momento
            if (sum > maxSumWithoutSharing) {
                maxSumWithoutSharing = sum;
            }
        }
    }

    return maxSumWithoutSharing;
}
