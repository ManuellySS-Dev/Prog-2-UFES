#include <stdio.h>
#include "vetor.h"
#include <stdlib.h>

typedef int (*Operation)(int, int);

void LeVetor(Vetor *vetor){
    int tamanho=0, i=0;
    scanf("%d\n", &tamanho);
    vetor->tamanhoUtilizado = tamanho;

    for(i=0; i<tamanho; i++){
        scanf(" %d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i=0;
    int resultado = vetor->elementos[0];
    for(i=1; i<vetor->tamanhoUtilizado; i++){
        resultado = op(resultado, vetor->elementos[i]);
    }

    return resultado;
}