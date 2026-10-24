#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc){
    Paciente * paciente = (Paciente*) calloc(1, sizeof(Paciente));
    if(paciente == NULL){
        exit(0);
    }
    strcpy(paciente->cartaoSus, cartaoSus);
    strcpy(paciente->nome, nome);
    paciente->genero = genero;
    paciente->dataNasc = dataNasc;
    paciente->numLesoes = 0;
    return paciente;
}

Paciente *lerPaciente(){
    char nome[MAX_NOME_PAC]; 
    char cartao[MAX_CARTAO_SUS];
    char genero = '\0';
    Data *data;

    // Removido o \n do final para evitar travamentos na leitura
    scanf(" %[^\n]", nome);
    data = lerData();
    scanf(" %[^\n]", cartao);
    scanf(" %c", &genero); // Espaço antes de %c ignora espaçamentos anteriores

    return criaPaciente(nome, cartao, genero, data);
}

void vinculaLesaoPaciente(Paciente *p, Lesao *l){
    p->lesoes[p->numLesoes] = l;
    p->numLesoes++;
}

int qtdLesoesCirurgicasPaciente(Paciente *p){
    int i = 0, malignas = 0;
    for(i = 0; i < p->numLesoes; i++){
        if(verificaCirurgicaLesao(p->lesoes[i])){
            malignas++;
        }
    }
    return malignas;
}

int calculaIdadePaciente(Paciente *p, Data *dataBase){
    return diferencaAnoData(p->dataNasc, dataBase);
}

char *getCartaoSusPaciente(Paciente *p){
    return p->cartaoSus;
}

int getNumLesoesPaciente(Paciente *p){
    return p->numLesoes;
}

void imprimePaciente(Paciente *p){
        int i;
    if(p->numLesoes >0){ //se o paciente nao tem lesao nao sera impresso
        printf("- %s - ", p->nome);
        for(i = 0; i < p->numLesoes; i++){
            imprimeIdLesao(p->lesoes[i]);
        }
        printf("\n");
    }
}

void liberaPaciente(Paciente *p){
    int i = 0;
    liberaData(p->dataNasc);
    for(i = 0; i < p->numLesoes; i++){
        liberaLesao(p->lesoes[i]);
    }
    free(p);
}