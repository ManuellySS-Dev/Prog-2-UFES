#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "receita.h"
#include "documento.h"

struct _Receita{
    char * nomeMedicamento;
    char * nomePaciente;
    char * nomeMedico;
    char * instrucoes;
};

Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes){
    Receita * rec = (Receita*) calloc(1, sizeof(Receita));

    rec->nomeMedicamento = (char*) calloc(100, sizeof(char));
    rec->nomePaciente = (char*) calloc(100, sizeof(char));
    rec->nomeMedico = (char*) calloc(100, sizeof(char));
    rec->instrucoes = (char*) calloc(100, sizeof(char));

    strcpy(rec->nomeMedicamento, nomeMedicamento);
    strcpy(rec->nomeMedico, nomeMedico);
    strcpy(rec->nomePaciente, nomePaciente);
    strcpy(rec->instrucoes, instrucoes);

    return rec;
}

Receita *leReceita(){
    char nomeMedicamento[100];
    char nomePaciente[100];
    char nomeMedico[100];
    char instrucoes[100];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", nomeMedicamento);
    scanf(" %[^\n]\n", instrucoes);

    return criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);
}

float calculaPrecoImpressaoReceita(void *dado, float precoCaractere){
    float preco_total = 0;
    Receita * rec = (Receita*) dado;

    preco_total += strlen(rec->instrucoes) * precoCaractere;
    preco_total += strlen(rec->nomeMedicamento) * precoCaractere;
    preco_total += strlen(rec->nomeMedico) * precoCaractere;
    preco_total += strlen(rec->nomePaciente) * precoCaractere;

    return preco_total;
}

void imprimeReceita(void *dado){
    Receita * rec = (Receita*) dado;
    printf("- - RECEITA - -\nMEDICAMENTO: %s\nPACIENTE: %s\nINSTRUCOES: %s\nMEDICO: %s\n- - - - - - - -\n", rec->nomeMedicamento, rec->nomePaciente, rec->instrucoes, rec->nomeMedico);
}

void desalocaReceita(void *dado){
    Receita * rec = (Receita*) dado;
    free(rec->nomeMedicamento);
    free(rec->nomePaciente);
    free(rec->nomeMedico);
    free(rec->instrucoes);
    free(rec);
}