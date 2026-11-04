#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

struct Vector{
    DataType * vetor;
    int tamanho;
};

Vector *VectorConstruct(){
    Vector * vector = (Vector*) calloc(1, sizeof(Vector));
    vector->vetor = NULL;
    vector->tamanho = 0;
    return vector;
}

void VectorPushBack(Vector *v, DataType val){
    DataType * temp = (DataType*) realloc(v->vetor, ((v->tamanho+1) *sizeof(DataType)));
    if(temp == NULL){
        exit(0);
    }
    v->vetor = temp;
    v->vetor[v->tamanho] = val;
    v->tamanho++;
}

DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i=0; i<v->tamanho; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}