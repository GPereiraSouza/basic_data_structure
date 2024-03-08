#include "../matrix.h"

// Função para alterar um elemento especifico na matriz
void setMatrixElement(Matrix *matrix, int row, int col, int value) {

    // Verifica se a estrutura da matriz e a matriz de dados são validas
    if (matrix != NULL && matrix->data != NULL) {

        // Verifica se os indices da linha e coluna estao dentro dos limites da matriz
        if (row > 0 && row <= matrix->rows && col > 0 && col <= matrix->cols) {

            // Atualiza o valor do elemento na posição especificada e mostra qual foi o elemento alterado
            matrix->data[row - 1][col - 1] = value;
            printf("\nElemento [%d][%d] atualizado para %d\n", row, col, value);
        }
        //se os indices nao forem validos ira mostrar este erro 
        else {
            printf("Erro: Indices de linha ou coluna fora dos limites da matriz.\n");
        }
    } 
    //Se a verificação for invalida ira mostrar este erro
    else {
        printf("Erro: Matriz inválida.\n");
    }
}
