#include "../matrix.h"

//Função criada para carregar a matriz predefinida na matriz de dados
void loadPredefinedMatrix(Matrix *matrix) {

    //Verifica se a estrutura da matriz e a matriz com os dados dados sao validas
    if (matrix != NULL && matrix->data != NULL) {

        //Copia os valores da matriz predefinida para a matriz de dados
        for (int i = 0; i < matrix->rows; i++) {
            for (int j = 0; j < matrix->cols; j++) {
                matrix->data[i][j] = predefinedMatrix[i][j];
            }
        }
    }
}
