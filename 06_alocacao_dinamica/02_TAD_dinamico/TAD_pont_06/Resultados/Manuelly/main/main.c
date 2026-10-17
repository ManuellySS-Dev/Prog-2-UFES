#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main(){
    int linhas1=0, colunas1=0, linhas2=0, colunas2=0,opcao=0, escalar=0, qual_matriz=0;
    tMatrix * matrix1;
    tMatrix * matrix2;

    scanf("%d %d", &linhas1, &colunas1);
    matrix1 = MatrixCreate(linhas1, colunas1);
    MatrixRead(matrix1);
    scanf("%d %d", &linhas2, &colunas2);
    matrix2 = MatrixCreate(linhas2, colunas2);
    MatrixRead(matrix2);

    while(opcao != 6){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &opcao);
        if(opcao == 1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                tMatrix * resultado;
                resultado = MatrixAdd(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(opcao == 2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                tMatrix * resultado;
                resultado = MatrixSub(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(opcao == 3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                tMatrix * resultado;
                resultado = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }else if(opcao == 4){
            scanf("%d %d", &escalar, &qual_matriz);
            if(qual_matriz == 1){
                tMatrix * resultado = MatrixMultiplyByScalar(matrix1, escalar);
                MatrixFree(matrix1); // Libera a matriz antiga para nao vazar
                matrix1 = resultado;
                MatrixPrint(matrix1);
            }else{
                tMatrix * resultado = MatrixMultiplyByScalar(matrix2, escalar);
                MatrixFree(matrix2); // Libera a matriz antiga para nao perder o endereco dela quando eu passar o de resultado pra ela guardar
                matrix2 = resultado;
                MatrixPrint(matrix2); 
            }
        }else if(opcao == 5){
                tMatrix * resultado1;
                resultado1 = TransposeMatrix(matrix1);
                MatrixPrint(resultado1);
                MatrixFree(resultado1);
                tMatrix * resultado2;
                resultado2 = TransposeMatrix(matrix2);
                MatrixPrint(resultado2);
                MatrixFree(resultado2);
        }
    }
    //nao preciso apagar o resultado do escalar porque o endereco dele foi passado pra uma das matrizes entao apontam pro mesmo espaco na memoria
    //se eu fizer copia de um ponteiro como os dois apontam pro mesmo espaco na memoria eu soh preciso dar free em um que vai desalocar o espaco e nao a variavel em si
    MatrixFree(matrix1);
    MatrixFree(matrix2);
    return 0;
}