#include "utils_char.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//funcoes
char *CriaVetor(int tamanho){
    char *vetor = (char*) malloc(tamanho*sizeof(char));
    int i=0;
    for(i=0; i<tamanho; i++){
        vetor[i] = '_';
    }
    return vetor;
}

void LeVetor(char *vetor, int tamanho){
    int i=0;
    char caracter ='\0';
    for(i=0; i<tamanho; i++){
        scanf("%c", &caracter);
        if(caracter != '\n'){
            vetor[i] = caracter;
        }
    }
}

void ImprimeString(char *vetor, int tamanho){
    int i=0;
    for(i=0; i<tamanho; i++){
        printf("%c", vetor[i]);
    } 
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}