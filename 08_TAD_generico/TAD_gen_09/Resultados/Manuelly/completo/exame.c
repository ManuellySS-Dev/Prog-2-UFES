#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "exame.h"
#include "documento.h"

struct _Exame{
    char * nomePaciente;
    char * nomeMedico;
    char * solicitacao;
};

Exame *criaExame(char *nomeMedico, char *nomePaciente, char *solicitacao){
    Exame * exame = (Exame*) calloc(1, sizeof(Exame));

    exame->nomePaciente = (char*) calloc(100, sizeof(char));
    exame->nomeMedico = (char*) calloc(100, sizeof(char));
    exame->solicitacao = (char*) calloc(100, sizeof(char));

    strcpy(exame->nomeMedico, nomeMedico);
    strcpy(exame->nomePaciente, nomePaciente);
    strcpy(exame->solicitacao, solicitacao);

    return exame;
}

Exame *leExame(){
    char nomePaciente[100];
    char nomeMedico[100];
    char solicitacao[100];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", solicitacao);

    return criaExame(nomeMedico, nomePaciente, solicitacao);
}

float calculaPrecoImpressaoExame(void *dado, float precoCaractere){
    float preco_total = 0;
    Exame * exame = (Exame*) dado;

    preco_total += strlen(exame->solicitacao) * precoCaractere;
    preco_total += strlen(exame->nomeMedico) * precoCaractere;
    preco_total += strlen(exame->nomePaciente) * precoCaractere;

    return preco_total;
}

void imprimeExame(void *dado){
    Exame * exame = (Exame*) dado;
    printf("- - EXAME - -\nPACIENTE: %s\nSOLICITACAO: %s\nMEDICO: %s\n- - - - - - -\n", exame->nomePaciente, exame->solicitacao, exame->nomeMedico);
}

void desalocaExame(void *dado){
    Exame * exame = (Exame*) dado;
    free(exame->nomePaciente);
    free(exame->nomeMedico);
    free(exame->solicitacao);
    free(exame);
}