#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"
#include "candidato.h"
#include "eleicao.h"
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}

tCandidato LeCandidato(){
    tCandidato candidato;
    candidato.votos = 0;
    scanf("\n%[^,], ", candidato.nome);
    scanf("%[^,], ", candidato.partido);
    scanf("%c, ", &candidato.cargo);
    scanf("%d\n", &candidato.id);
    candidato = CriaCandidato (candidato.nome, candidato.partido, candidato.cargo, candidato.id);
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    }
    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if(candidato1.id == candidato2.id){
        return 1;
    }
   return 0;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos = candidato.votos+1;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual = 0, total=0;
    total= totalVotos;
    percentual = (candidato.votos * 100.0)/ total;
    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s ", candidato.nome);
    printf("(%s), ", candidato.partido);
    printf("%d voto(s), ", candidato.votos);
    printf("%.2f%%\n", percentualVotos);
}