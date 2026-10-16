#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
//Nao entendi como alocar a matriz nesse caso com a funcao voltando ** tah dando erro de compilacao vou perguntar ao thiago ou a algum monitor
int **CriaMatriz(int linhas, int colunas) {
    int i = 0;
    int **matriz = (int**) malloc(linhas * sizeof(int*)); 
    
    if (matriz == NULL) return NULL; 

    for(i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    
    return matriz;
}

void LiberaMatriz(int **matriz, int linhas){
    int i=0;
    for(i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas){
    int i=0, j=0;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    int i=0, j=0;
    int mat_trans[colunas][linhas];
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            mat_trans[j][i] = matriz[i][j];
        }
    }
    for(i=0; i<colunas; i++){
        for(j=0; j<linhas; j++){
            printf("%d ", mat_trans[i][j]);
        }
        printf("\n");
    }

}
