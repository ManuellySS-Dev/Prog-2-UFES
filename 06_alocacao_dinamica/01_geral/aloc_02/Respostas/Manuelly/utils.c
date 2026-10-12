#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
//Nao entendi como alocar a matriz nesse caso com a funcao voltando ** tah dando erro de compilacao vou perguntar ao thiago ou a algum monitor
int **CriaMatriz(int linhas, int colunas){
    int (*matriz)[colunas] = malloc(linhas * colunas * sizeof(int));
    if(matriz == NULL){
        exit(0);
    }
    int ** matrizz = matriz; //tentando passar o ponteiro da matriz para um ponteiro pra ponteiro pra retornar ponteiro pra ponteiro mas nao vaiiiiiii
    return matrizz;
}

void LiberaMatriz(int **matriz, int linhas){
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
