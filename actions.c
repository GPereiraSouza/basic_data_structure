#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int actions(Matrix *matrix){
    int caso;
    int row, col, ele, ad;


    printf("\n|Precione 1 para alterar um elemento especifico na Matriz|\n|Precione 2 para adicionar linhas ou colunas|\n |Precione 3 para remover linhas ou colunas|\n ");
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
            destroyMatrix(matrix);
        break;
        case 2:
            printf("Digite [1] se pretende adicionar Linhas | Digite [2] se pretende adicionar Colunas: ");
            scanf("%d", &ad);

            if(ad == 1){
                printf("Quantas linhas deseja adicionar: ");
                scanf("%d", &row);

                addRows(matrix, row);
                showMatrix(matrix);
                destroyMatrix(matrix);
            } else{
                printf("Quantas colunas deseja adicionar: ");
                scanf("%d", &col);

                addCols(matrix, col);
                showMatrix(matrix);
                destroyMatrix(matrix);
            }
        break;
        case 3:
            printf("Digite [1] se pretende remover Linhas | Digite [2] se pretende remover Colunas: ");
            scanf("%d", &ad);

            if(ad == 1){
                printf("Quantas linhas deseja remover: ");
                scanf("%d", &row);

                deleteRows(matrix, row);
                showMatrix(matrix);
                destroyMatrix(matrix);
            }else{
                printf("Quantas colunas deseja remover: ");
                scanf("%d", &col);

                deleteCols(matrix, col);
                showMatrix(matrix);
                destroyMatrix(matrix);
            }
        break;
    
        default:
        break;
    }

    return caso;
}