#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "encaminhamento.h"
#include "documento.h"

struct _Encaminhamento{
    char * nomePaciente;
    char * nomeMedico;
    char * especialidade;
    char * solicitacao;
};

Encaminhamento *criaEncaminhamento(char *nomeMedico, char *nomePaciente, char *solicitacao, char * especialidade){
    Encaminhamento * encaminhamento = (Encaminhamento*) calloc(1, sizeof(Encaminhamento));

    encaminhamento->nomePaciente = (char*) calloc(100, sizeof(char));
    encaminhamento->nomeMedico = (char*) calloc(100, sizeof(char));
    encaminhamento->solicitacao = (char*) calloc(100, sizeof(char));
    encaminhamento->especialidade = (char*) calloc(100, sizeof(char));

    strcpy(encaminhamento->nomeMedico, nomeMedico);
    strcpy(encaminhamento->nomePaciente, nomePaciente);
    strcpy(encaminhamento->solicitacao, solicitacao);
    strcpy(encaminhamento->especialidade, especialidade);

    return encaminhamento;
}

Encaminhamento *leEncaminhamento(){
    char nomePaciente[100];
    char nomeMedico[100];
    char solicitacao[100];
    char especialidade[100];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", especialidade);
    scanf(" %[^\n]\n", solicitacao);

    return criaEncaminhamento(nomeMedico, nomePaciente, solicitacao, especialidade);
}

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere){
    float preco_total = 0;
    Encaminhamento * encaminhamento = (Encaminhamento*) dado;

    preco_total += strlen(encaminhamento->solicitacao) * precoCaractere;
    preco_total += strlen(encaminhamento->nomeMedico) * precoCaractere;
    preco_total += strlen(encaminhamento->nomePaciente) * precoCaractere;
    preco_total += strlen(encaminhamento->especialidade) * precoCaractere;

    return preco_total;
}

void imprimeEncaminhamento(void *dado){
    Encaminhamento * encaminhamento = (Encaminhamento*) dado;
    printf("- - ENCAMINHAMENTO - -\nPACIENTE: %s\nESPECIALIDADE: %s\nMOTIVO: %s\nMEDICO: %s\n- - - - - - - - - - - -\n", encaminhamento->nomePaciente, encaminhamento->especialidade,encaminhamento->solicitacao, encaminhamento->nomeMedico);
}

void desalocaEncaminhamento(void *dado){
    Encaminhamento * encaminhamento = (Encaminhamento*) dado;

    free(encaminhamento->nomePaciente);
    free(encaminhamento->nomeMedico);
    free(encaminhamento->solicitacao);
    free(encaminhamento->especialidade);

    free(encaminhamento);
}