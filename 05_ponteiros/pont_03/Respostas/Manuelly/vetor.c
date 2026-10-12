#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam){
    int i=0;
    for(i=0; i<tam; i++){
        scanf("%d ", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    int i=0;
    for(i=0; i<tam; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    int i=0;
    int indiceMenor = *paraTrocar; 

    for (i = *paraTrocar + 1; i < tam; i++) {
        if (vet[i] < vet[indiceMenor]) {
            indiceMenor = i; 
        }
    }

    if (indiceMenor != *paraTrocar) {
        int aux = vet[*paraTrocar];
        vet[*paraTrocar] = vet[indiceMenor];
        vet[indiceMenor] = aux;
    }
}

void OrdeneCrescente(int * vet, int tam) {
    int i;
    
    for (i = 0; i < tam - 1; i++) {
        int posAtual = i;
        TrocaSeAcharMenor(vet, tam, &posAtual);
    }
}