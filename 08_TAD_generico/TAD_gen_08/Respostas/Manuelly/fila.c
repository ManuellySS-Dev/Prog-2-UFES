#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "movel.h"
#include "fila.h"

struct Fila{
    Vector * vetor;
};

Fila *FilaConstruct(){
    Fila * fila = (Fila*) calloc(1, sizeof(Fila));
    fila->vetor = VectorConstruct();
    return fila;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)){
    VectorDestroy(f->vetor, destroy);
    free(f);
}

int FilaSize(Fila *f){
    return VectorSize(f->vetor);
}

DataType FilaPop(Fila *f){
    return VectorPopFront(f->vetor);
}

void FilaPush(Fila *f, DataType val){
    VectorPushBack(f->vetor, val);
}