#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "missil.h"
#include "cidade.h"
#include "defesa.h"

struct defesa{
    char nome[3];
    char tipo;
    float x, y, tamanho, poder;
    int quantidade;
};

tDefesa LeDefesa(){
    tDefesa defesa= (tDefesa) calloc(1, sizeof(struct defesa));
    scanf(" %[^ ] ", defesa->nome);
    scanf(" %f", &defesa->x);
    scanf(" %f", &defesa->y);
    scanf(" %c", &defesa->tipo);
    scanf(" %f", &defesa->tamanho);
    scanf(" %f", &defesa->poder);
    scanf(" %d", &defesa->quantidade);

    return defesa;
}

void ImprimeDefesa(tDefesa defesa){
    printf("D-%s: %d\n", defesa->nome, defesa->quantidade);
}

void LiberaDefesa(tDefesa defesa){
    free(defesa);
}

int VerificaSeDentroArea(tDefesa defesa, float x, float y){
    float distancia=0, lado=0;
    if(defesa->tipo == 'C'){
        distancia = sqrt(((defesa->x - x)*(defesa->x - x))+((defesa->y - y)*(defesa->y - y)));
        if(distancia <= defesa->tamanho){
            return 1;
        }else{
            return 0;
        }
    }else if(defesa->tipo == 'Q'){
        distancia = sqrt(((defesa->x - x)*(defesa->x - x))+((defesa->y - y)*(defesa->y - y)));
        if(distancia <= defesa->tamanho){
            return 1;
        }else{
            return 0;
        }   
    }
}

void UsaDefesa(tDefesa defesa){
    defesa->quantidade--;
}

float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}

int PodeDefender(tDefesa defesa){
    if(defesa->quantidade >0){
        return 1;
    }
    return 0;
}