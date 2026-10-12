#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"
//consertar o desconto do valgrind
char *CriaVetorTamPadrao(){
    int i=0;
    char *vet = (char*) malloc(11*sizeof(char));
    for (i = 0; i < 11; i++) {
        vet[i] = '\0';
    }
    for(i=0; i<10; i++){
        vet[i] = '_';
    }
    return vet;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    char *vet = (char *) realloc(vetor, (tamanhoantigo + 10 +1) * sizeof(char)); 
    //tem que criar vet porque se der errado vai retornar null  o realloc
    // eu vou perder o endereco e nao conseguir liberar o vetor e vai vazar na memoria
    if(vet != NULL){
        vetor = vet; //depois eh so igualar o ponteiro temporario com o ponteiro original;
    }
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){
    int i=0, j=0;
    char caractere = '\0';
    while(1){
        scanf("%c", &caractere);
        if(caractere == '\n'){
            vetor[*tamanho] = '\0';
            break;
        }
        vetor[i]= caractere;
        i++;
        if(i == *tamanho){ 
            vetor = AumentaTamanhoVetor(vetor,*tamanho);
            *tamanho +=10;
            for(j=i; j<*tamanho; j++){
                vetor[j] = '_';
            }
        }
    }

    return vetor;
}

void ImprimeString(char *vetor){
    int i=0;
    while(vetor[i] != '\0' && vetor[i]!= '\n'){
        printf("%c", vetor[i]);
        i++;
    }
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}