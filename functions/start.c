#include "../matrix.h"

int start(){
    Matrix *matrix = createMatrix(5, 5);

    if (matrix == NULL) { 
        printf("Erro ao criar a matriz.\n");
        return 1;
    }
    
    loadPredefinedMatrix(matrix);
    
    showMatrix(matrix);

    actions(matrix);
    
    return 0;
}