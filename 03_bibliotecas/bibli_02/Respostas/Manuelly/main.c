#include <stdio.h>
#include "matrix_utils.h"

int main(){
    int opcao_escolhida = 0, rows1=0, cols1=0, rows2=0, cols2=0, scalar=0, matriz_a_ser_multiplicada=0;
    //matriz 1
    scanf("%d %d\n", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    //matriz 2
    scanf("%d %d\n",&rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    while(opcao_escolhida != 6){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d\n", &opcao_escolhida);

        if(opcao_escolhida == 1){
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }else if(opcao_escolhida == 2){
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }else if(opcao_escolhida == 3){

            if(possible_matrix_multiply(cols1, rows2)){
                int result[rows2][cols1];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }else if(opcao_escolhida == 4){
            scanf("%d %d\n", &scalar, &matriz_a_ser_multiplicada);
            if(matriz_a_ser_multiplicada == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }else{
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }else if(opcao_escolhida == 5){
            int result_1[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result_1);
            matrix_print(cols1, rows1, result_1);
            int result_2[cols1][rows1];
            transpose_matrix(rows2, cols2, matrix2, result_2);
            matrix_print(cols2, rows2, result_2); //mandando cols e rows na ordem inversa
        }
    }

    return 0;
}