#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "franquia.h"
#include "nba.h"
#include "partida.h"

tFranquia LeFranquia(){
    tFranquia f = (tFranquia) calloc(1,sizeof(struct franquia));
    f->nome = (char*) calloc(MAX_NOME, sizeof(char));
    f->conferencia = (char*) calloc(100, sizeof(char));
    scanf(" %[^ ] %[^\n]\n", f->nome, f->conferencia);
    return f;
}

void LiberaFranquia(tFranquia f){
    free(f->nome);
    free(f->conferencia);
    free(f);
}

void ImprimeFranquia(tFranquia f){
    if((f->vit_casa+f->vit_fora+f->der_casa+f->der_fora) >0){
        f->aproveitamento = (((f->vit_casa+f->vit_fora)*100.0/(f->vit_casa+f->vit_fora +f->der_casa+f->der_fora)));
    }
    if(!strcmp(f->conferencia, "LESTE")){
        printf("%s [CL] %d %d %.2f %d %d\n", f->nome, (f->vit_casa+f->vit_fora), (f->der_casa+f->der_fora), f->aproveitamento, f->vit_casa, f->vit_fora);
    }else{
        printf("%s [CO] %d %d %.2f %d %d\n", f->nome, (f->vit_casa+f->vit_fora), (f->der_casa+f->der_fora), f->aproveitamento, f->vit_casa, f->vit_fora);  
    }
}

char * GetNomeFranquia(tFranquia f){
    return f->nome;
}

char * GetConferenciaFranquia(tFranquia f){
    return f->conferencia;
}

void AdicionaVitoriaCasaFranquia(tFranquia f){
    f->vit_casa++;
}

void AdicionaVitoriaForaFranquia(tFranquia f){
    f->vit_fora++;
}

void AdicionaDerrotaCasaFranquia(tFranquia f){
    f->der_casa++;
}

void AdicionaDerrotaForaFranquia(tFranquia f){
    f->der_fora++;
}

int GetVitoriaCasaFranquia(tFranquia f){
    return f->vit_casa;
}

int GetVitoriaForaFranquia(tFranquia f){
    return f->vit_fora;
}

int GetDerrotaCasaFranquia(tFranquia f){
    return f->der_casa;
}

int GetDerrotaForaFranquia(tFranquia f){
    return f->der_fora;
}