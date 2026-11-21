#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

struct Vector{
    DataType * vetor;
    int qtd_elementos;
};

Vector *VectorConstruct(){
    Vector * vet = (Vector*) calloc(1, sizeof(Vector));
    vet->vetor = NULL;
    return vet;
}

void VectorPushBack(Vector *v, DataType val){
    v->vetor = (DataType*) realloc(v->vetor, (v->qtd_elementos +1) * sizeof(DataType));
    v->vetor[v->qtd_elementos] = val;
    v->qtd_elementos++;
}

void VectorRemove(Vector *v, int i){
    v->vetor[i] = NULL;
    for(int j=i; j<v->qtd_elementos-1; j++){
        v->vetor[j] = v->vetor[j+1];
    }
    v->qtd_elementos--;
    v->vetor[v->qtd_elementos] = NULL; //liberando ultima posicao do vetor
}

DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->qtd_elementos;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i=0; i<v->qtd_elementos; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}