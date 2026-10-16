#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix* MatrixCreate(int rows, int cols){
    tMatrix * matrix = (tMatrix*) calloc(1, sizeof(tMatrix*));
    int i = 0;
    matrix->data = (int**) malloc(rows * sizeof(int*)); 
    
    if (matrix->data == NULL){
        exit(0);
    }

    for(i = 0; i < rows; i++) {
        matrix->data[i] = (int*) malloc(cols * sizeof(int));
    }    
    matrix->cols = cols;
    matrix->rows = rows;
    return matrix;
}

void MatrixFree(tMatrix* matrix){
    int i=0;
    for(i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    } 
    free(matrix->data);
    free(matrix);
}

void MatrixRead(tMatrix* matrix){
    int i=0, j=0;
    for(i=0; i<matrix->rows; i++){
        for(j=0; j<matrix->cols; j++){
            scanf("%d", &matrix->data[i][j]); //tentar com &
        }
    }
}

void MatrixPrint(tMatrix* matrix){
    int i=0, j=0;
    for(i=0; i<matrix->rows; i++){
        for(j=0; j<matrix->cols; j++){
            printf(" %d", matrix->data[i][j]);
        }
    }
}

int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows){
        return 1;
    }else{
        return 0;
    }
}

int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows){
        return 1;
    }else{
        return 0;
    }
}

int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(matrix1->cols == matrix2->rows){
        return 1;
    }else{
        return 0;
    }
}

tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix * Soma;
    Soma = MatrixCreate(matrix1->rows, matrix1->cols);
    int i=0, j=0;
    for(i=0; i<matrix1->rows; i++){
        for(j=0; j<matrix1->cols; j++){
            Soma->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return Soma;
}

tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix * Sub;
    Sub = MatrixCreate(matrix1->rows, matrix1->cols);
    int i=0, j=0;
    for(i=0; i<matrix1->rows; i++){
        for(j=0; j<matrix1->cols; j++){
            Sub->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return Sub;
}

tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix * Mult;
    Mult = MatrixCreate(matrix1->rows, matrix1->cols);
    int i=0, j=0;
    for(i=0; i<matrix1->rows; i++){
        for(j=0; j<matrix1->cols; j++){
            Mult->data[i][j] = matrix1->data[i][j] * matrix2->data[i][j];
        }
    }
    return Mult;
}

tMatrix* TransposeMatrix(tMatrix* matrix){
    tMatrix * Trans;
    Trans = MatrixCreate(matrix->cols, matrix->rows);
    int i=0, j=0;
    for(i=0; i<matrix->rows; i++){
        for(j=0; j<matrix->cols; j++){
            Trans->data[i][j] = matrix->data[j][i];
        }
    }
    return Trans;
}

tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    tMatrix * Mult;
    Mult = MatrixCreate(matrix->rows, matrix->cols);
    int i=0, j=0;
    for(i=0; i<matrix->rows; i++){
        for(j=0; j<matrix->cols; j++){
            Mult->data[i][j] = matrix->data[i][j] * scalar;
        }
    }
    return Mult;
}

