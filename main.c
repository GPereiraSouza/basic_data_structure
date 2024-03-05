#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {  
    Matrix *matrix = createMatrix(5, 5);
        if (matrix == NULL) { 
            printf("Erro ao criar a matriz.\n");
            return 1;
        }
    
    loadPredefinedMatrix(matrix);
    
    showMatrix(matrix);

    destroyMatrix(matrix);
    
    return 0;
}
