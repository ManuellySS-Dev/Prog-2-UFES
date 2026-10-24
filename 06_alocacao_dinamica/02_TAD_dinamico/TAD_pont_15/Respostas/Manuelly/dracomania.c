#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

tDracomania CriaDracomania(){
    tDracomania d = (tDracomania) calloc(1, sizeof(struct dracomania));
    d->maxcartas = 50;
    d->maxduelos = 50;
    d->listacartas = (tCarta*) calloc(d->maxcartas, sizeof(tCarta));
    d->listaduelos = (tDuelo*) calloc(d->maxduelos, sizeof(tDuelo));
    return d;
}

tDracomania RodaDracomania(tDracomania d){
    char operacao = '\0';
    int c1,c2, i=0, j=0, achou=0, eh_mesma=0;
    tCarta carta;

    while(1){
        scanf("%c\n", &operacao);
        if(operacao == 'C'){
            carta = LeCarta();
            eh_mesma=0;
                for(i=0; i<d->qtdcartas; i++){
                    if(EhMesmoIdCarta(carta, d->listacartas[i])){
                        d->listacartas[i]->ataque = carta->ataque;
                        d->listacartas[i]->fogo = carta->fogo;
                        d->listacartas[i]->magia = carta->magia;
                        LiberaCarta(carta);
                        eh_mesma=1;
                        break;
                    }
                }
            if(eh_mesma==0){
                d->listacartas[d->qtdcartas] = carta;
                    
                if(EhCartaValida(d->listacartas[d->qtdcartas])){
                    d->qtdcartas++;
                }else{
                    d->descartes++;
                    LiberaCarta(d->listacartas[d->qtdcartas]);
                }
            }
        }else if(operacao == 'L'){
            d->listaduelos[d->qtdduelos] = LeDuelo();
            achou=0;
            for(i=0; i<d->qtdcartas; i++){
                if(GetC1Duelo(d->listaduelos[d->qtdduelos]) == d->listacartas[i]->id){
                    c1 = i;
                    achou=1;
                    break;
                }
            }
            if(achou==0){
                d->descartes++;
            }
            achou=0;
            for(j=0; j<d->qtdcartas; j++){
                if(GetC2Duelo(d->listaduelos[d->qtdduelos]) == d->listacartas[j]->id){
                    c2 =j;
                    achou=1;
                    break;
                }
            }
            if(achou==0){
                d->descartes++;
            }
            RealizaDuelo(d->listaduelos[d->qtdduelos], d->listacartas[c1],d->listacartas[c2]);
            d->qtdduelos++;
        }else if(operacao == 'F'){
            break;
        }
    }
    return d;
}

void ImprimeRelatorioDracomania(tDracomania d){
    int desempates=0, vitoriosa=0, i=0, maior_dif = -1000, mais_vitorias=-100, luta_maior_dif=0;
    for(i=0; i<d->qtdduelos; i++){
        if(GetDiferencaDuelo(d->listaduelos[i]) > maior_dif){
            maior_dif = GetDiferencaDuelo(d->listaduelos[i]);
            luta_maior_dif = d->listaduelos[i]->id;
        }
    }
    for(i=0; i<d->qtdcartas; i++){
        if(GetNumVitCarta(d->listacartas[i]) > mais_vitorias){
            vitoriosa=i;
            mais_vitorias = GetNumVitCarta(d->listacartas[i]);
        }
    }
    for(i=0; i<d->qtdduelos; i++){
        if(GetDesempateDuelo(d->listaduelos[i])){
            desempates++;
        }
    }
    if(d->qtdduelos >0){
        printf("Quantidade de Cartas: %d\nQuantidade de descartadas: %d\nQuantidade de lutas: %d\nLutas que foram desempatadas: %d\nCarta mais vitoriosa: %s\nLuta com Maior Diferença: %d\n", d->qtdcartas, d->descartes, d->qtdduelos, desempates, d->listacartas[vitoriosa]->nome, luta_maior_dif);
    }else{
        printf("Quantidade de Cartas: %d\nQuantidade de descartadas: %d\nQuantidade de lutas: %d\n", d->qtdcartas, d->descartes, d->qtdduelos);
    }
}

void LiberaDracomania(tDracomania d){
    int i=0;
    for(i=0; i<d->qtdcartas; i++){
        LiberaCarta(d->listacartas[i]);
    }
    free(d->listacartas);
    for(i=0; i<d->qtdduelos; i++){
        LiberaDuelo(d->listaduelos[i]);
    }
    free(d->listaduelos);
    free(d);
}