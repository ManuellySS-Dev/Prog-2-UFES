#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Vector{
    DataType * vet;
    int qtd_elementos;
};

Vector *VectorConstruct(){
    Vector * vetor = (Vector*) calloc(1, sizeof(Vector));
    vetor->vet = NULL;
    return vetor;
}

void VectorPushBack(Vector *v, DataType val){
    v->vet = (DataType*) realloc(v->vet, (v->qtd_elementos+1)* sizeof(DataType));
    v->vet[v->qtd_elementos] = val;
    v->qtd_elementos++;
}

DataType VectorGet(Vector *v, int i){
    return v->vet[i];
}

int VectorSize(Vector *v){
    return v->qtd_elementos;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i=0; i<v->qtd_elementos; i++){
        destroy(v->vet[i]);
    }
    free(v->vet);
    free(v);
}
