#include "matrix_utils.h"
#include <stdio.h>

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}
tMatrix MatrixRead(tMatrix matrix){
    int linha=0, coluna=0;
    for(linha=0; linha<matrix.rows; linha++){
        for(coluna=0; coluna<matrix.cols; coluna++){
            scanf(" %d", &matrix.data[linha][coluna]);
        }
        scanf("\n");
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix){
    int linha=0, coluna=0;
    for(linha=0; linha<matrix.rows; linha++){
        printf("|");
        for(coluna=0; coluna<matrix.cols; coluna++){
            if(coluna < (matrix.cols-1)){
                printf("%d ", matrix.data[linha][coluna]);
            }else{
                printf("%d", matrix.data[linha][coluna]);  
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1; //eh possivel somar
    }else{
        return 0; //nao eh possivel somar
    }
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    return PossibleMatrixSum(matrix1, matrix2); //mesmas condicoes pra substrair e somar matrizes
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }else{
        return 0;
    }
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    int linha=0, coluna=0;
    tMatrix result;
    result.cols = matrix2.cols;
    result.rows = matrix1.rows;

    for(linha=0; linha<matrix1.rows; linha++){
        for(coluna=0; coluna<matrix1.cols; coluna++){
            result.data[linha][coluna] = (matrix1.data[linha][coluna] + matrix2.data[linha][coluna]);
        }
    }
    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    int linha=0, coluna=0;
    tMatrix result;
    result.cols = matrix2.cols;
    result.rows = matrix1.rows;

    for(linha=0; linha<matrix1.rows; linha++){
        for(coluna=0; coluna<matrix1.cols; coluna++){
            result.data[linha][coluna] = (matrix1.data[linha][coluna] - matrix2.data[linha][coluna]);
        }
    }
    return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    int linha=0, coluna=0, i=0;
    tMatrix result;
    result.cols = matrix2.cols;
    result.rows = matrix1.rows;
    for(linha=0; linha<matrix1.rows; linha++){
        for(coluna=0; coluna<matrix2.cols; coluna++){
            result.data[linha][coluna] = 0; //Como eu to usando += para somar os produtos que formam os elementos eu preciso primeiro zerar a posicao que essa soma vai ocupar ou entao esa assumiria valores advindos do buffer e somaria a eles
            for(i=0; i<matrix2.rows; i++){ 
                    result.data[linha][coluna] += (matrix1.data[linha][i] * matrix2.data[i][coluna]);
            }
        }
    }
    return result;
}

tMatrix TransposeMatrix(tMatrix matrix){
    int linha=0, coluna=0;
    tMatrix result;
    result.cols = matrix.rows;
    result.rows = matrix.cols;   
    for(linha=0; linha<matrix.rows; linha++){
        for(coluna=0; coluna<matrix.cols; coluna++){
            result.data[coluna][linha] = matrix.data[linha][coluna];
        }
    }
    return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    int linha=0, coluna=0;
    for(linha=0; linha<matrix.rows; linha++){
        for(coluna=0; coluna<matrix.cols; coluna++){
            matrix.data[linha][coluna] = matrix.data[linha][coluna] * scalar;
        }
    }
    return matrix;
}

