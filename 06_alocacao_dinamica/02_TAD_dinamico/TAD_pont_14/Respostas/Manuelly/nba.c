#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "franquia.h"
#include "nba.h"
#include "partida.h"

tNBA CriaNBA(){
    tNBA nba = (tNBA) calloc(1, sizeof(struct nba));
    nba->listafranquias = (tFranquia*) calloc(MAX_FR, sizeof(tFranquia));
    nba->listapartidas = (tPartida*) calloc(MAX_PT, sizeof(tPartida));
    return nba;
}

tNBA RodaNBA(tNBA nba){
    int num_franquias_l=0, num_partidas=0, i=0;
    char operacao='\0';

    while(scanf("%c\n", &operacao) == 1){
        if(operacao == CAD_FRANQUIA){
            nba->listafranquias[nba->qtdfranquias] = LeFranquia();
            nba->qtdfranquias++;
        }else if(operacao == CAD_PARTIDA){
            nba->listapartidas[nba->qtdpartidas] = LePartida();
            if(GetVencedorPartida(nba->listapartidas[nba->qtdpartidas]) == TIME_CASA){
                for(i=0; i<nba->qtdfranquias; i++){
                    if(!strcmp(nba->listapartidas[nba->qtdpartidas]->time1, nba->listafranquias[i]->nome)){
                        AdicionaVitoriaCasaFranquia(nba->listafranquias[i]);
                    }
                }
                for(i=0; i<nba->qtdfranquias; i++){
                    if(!strcmp(nba->listapartidas[nba->qtdpartidas]->time2, nba->listafranquias[i]->nome)){
                        AdicionaDerrotaForaFranquia(nba->listafranquias[i]);
                    }
                }
            }else{
               for(i=0; i<nba->qtdfranquias; i++){
                    if(!strcmp(nba->listapartidas[nba->qtdpartidas]->time2, nba->listafranquias[i]->nome)){
                        AdicionaVitoriaForaFranquia(nba->listafranquias[i]);
                    }
                }
                for(i=0; i<nba->qtdfranquias; i++){
                    if(!strcmp(nba->listapartidas[nba->qtdpartidas]->time1, nba->listafranquias[i]->nome)){
                        AdicionaDerrotaCasaFranquia(nba->listafranquias[i]);
                    }
                }
            }
            nba->qtdpartidas++;
        }else if(operacao == ENCERRAR){
            break;
        }
    }
    return nba;
}

void ImprimeRelatorioNBA(tNBA nba){
    int i=0, derrotas_leste=0, derrotas_oeste=0, vitorias_leste=0, vitorias_oeste=0;
    float aproveiramente_leste=0, aproveiramente_oeste=0;
    for(i=0; i<nba->qtdfranquias; i++){
        ImprimeFranquia(nba->listafranquias[i]);
        if(!strcmp(GetConferenciaFranquia(nba->listafranquias[i]), "LESTE")){
            vitorias_leste+= GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]);
            derrotas_leste+= GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]);
        }else{
            vitorias_oeste+= GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]);
            derrotas_oeste+= GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]);
        }
    }
    if((vitorias_leste+derrotas_leste)>0){
        aproveiramente_leste = ((vitorias_leste*100.0)/(vitorias_leste+derrotas_leste))*1.0;
    }
    if((vitorias_oeste+derrotas_oeste>0)){
        aproveiramente_oeste = ((vitorias_oeste*100.0)/(vitorias_oeste+derrotas_oeste))*1.0;
    }
    printf("LESTE %d %d %.2f\n", vitorias_leste, derrotas_leste, aproveiramente_leste);
    printf("OESTE %d %d %.2f\n", vitorias_oeste, derrotas_oeste, aproveiramente_oeste);
}

void LiberaNBA(tNBA nba){
    int i=0;
    for(i=0; i<nba->qtdfranquias; i++){
        LiberaFranquia(nba->listafranquias[i]);
    }
    free(nba->listafranquias);
    for(i=0; i<nba->qtdpartidas; i++){
        LiberaPartida(nba->listapartidas[i]);
    }
    free(nba->listapartidas);
    free(nba);
}