#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int actions(Matrix *matrix){
    int caso;
    int row, col, ele, ad;


    printf("\nPrecione 1 para alterar um elemento especifico na Matriz;\nPrecione 2 para alterar o numero de linhas ou de coluas;\n  ");
    scanf("%d", &caso);
    

    switch (caso){
        case 1:

            printf("Infome: Linha | Coluna | Valor - ");
            scanf("%d", &row);

            printf(" | ");
            scanf("%d", &col);

            printf(" | ");
            scanf("%d", &ele);

            setMatrixElement(matrix, row, row, ele);
            showMatrix(matrix);
        break;
        case 2:
            printf("Digite [1] se pretende adicionar Linhas | Digite [2] se pretende adicionar Colunas: ");
            scanf("%d", &ad);

            if(ad == 1){
                printf("Quantas linhas deseja adicionar: ");
                scanf("%d", &row);

                addRows(matrix, row);
                showMatrix(matrix);
            } else{
                printf("Quantas colunas deseja adicionasr: ");
                scanf("%d", &col);

                addCols(matrix, col);
                showMatrix(matrix);
            }
        break;
    
        default:
        break;
    }

    return caso;
}