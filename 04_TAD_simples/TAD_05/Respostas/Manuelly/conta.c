#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

tConta CriaConta(int numero, tUsuario user){
    tConta conta;
    conta.user = user;
    conta.numero = numero;
    conta.saldo = 0;
    return conta;
}

void ImprimeConta(tConta conta){
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    printf("Nome: %s\n", conta.user.nome);
    printf("CPF: %s\n\n", conta.user.cpf);
}

int VerificaConta(tConta conta, int numero){
    if(conta.numero == numero){
        return 1;
    }
    return 0;
}

tConta SaqueConta(tConta conta, float valor){
    if(conta.saldo >= valor){
        conta.saldo = conta.saldo - valor;
    }else{
        printf("Saldo insuficiente\n");
    }
    return conta;
}

tConta DepositoConta(tConta conta, float valor){
    conta.saldo = conta.saldo + valor;
    return conta;
}