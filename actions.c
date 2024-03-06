#include "matrix.h"

int actions(Matrix *matrix) {
    int choice, option, row, col, val, numRowsToAdd, numColsToAdd, numRowsToRemove, numColsToRemove, totalSum;
    
    // Exibir as opções para o usuário
    printf("\nEscolha uma opcao:\n");

    printf("1. Alterar um elemento especifico na matriz\n");
    printf("2. Adicionar linhas ou colunas\n");
    printf("3. Remover linhas ou colunas\n");
    printf("4. Calcular a soma maxima Rows|Cols\n");

    printf("Opcao: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            // Alterar um elemento específico na matriz
            printf("\nInforme a linha, coluna e o novo valor:\n");
            
            printf("Linha: ");
            scanf("%d", &row);

            printf("Coluna: ");
            scanf("%d", &col);

            printf("Novo valor: ");
            scanf("%d", &val);

            setMatrixElement(matrix, row, col, val);
            break;
        
        case 2:
            // Adicionar linhas ou colunas
            printf("\nEscolha o que deseja adicionar:\n");
            
            printf("1. Adicionar linhas\n");
            printf("2. Adicionar colunas\n");

            printf("Opcao: ");
            scanf("%d", &option);

            if (option == 1) {

                printf("Quantas linhas deseja adicionar: ");
                scanf("%d", &numRowsToAdd);

                addRows(matrix, numRowsToAdd);

            } else if (option == 2) {
                int numColsToAdd;

                printf("Quantas colunas deseja adicionar: ");
                scanf("%d", &numColsToAdd);

                addCols(matrix, numColsToAdd);

            } else {
                printf("Opcao invalida!\n");
            }
            break;
        
        case 3:
            // Remover linhas ou colunas
            printf("\nEscolha o que deseja remover:\n");

            printf("1. Remover linhas\n");
            printf("2. Remover colunas\n");

            printf("Opcao: ");            
            scanf("%d", &option);

            if (option == 1) {

                printf("Quantas linhas deseja remover: ");
                scanf("%d", &numRowsToRemove);

                deleteRows(matrix, numRowsToRemove);

            } else if (option == 2) {
                int numColsToRemove;

                printf("Quantas colunas deseja remover: ");
                scanf("%d", &numColsToRemove);

                deleteCols(matrix, numColsToRemove);

            } else {
                printf("Opcao invalida!\n");
            }
            break;
        case 4:
            //Calcular a soma maxima Linhas | Colunas
            totalSum = calcMax(matrix, matrix->rows, matrix->cols, &totalSum);


            printf("\nA soma maxima possivel dos inteiros na matriz que nao compartilham linhas ou colunas eh: |%d|\n", totalSum);
        break;

        default:
            printf("Opcao invalida!\n");
            break;
    }
    
    // Exibir a matriz após as alterações
    printf("\nMatriz atualizada:\n");
    showMatrix(matrix);
    
    // Retorna a escolha do usuário
    return choice;
}
