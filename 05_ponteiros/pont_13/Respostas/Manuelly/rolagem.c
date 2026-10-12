#include "rolagem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){
    char vet_mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsgs=0, tamanho_total=0, i=0, j=0, indice=0;
    
    FuncMsg(vet_mensagens, &numMsgs);
    char msgs_concatenadas[TAM_MAX_MSG * numMsgs];
    msgs_concatenadas[0] = '\0'; //pra parar de descontar valgrind precisa inicializar o concatenado com caracter neutro
    for(i=0; i<numMsgs; i++){
        strcat(msgs_concatenadas, vet_mensagens[i]);
    }
    tamanho_total = strlen(msgs_concatenadas);
    i=0;
    for(i=0; i<tempoFim; i++){
        for(j=i; j<(tamanhoDisplay+i); j++){
            indice=0;
            if(j>=tamanho_total){
                indice=j-tamanho_total;
            }else{
                indice=j;
            }
            printf("%c", msgs_concatenadas[indice]);
            indice++;
        }
        printf("\n");
        printf("\033[H\033[J");
    }
}