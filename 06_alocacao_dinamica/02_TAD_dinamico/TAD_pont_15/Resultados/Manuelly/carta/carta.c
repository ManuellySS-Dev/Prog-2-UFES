#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

tCarta LeCarta(){
    tCarta carta = (tCarta) calloc(1, sizeof(struct carta));
    if(carta == NULL){
        exit(0);
    }
    carta->nome = (char*) calloc(MAX_NOME, sizeof(char));
    scanf(" %d\n %[^\n]\n %d %d %d\n", &carta->id, carta->nome, &carta->magia, &carta->ataque, &carta->fogo);
    return carta;
}

void LiberaCarta(tCarta c){
    free(c->nome);
    free(c);
}

void ImprimeCarta(tCarta c){
    printf("%s\n", c->nome);
}

int GetIdCarta(tCarta c){
    return c->id;
}

char * GetNomeCarta(tCarta c){
    return c->nome;
}

int GetNumVitCarta(tCarta c){
    return c->num_vit;
}

int GetMagiaCarta(tCarta c){
    return c->magia;
}

int GetAtaqueCarta(tCarta c){
    return c->ataque;
}

int GetFogoCarta(tCarta c){
    return c->fogo;
}

bool EhCartaValida(tCarta c){
    if(c->ataque > 30 || c->magia>30 || c->fogo >30 || (c->ataque+c->magia+c->fogo)>80){
        return false;
    }else{
        return true;
    }
}

bool EhMesmoIdCarta(tCarta c1, tCarta c2){
    if(c1->id == c2->id){
        return true;
    }else{
        return false;
    }
}

int ComparaIdCarta(tCarta c1, tCarta c2){
    printf("%s %s\n", c1->nome, c2->nome);
    if(c1->id > c2->id){
        return 10;
    }else if(c1->id == c2->id){
        return 0;
    }else{
        return -11;
    }
}

int ComparaMagiaCarta(tCarta c1, tCarta c2){
    if(c1->magia > c2->magia){
        return 10;
    }else if(c1->magia == c2->magia){
        return 0;
    }else{
        return -11;
    }
}

int ComparaAtaqueCarta(tCarta c1, tCarta c2){
    if(c1->ataque > c2->ataque){
        return 10;
    }else if(c1->ataque == c2->ataque){
        return 0;
    }else{
        return -11;
    }
}

int ComparaFogoCarta(tCarta c1, tCarta c2){
    if(c1->fogo < c2->fogo){
        return 1;
    }else if(c1->fogo == c2->fogo){
        return 0;
    }else{
        return -1;
    }
}

int AdicionaVitoriaCarta(tCarta c){
    c->num_vit = c->num_vit+1;
    return c->num_vit;
}