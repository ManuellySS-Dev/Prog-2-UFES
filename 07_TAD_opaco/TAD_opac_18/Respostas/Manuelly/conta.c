#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"

struct Conta{
    int id;
    float saldo;
};

tConta* CriaConta(int id){
    tConta*conta = (tConta*) calloc(1, sizeof(tConta));
    conta->id = id;
    conta->saldo = 0;
    return conta;
}

void DestroiConta(tConta* conta){   
    free(conta);
}   

void AlteraSaldoConta(tConta* conta, float valor){
    conta->saldo += valor;
}

int ConfereIdConta(tConta* conta, int id){
    if(conta->id == id){
        return 1;
    }
    return 0;
}

int RetornaIdConta(tConta* conta){
    return conta->id;
}

float RetornaSaldoConta(tConta* conta){
    return conta->saldo;
}