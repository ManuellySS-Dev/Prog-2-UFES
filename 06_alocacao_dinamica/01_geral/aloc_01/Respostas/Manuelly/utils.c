#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
//funcoes
int *CriaVetor(int tamanho){
    int * vetor = (int*) malloc (tamanho * sizeof(int));
    return vetor;
}

void LeVetor(int *vetor, int tamanho){
    int i=0;
    for(i=0; i<tamanho; i++){
        scanf(" %d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    int i=0;
    float somatorio=0;
    for(i=0; i<tamanho; i++){
        somatorio+= vetor[i];
    }
    return (somatorio/tamanho);
}

void LiberaVetor(int *vetor){
    free(vetor);
}