#include "../matrix.h"

//Função criada para uma melhor interação entre o codigo e o usuario
int actions(Matrix *matrix) {
    //Variaveis declaradas "globalmente" nesta função pois dentro dos cases nao é possivel
    int choice, option, row, col, val, numRowsToAdd, numColsToAdd, numRowsToRemove, numColsToRemove, totalSum;
    
    // Exibir as opções para o usuario
    printf("\nEscolha uma opcao:\n");

    printf("1. Alterar um elemento especifico na matriz\n");
    printf("2. Adicionar linhas ou colunas\n");
    printf("3. Remover linhas ou colunas\n");
    printf("4. Calcular a soma maxima Rows|Cols\n");

    //Le a opção que o usuario deseja
    printf("Opcao: ");
    scanf("%d", &choice);
    
    //Switch criado para que qual seja a opção do usuario ira apenas trabalhar naquela opção
    switch (choice) {
        case 1:
            // Altera um elemento especifico na matriz
            printf("\nInforme a linha, coluna e o novo valor:\n");
            
            //Le a linha que quer alterar
            printf("Linha: ");
            scanf("%d", &row);

            //Le a coluna que quer alterar
            printf("Coluna: ");
            scanf("%d", &col);

            //Le o valor que quer alocar no local anteriormente selecionado
            printf("Novo valor: ");
            scanf("%d", &val);

            //Chama função que faz esta alteração, passando a matrix carregada, a linha, a coluna e o valor que deseja alocar
            setMatrixElement(matrix, row, col, val);
            break;
        
        case 2:
            // Adiciona linhas ou colunas
            printf("\nEscolha o que deseja adicionar:\n");
            
            printf("1. Adicionar linhas\n");
            printf("2. Adicionar colunas\n");

            //Le a opção que o usuario deseja
            printf("Opcao: ");
            scanf("%d", &option);

            //Se o usuario deseja alterar linhas ira entrar neste if
            if (option == 1) {
                
                //le a quantidade de linhas que deseja adicionar
                printf("Quantas linhas deseja adicionar: ");
                scanf("%d", &numRowsToAdd);
                
                //Chama função que adiciona linhas novas, passando a matrix carregada e o numero de linhas que quer adicionar
                addRows(matrix, numRowsToAdd);

            } 
            //Se o usuario deseja alterar colunas ira entrar neste if
            else if (option == 2) {

                //le a quantidade de colunas que deseja adicionar
                printf("Quantas colunas deseja adicionar: ");
                scanf("%d", &numColsToAdd);

                //Chama função que adiciona colunas novas, passando a matrix carregada e o numero de colunas que quer adicionar
                addCols(matrix, numColsToAdd);

            } 
            //Se escolher uma opcao invalida irar mostrar este ERRO
            else {
                printf("Opcao invalida!\n");
            }
            break;
        
        case 3:
            // Deleta linhas ou colunas
            printf("\nEscolha o que deseja remover:\n");

            printf("1. Remover linhas\n");
            printf("2. Remover colunas\n");

            //Le a opção que o usuario deseja
            printf("Opcao: ");            
            scanf("%d", &option);

            //Se o usuario deseja alterar linhas ira entrar neste if
            if (option == 1) {

                //le a quantidade de linhas que deseja deletar
                printf("Quantas linhas deseja remover: ");
                scanf("%d", &numRowsToRemove);

                //Chama função que deleta linhas novas, passando a matrix carregada e o numero de linhas que quer deletar
                deleteRows(matrix, numRowsToRemove);

            } 
            //Se o usuario deseja alterar colunas ira entrar neste if
            else if (option == 2) {

                //le a quantidade de colunas que deseja deletar
                printf("Quantas colunas deseja remover: ");
                scanf("%d", &numColsToRemove);

                //Chama função que deleta colunas novas, passando a matrix carregada e o numero de colunas que quer deletar
                deleteCols(matrix, numColsToRemove);

            }
            //Se escolher uma opcao invalida irar mostrar este ERRO
            else {
                printf("Opcao invalida!\n");
            }
            break;
        case 4:
            //Calcula a soma maxima Linhas || Colunas

            //Variavel que recebe a função que faz o calculo maximo
            //Esta função recebe a matrix predefinida, as linhas e as colunas e o endereço para o total somado

            //int totalSum;
            totalSum = calcMax(matrix, matrix->rows, matrix->cols);

            printf("\nA soma maxima possivel dos inteiros na matriz que nao compartilham Linhas || Colunas eh: |%d|\n", totalSum);
        break;

        //Se o usuario nao selecionar uma opcao valida ira cair no default
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
