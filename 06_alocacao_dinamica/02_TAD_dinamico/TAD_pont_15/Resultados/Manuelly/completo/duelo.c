#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

tDuelo LeDuelo(){
    tDuelo d = (tDuelo) calloc(1, sizeof(struct duelo));
    scanf("%d\n %d %d %c\n", &d->id, &d->c1, &d->c2, &d->atributo);
    return d;
}

void LiberaDuelo(tDuelo d){
    free(d);
}

void ImprimeDuelo(tDuelo d){
    printf(" ");
}

void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2){
    if(EhCartaValida(c1) && EhCartaValida(c2)){
        if(d->atributo == 'G'){
            if(!ComparaFogoCarta(c1,c2)){
                if(ComparaIdCarta(c1,c2)>0){
                    d->vencedor = d->c1;
                    AdicionaVitoriaCarta(c1);
                }else{
                    d->vencedor = d->c2;
                AdicionaVitoriaCarta(c2);
                }
                d->desempate=1;
            }else if(ComparaFogoCarta(c1,c2)>0){
                d->diferenca = GetFogoCarta(c2) - GetFogoCarta(c1);
                d->vencedor = d->c2;
                AdicionaVitoriaCarta(c2);
            }else if(ComparaFogoCarta(c1,c2)<0){
                d->diferenca = GetFogoCarta(c1) - GetFogoCarta(c2);
                d->vencedor = d->c1;
                AdicionaVitoriaCarta(c1);
            }
        }else if(d->atributo == 'M'){
            if(!ComparaMagiaCarta(c1,c2)){
                if(ComparaIdCarta(c1,c2)>0){
                    d->vencedor = d->c1;
                    AdicionaVitoriaCarta(c1);
                }else{
                    d->vencedor = d->c2;
                AdicionaVitoriaCarta(c2);
                }
                d->desempate=1;
            }else if(ComparaMagiaCarta(c1,c2)>0){
                d->diferenca = GetMagiaCarta(c1) - GetMagiaCarta(c2);
                d->vencedor = d->c1;
                AdicionaVitoriaCarta(c1);
            }else{
                d->diferenca = GetMagiaCarta(c2) - GetMagiaCarta(c1);
                d->vencedor = d->c2;
                AdicionaVitoriaCarta(c2);
            }
        }else{
            if(!ComparaAtaqueCarta(c1,c2)){
                if(ComparaIdCarta(c1,c2)>0){
                    d->vencedor = d->c1;
                    AdicionaVitoriaCarta(c1);
                }else{
                    d->vencedor = d->c2;
                    AdicionaVitoriaCarta(c2);
                }
                d->desempate=1;
            }else if(ComparaAtaqueCarta(c1,c2)>0){
                d->diferenca = GetAtaqueCarta(c1) - GetAtaqueCarta(c2);
                d->vencedor = d->c1;
                AdicionaVitoriaCarta(c1);
            }else{
                d->diferenca = GetAtaqueCarta(c2) - GetAtaqueCarta(c1);
                d->vencedor = d->c2;
                AdicionaVitoriaCarta(c2);
            }
        }
    }
}

int GetC1Duelo(tDuelo d){
    return d->c1;
}

int GetC2Duelo(tDuelo d){
    return d->c2;
}

bool GetDesempateDuelo(tDuelo d){
    return d->desempate;
}

int GetDiferencaDuelo(tDuelo d){
    return d->diferenca;
}

int GetIdDuelo(tDuelo d){
    return d->id;
}