#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"

#define TAM_MAX_NOME 100
#define TAM_MAX_PARTIDO 100

tCandidato* CriaCandidato(){
    tCandidato * candidato = (tCandidato*) calloc(1, sizeof(tCandidato));
    candidato->nome = (char*) calloc(TAM_MAX_NOME, sizeof(char));
    candidato->partido = (char*) calloc(TAM_MAX_PARTIDO, sizeof(char));
    candidato->id = 0;
    candidato->votos = 0;
    return candidato;
}

void ApagaCandidato(tCandidato* candidato){
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

void LeCandidato(tCandidato *candidato){
    scanf(" %[^,],", candidato->nome);
    scanf(" %[^,],", candidato->partido);
    scanf(" %c,", &candidato->cargo);
    scanf(" %d", &candidato->id);
}

int VerificaIdCandidato(tCandidato *candidato, int id){
    if(candidato->id == id){
        return 1;
    }else{
        return 0;
    }
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2){
    return VerificaIdCandidato(candidato1, candidato2->id);
}

char ObtemCargo(tCandidato* candidato){
    return candidato->cargo;
}

void IncrementaVotoCandidato(tCandidato* candidato){
    candidato->votos = candidato->votos+1;
}

int ObtemVotos(tCandidato* candidato){
    return candidato->votos;
}

float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){
    return ((candidato->votos *100.0)/totalVotos);
}

void ImprimeCandidato (tCandidato* candidato, float percentualVotos){
    printf("%s", candidato->nome);
    printf(" (%s), ", candidato->partido);
    printf("%d voto(s), %.2f%%\n", candidato->votos, percentualVotos);
}