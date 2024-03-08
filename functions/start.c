#include "../matrix.h"

//Função criada para deixar a main clean
int start(){
    //Chamando a função que cria a matriz e atribuindo a ela um apontador do tipo "Matrix"
    Matrix *matrix = createMatrix(5, 5);

    //Verifica se a matriz foi criada com sucesso
    if (matrix == NULL) { 
        printf("Erro ao criar a matriz.\n");
        return 1;
    }
    
    //"Carrega" a matrix predefinida na matrix criada
    loadPredefinedMatrix(matrix);
    
    //Mostra a matrix no console
    showMatrix(matrix);

    //Esta função foi criada para ter uma boa interação do sistema com o usuario
    actions(matrix);

    //Esta função ira "destruir" a matriz, liberando todo o espaço na memoria que foi alocado para ela
    destroyMatrix(matrix);
    
    return 0;
}