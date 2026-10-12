#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao_escolhida=0, rows1=0, cols1=0, rows2=0, cols2=0,escalar=0, qual_matriz=0;
    tMatrix matriz1, matriz2, resultado;

    scanf("%d %d\n", &rows1, &cols1);
    matriz1 = MatrixCreate(rows1, cols1);
    matriz1 = MatrixRead(matriz1);
    scanf("%d %d\n", &rows2, &cols2);
    matriz2 = MatrixCreate(rows2, cols2);
    matriz2 = MatrixRead(matriz2);

    while(opcao_escolhida != 6){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        
        scanf("%d\n", &opcao_escolhida);

        if(opcao_escolhida == 1){
            if(PossibleMatrixSum(matriz1, matriz2)){
                resultado = MatrixAdd(matriz1, matriz2);
                MatrixPrint(resultado);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(opcao_escolhida == 2){
            if(PossibleMatrixSub(matriz1, matriz2)){
                resultado = MatrixSub(matriz1, matriz2);
                MatrixPrint(resultado);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(opcao_escolhida == 3){
            if(PossibleMatrixMultiply(matriz1, matriz2)){
                resultado = MatrixMultiply(matriz1, matriz2);
                MatrixPrint(resultado);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        if(opcao_escolhida == 4){
            scanf("%d %d", &escalar, &qual_matriz);
            if(qual_matriz ==1){
                matriz1 = MatrixMultiplyByScalar(matriz1, escalar);
                MatrixPrint(matriz1);
            }else if(qual_matriz==2){
                matriz2 = MatrixMultiplyByScalar(matriz2, escalar);
                MatrixPrint(matriz2);
            }
        }
        if(opcao_escolhida == 5){
            resultado = TransposeMatrix(matriz1);
            MatrixPrint(resultado);
            resultado = TransposeMatrix(matriz2);
            MatrixPrint(resultado);
        }
}
    return 0;
}