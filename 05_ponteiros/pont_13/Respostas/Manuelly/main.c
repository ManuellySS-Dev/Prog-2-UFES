#include "rolagem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void leMensagens(char vet_mensagens[NUM_MAX_MSGS][TAM_MAX_MSG], int * num_mensagens){
    scanf(" %d", num_mensagens);
    int i=0;
    for(i=0; i< (*num_mensagens); i++){
        scanf(" %[^\n]", vet_mensagens[i]);
    }
}

int main(){
    int tamanhodisplay=30, tempofim=0;
    scanf("%d", &tempofim);
    RolaMsg(leMensagens, tamanhodisplay, tempofim);
    return 0;
}