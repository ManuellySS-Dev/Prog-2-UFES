#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"
#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 12

tEleicao* InicializaEleicao(){
    int qtd_candidatos=0, i=0;
    tEleicao * eleicao = (tEleicao*) calloc(1, sizeof(tEleicao));
    eleicao->presidentes = (tCandidato**) calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato*));
    eleicao->governadores = (tCandidato**) calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato*));
    eleicao->eleitores = (tEleitor**) calloc(MAX_ELEITORES, sizeof(tEleitor*));

    tCandidato * candidato; 

    scanf(" %d", &qtd_candidatos);
    for(i=0; i<qtd_candidatos; i++){
        candidato = CriaCandidato();
        LeCandidato(candidato);
        if(ObtemCargo(candidato) == 'P'){
            eleicao->presidentes[eleicao->totalPresidentes] = candidato;
            eleicao->totalPresidentes++;
        }else if(ObtemCargo(candidato) == 'G'){
            eleicao->governadores[eleicao->totalGovernadores] = candidato;
            eleicao->totalGovernadores++;
        }
    }
    return eleicao;
}

void ApagaEleicao(tEleicao* eleicao){
    int i=0;

    if (eleicao->presidentes != NULL) {
        for (i = 0; i < eleicao->totalPresidentes; i++) {
            ApagaCandidato(eleicao->presidentes[i]); // Libera o candidato
        }
        free(eleicao->presidentes); // Libera o vetor de ponteiros
    }

    if (eleicao->governadores != NULL) {
        for (i = 0; i < eleicao->totalGovernadores; i++) {
            ApagaCandidato(eleicao->governadores[i]); // Libera o candidato
        }
        free(eleicao->governadores); // Libera o vetor de ponteiros
    }
    if (eleicao->eleitores != NULL) {
        for (i = 0; i < eleicao->totalEleitores; i++) {
            ApagaEleitor(eleicao->eleitores[i]); // Libera o candidato
        }
        free(eleicao->eleitores); // Libera o vetor de ponteiros
    }
    free(eleicao);
}

void RealizaEleicao(tEleicao* eleicao){
    int qtd_eleitores=0, i=0, j=0, flag_votou=0;
    tEleitor * eleitor;

    scanf(" %d", &qtd_eleitores);
    //le eleitores e preenche o vetor eleitores com eles
    for(i=0; i<qtd_eleitores; i++){
        eleitor = CriaEleitor();
        LeEleitor(eleitor);
        eleicao->eleitores[eleicao->totalEleitores] = eleitor;
        eleicao->totalEleitores++;
    }
    //valida os votos e preenche as variaveis de votos com eles na categoria presidente
    for(i=0; i<qtd_eleitores; i++){
        flag_votou = 0;
        for(j=0; j<eleicao->totalPresidentes; j++){
            if(eleicao->eleitores[i]->votoP == 0){
                eleicao->votosBrancosPresidente++;
                flag_votou =1;
                break;
            }
            if(eleicao->eleitores[i]->votoP == eleicao->presidentes[j]->id){
                eleicao->presidentes[j]->votos++;
                flag_votou =1;
            }
        }
        if(flag_votou == 0){ //se o voto nao foi branco e nem pra nenhum candidato com id salvo entao ele eh nulo
            eleicao->votosNulosPresidente++;
        }
    }
    //valida os votos e preenche as variaveis de votos com eles na categoria governador
    for(i=0; i<qtd_eleitores; i++){
        flag_votou = 0;
        for(j=0; j<eleicao->totalGovernadores; j++){
            if(eleicao->eleitores[i]->votoG == 0){
                eleicao->votosBrancosGovernador++;
                flag_votou =1;
                break;
            }
            if(eleicao->eleitores[i]->votoG == eleicao->governadores[j]->id){
                eleicao->governadores[j]->votos++;
                flag_votou =1;
            }
        }
        if(flag_votou == 0){
            eleicao->votosNulosGovernador++;
        }
    }
    //verifica eleitores duplicados caso um eleitor vote duas vezes a eleicao tem que ser anulada
    for(i=0; i<eleicao->totalEleitores; i++){
        for(j=0; j<eleicao->totalEleitores; j++){
            if(i!=j){
                if(EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])){
                    printf("ELEICAO ANULADA");
                    ApagaEleicao(eleicao);
                    exit(0);
                }
            }
        }
    }
}

void ImprimeResultadoEleicao(tEleicao* eleicao){
    int j=0, indice_gov_mais_votado=0, indice_pres_mais_votado=0, maior_p= -1000,maior_g= -1000, empate_gov=0, empate_pres=0, total_invalidos=0;

    //acha o indice e a quantidade do mais votado
    for(j=0; j<eleicao->totalGovernadores; j++){
        if(eleicao->governadores[j]->votos >maior_g){
            maior_g = eleicao->governadores[j]->votos;
            indice_gov_mais_votado = j;
        }
    }

    //ve se ha empate para o mais votado
    for(j=0; j<eleicao->totalGovernadores; j++){
        if(eleicao->governadores[j]->votos == maior_g){
            if(indice_gov_mais_votado != j){
                empate_gov=1;
            }
        }
    }
    //acha o indice e a quantidade do mais votado

    for(j=0; j<eleicao->totalPresidentes; j++){
        if(eleicao->presidentes[j]->votos >maior_p){
            maior_p = eleicao->presidentes[j]->votos;
            indice_pres_mais_votado = j;
        }
    }

    //ve se ha empate para o mais votado
    for(j=0; j<eleicao->totalPresidentes; j++){
        if(eleicao->presidentes[j]->votos == maior_p){
            if(indice_pres_mais_votado != j){
                empate_pres=1;
            }
        }
    }
    //impressoes presidente
    if(empate_pres ==0 && maior_p > maior_p>= eleicao->votosBrancosPresidente && maior_p>= eleicao->votosNulosPresidente){
        printf("- PRESIDENTE ELEITO: ");
        ImprimeCandidato(eleicao->presidentes[indice_pres_mais_votado], CalculaPercentualVotos(eleicao->presidentes[indice_pres_mais_votado], eleicao->totalEleitores));
    }else if(empate_pres==1){
        printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }else{
        printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
    }
    //impressoes governador
    if(empate_gov ==0 && maior_g>= eleicao->votosBrancosGovernador && maior_g>= eleicao->votosNulosGovernador){
        printf("- GOVERNADOR ELEITO: ");
        ImprimeCandidato(eleicao->governadores[indice_gov_mais_votado], CalculaPercentualVotos(eleicao->governadores[indice_gov_mais_votado], eleicao->totalEleitores));
    }else if(empate_gov ==1){
        printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }else{
        printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
    }
    //imprime votos brancos e nulos
    printf("- NULOS E BRANCOS: %d, %d\n", (eleicao->votosNulosGovernador+eleicao->votosNulosPresidente),(eleicao->votosBrancosGovernador+eleicao->votosBrancosPresidente));
}