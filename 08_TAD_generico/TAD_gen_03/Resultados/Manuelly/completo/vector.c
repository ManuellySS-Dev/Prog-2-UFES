#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

struct Vector{
    data_type * vetor;
    int tamanho;
};

Vector *VectorConstruct(){
    Vector * vector = (Vector*) calloc(1, sizeof(Vector));
    vector->vetor = NULL;
    vector->tamanho = 0;
    return vector;
}

void VectorPushBack(Vector *v, data_type val){
    data_type * temp = (data_type*) realloc(v->vetor, ((v->tamanho+1) *sizeof(data_type)));
    if(temp == NULL){
        exit(0);
    }
    v->vetor = temp;
    v->vetor[v->tamanho] = val;
    v->tamanho++;
}

data_type VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i=0; i<v->tamanho; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}