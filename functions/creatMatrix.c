#include "../matrix.h"

//Função criada para alocar memoria para a estrutura da matrix e para os dados da matrix
Matrix *createMatrix(int rows, int cols) {
    // Aloca memoria para a estrutura Matrix
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));

    //Verifica se a alocação de memoria para a estrutura teve sucesso
    if (matrix == NULL) {
        printf("Erro: falha na alocação de memoria para a matriz.\n");
        return NULL;
    }

    // Define o número de linhas e colunas da matriz, conforme os parametros recebidos
    matrix->rows = rows;
    matrix->cols = cols;

    // Aloca memória para a matriz de dados
    matrix->data = (int**)malloc(rows * sizeof(int*));

    //Verifica se a alocação de memoria para os dados da matrix teve sucesso
    if (matrix->data == NULL) {
        printf("Erro: falha na alocação de memória para a matriz de dados.\n");
        free(matrix); // Libera a memória alocada para a estrutura Matrix
        return NULL;
    }

    // Iteração para alocar memoria para cada linha da matriz
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));

        //Verifica se a alocação teve sucesso e se nao teve sucesso vai liberar a memoria alocada anteriormente
        if (matrix->data[i] == NULL) {
            printf("Erro: falha na alocação de memoria para a linha %d da matriz.\n", i);

            //Iteração para liberar as colunas alocadas anteriormente
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}
