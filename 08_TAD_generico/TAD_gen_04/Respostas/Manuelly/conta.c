#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

struct Conta{
    int num_conta;
    float saldo;
    char * nome_usuario;
};

tConta *CriaConta(){
    tConta * conta = (tConta*) calloc(1, sizeof(tConta));
    conta->nome_usuario = (char*) calloc(50, sizeof(char));
    if(conta == NULL){
        exit(0);
    }
    return conta;
}

void DestroiConta(DataType conta){
    tConta * cont = (tConta*) conta;
    free(cont->nome_usuario);
    free(cont);
}

void LeConta(tConta *conta){
    scanf("%d;", &conta->num_conta);
    scanf("%[^;];", conta->nome_usuario);
    scanf("%f", &conta->saldo);
}

float GetSaldoConta(tConta *conta){
    return conta->saldo;
}