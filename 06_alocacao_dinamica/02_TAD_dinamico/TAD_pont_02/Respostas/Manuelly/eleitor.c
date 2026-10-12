#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"

tEleitor* CriaEleitor(){
    tEleitor * eleitor = (tEleitor*) calloc(1, sizeof(tEleitor)); //aloca memoria pra um eleitor
    //calloc inicializa ponteiros internos com NULL mas as variaveis numericas com 0 como a biblioteca pede -1 eu vou fazer manualmente
    eleitor->id = -1;
    eleitor->votoG = -1;
    eleitor->votoP = -1;
    return eleitor;
}

void ApagaEleitor(tEleitor* eleitor){
    free(eleitor);
}

void LeEleitor(tEleitor *eleitor){
    scanf("%d %d %d", &eleitor->id, &eleitor->votoP, &eleitor->votoG);
    //printf("%d %d %d\n", eleitor->id, eleitor->votoG, eleitor->votoP);
}

int ObtemVotoPresidente(tEleitor* eleitor){
    //printf("%d\n", eleitor->votoP);
    return eleitor->votoP;
}

int ObtemVotoGovernador(tEleitor* eleitor){
    return eleitor->votoG;
}

int EhMesmoEleitor(tEleitor* eleitor1, tEleitor* eleitor2){
    if(eleitor1->id == eleitor2->id){
        return 1;
    }
    return 0;
}