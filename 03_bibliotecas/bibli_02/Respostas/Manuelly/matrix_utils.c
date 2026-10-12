#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int linha=0, coluna=0;
    for(linha=0; linha<rows; linha++){
        for(coluna=0; coluna<cols; coluna++){
            scanf(" %d", &matrix[linha][coluna]);
        }
        scanf("\n");
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int linha=0, coluna=0;
    for(linha=0; linha<rows; linha++){
        printf("|");
        for(coluna=0; coluna<cols; coluna++){
            if(coluna < (cols-1)){
                printf("%d ", matrix[linha][coluna]);
            }else{
                printf("%d", matrix[linha][coluna]);  
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2){
        return 1; //eh possivel somar
    }else{
        return 0; //nao eh possivel somar
    }
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    return possible_matrix_sum(rows1, cols1, rows2, cols2); //mesmas condicoes pra substrair e somar matrizes
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }else{
        return 0;
    }
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int linha=0, coluna=0;
    for(linha=0; linha<rows1; linha++){
        for(coluna=0; coluna<cols1; coluna++){
            result[linha][coluna] = (matrix1[linha][coluna] + matrix2[linha][coluna]);
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int linha=0, coluna=0;
    for(linha=0; linha<rows1; linha++){
        for(coluna=0; coluna<cols1; coluna++){
            result[linha][coluna] = (matrix1[linha][coluna] - matrix2[linha][coluna]);
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    int linha=0, coluna=0, i=0;
    for(linha=0; linha<rows1; linha++){
        for(coluna=0; coluna<cols2; coluna++){
            result[linha][coluna] = 0; //Como eu to usando += para somar os produtos que formam os elementos eu preciso primeiro zerar a posicao que essa soma vai ocupar ou entao esa assumiria valores advindos do buffer e somaria a eles
            for(i=0; i<rows2; i++){ 
                    result[linha][coluna] += (matrix1[linha][i] * matrix2[i][coluna]);
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    int linha=0, coluna=0;
    for(linha=0; linha<rows; linha++){
        for(coluna=0; coluna<cols; coluna++){
            result[coluna][linha] = matrix[linha][coluna];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int linha=0, coluna=0;
    for(linha=0; linha<rows; linha++){
        for(coluna=0; coluna<cols; coluna++){
            matrix[linha][coluna] = matrix[linha][coluna] * scalar;
        }
    }
}

