#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "franquia.h"
#include "nba.h"
#include "partida.h"

tPartida LePartida(){
    //tPartida jah eh ponteiro e foi declarado como ponteiro no .h
    tPartida partida = (tPartida) calloc(1, sizeof(struct partida)); //tem que colocar struct no sizeof porque nao usaram typedf pra declarar a struct
    partida->time1 = (char*) calloc(100, sizeof(char));
    partida->time2 = (char*) calloc(100, sizeof(char));
    scanf(" %[^ ] @ %[^ ] %d %d\n", partida->time1, partida->time2, &partida->pontos1, &partida->pontos2);
    return partida;
}

void LiberaPartida(tPartida p){
    free(p->time1);
    free(p->time2);
    free(p);
}

void ImprimePartida(tPartida p){

}

char * GetTime1Partida(tPartida p){
    return  p->time1;
}

char * GetTime2Partida(tPartida p){
    return p->time2;
}

int GetVencedorPartida(tPartida p){
    if(p->pontos1 > p->pontos2){
        return TIME_CASA;
    }else if(p->pontos1 < p->pontos2){
        return TIME_FORA;
    }else{
        return 0;
    }
}