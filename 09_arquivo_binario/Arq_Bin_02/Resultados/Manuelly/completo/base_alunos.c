#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "base_alunos.h"

struct BaseAlunos{
    int qtd_alunos;
    tAluno ** alunos;
};

tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos * base = (tBaseAlunos*) calloc(1, sizeof(tBaseAlunos));
    return base;
}

void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for(int i=0; i<baseAlunos->qtd_alunos; i++){
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE * arq = fopen(nomeArquivo, "rb");
    fread(&baseAlunos->qtd_alunos, sizeof(int), 1, arq);
    baseAlunos->alunos = (tAluno**) calloc(baseAlunos->qtd_alunos, sizeof(tAluno*));
    for(int i=0; i<baseAlunos->qtd_alunos; i++){
        baseAlunos->alunos[i]= LeAluno(arq);
    }
    fclose(arq);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float media=0;
    for(int i=0; i<baseAlunos->qtd_alunos; i++){
        media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return media/baseAlunos->qtd_alunos;
}