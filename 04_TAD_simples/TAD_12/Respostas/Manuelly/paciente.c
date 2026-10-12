#include "data.h"
#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"

Paciente criaPaciente(char *nome, char *cartaoSus, char genero, Data dataNasc){
    Paciente paciente;
    strcpy(paciente.nome, nome);
    strcpy(paciente.cartaoSus, cartaoSus);
    paciente.genero = genero;
    paciente.dataNasc = dataNasc;
    paciente.numLesoes=0;
    return paciente;
}

Paciente lerPaciente(){
    Paciente paciente;
    Data data_nasci;
    char nome[MAX_NOME_PAC], cartao[MAX_CARTAO_SUS], genero='\0';
    scanf(" %[^\n]\n", nome);
    data_nasci = lerData();
    scanf(" %[^\n]\n", cartao);
    scanf("%c", &genero);
    paciente = criaPaciente(nome, cartao, genero, data_nasci);
    return paciente;
}

Paciente vinculaLesaoPaciente(Paciente p, Lesao l){
    p.lesoes[p.numLesoes] = l;
    p.numLesoes = p.numLesoes +1;
    return p;
}

int calculaIdadePaciente(Paciente p, Data dataBase){
    int idade;
    idade = diferencaAnoData(p.dataNasc, dataBase);
    return idade;
}

void getCartaoSusPaciente(Paciente p, char *cartaoSus){
    strcpy(cartaoSus, p.cartaoSus);
}

int getNumLesoesPaciente(Paciente p){
    return p.numLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente p){
    int cirurgicas=0, i=0;
    for(i=0; i<p.numLesoes; i++){
        if(verificaCirurgicaLesao(p.lesoes[i])){
            cirurgicas++;
        }
    }   
    return cirurgicas;
}

void imprimePaciente(Paciente p){
    int tem_lesao_pesada=0, i=0;
if(p.numLesoes>0){
        printf("- %s - ", p.nome);
        for(i=0; i<p.numLesoes; i++){
                imprimeIdLesao(p.lesoes[i]);
        }
    }
                        printf("\n");
    
}