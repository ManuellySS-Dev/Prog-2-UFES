#include "conta.h"
#include "usuario.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tConta *CriaConta(){
    tConta * conta = (tConta*) calloc(1, sizeof(tConta));
    if(conta == NULL){
        exit(0);
    }
    return conta;
}

void DestroiConta(tConta *conta){
    free(conta->user);
    free(conta);
}

void LeConta(tConta *conta){
    conta->user = CriaUsuario();
    LeUsuario(conta->user);
    scanf("%d", &conta->numero);
}

void ImprimeConta(tConta *conta){
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
    printf("\n");
}

int VerificaConta(tConta *conta, int numero){
    if(numero == conta->numero){
        return 1;
    }else{
        return 0;
    }
}

void SaqueConta(tConta *conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo = conta->saldo - valor;
    }else{
        printf("Saldo insuficiente \n");
    }
}

void DepositoConta(tConta *conta, float valor){
    conta->saldo = conta->saldo + valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    SaqueConta(origem, valor);
    DepositoConta(destino, valor);
}