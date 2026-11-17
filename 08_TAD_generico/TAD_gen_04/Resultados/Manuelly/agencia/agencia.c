#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

struct Agencia{
    char * nome;
    int id, qtd_contas;
    tConta ** contas;
    float saldo_medio;
};

tAgencia *CriaAgencia(){
    tAgencia * agencia = (tAgencia*) calloc(1, sizeof(tAgencia));
    agencia->nome = (char*) calloc(50, sizeof(char));
    agencia->contas = NULL;
    return agencia;
}

void DestroiAgencia(DataType agencia){
    tAgencia * agen = (tAgencia*) agencia; 
    for(int i=0; i<agen->qtd_contas; i++){
        DestroiConta(agen->contas[i]);
    }
    free(agen->contas);
    free(agen->nome);
    free(agen);
}

void LeAgencia(tAgencia *agencia){
    scanf("%d;", &agencia->id);
    scanf(" %[^\n]\n", agencia->nome);
}

void AdicionaConta(tAgencia *agencia, tConta *conta){
    tConta ** temp;
    temp = (tConta**) realloc(agencia->contas, (agencia->qtd_contas+1) * sizeof(tConta*));
    if(temp == NULL){
        exit(0);
    }
    agencia->contas = temp;
    agencia->contas[agencia->qtd_contas] = conta;
    agencia->qtd_contas++;
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->id){
        return 1;
    }
    return 0;
}

float GetSaldoMedioAgencia (tAgencia *agencia){
    float saldo=0;
    for(int i=0; i<agencia->qtd_contas; i++){
        saldo+= GetSaldoConta(agencia->contas[i]);
    }
    return saldo/agencia->qtd_contas;
}

void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->id);
    printf("\tNumero de contas cadastradas: %d\n", agencia->qtd_contas);
    printf("\t Saldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}