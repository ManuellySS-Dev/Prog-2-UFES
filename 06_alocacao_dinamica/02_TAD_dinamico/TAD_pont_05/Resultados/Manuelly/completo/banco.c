#include "conta.h"
#include "usuario.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tBanco *CriaBanco(){
    int i=0;
    tBanco * banco = (tBanco*) calloc(1, sizeof(tBanco));
    banco->contas = (tConta**) calloc(5, sizeof(tConta*));
    if(banco == NULL){
        exit(0);
    }
    for(i=0; i<5; i++){
        banco->contas[i] = CriaConta();
    }

    banco->contasAlocadas=5;
    banco->qtdContas=0;

    return banco;
}

void DestroiBanco(tBanco *banco){
    int i=0;
    //Destroi as contas que foram efetivamente usadas (passaram por LeConta)
    for(i=0; i<banco->qtdContas; i++){
        DestroiConta(banco->contas[i]);
    }
    //Dah free direto na estrutura da conta para as que sobraram vazias
    for(i=banco->qtdContas; i<banco->contasAlocadas; i++){
        free(banco->contas[i]);//essas eu nao usei le conta entao os ponteiros dos usuarios nao foram inicializados e dai preciso liberar soh a posicao na lista de ponteiros
    }
    free(banco->contas);
    free(banco);
}

void AbreContaBanco(tBanco *banco){
    int i=0;
    if(banco->qtdContas < banco->contasAlocadas){
        LeConta(banco->contas[banco->qtdContas]);
        banco->qtdContas++;
    }else{
        banco->contas = realloc(banco->contas, (banco->contasAlocadas+1) * sizeof(tConta*));
        banco->contasAlocadas = banco->contasAlocadas+1;
        
        banco->contas[banco->qtdContas] = CriaConta();
        LeConta(banco->contas[banco->qtdContas]);
        
        banco->qtdContas++;
    }
}

void SaqueContaBanco(tBanco *banco){
    int i=0, n_conta=0, flag_sacou=0;
    float valor=0;
    scanf("%d %f", &n_conta, &valor);
    for(i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], n_conta)){
            SaqueConta(banco->contas[i], valor);
            flag_sacou=1;
        }
    }
    if(flag_sacou == 0){
        printf("Usuario nao encontrado na lista de usuarios do banco\n");
    }
}

void DepositoContaBanco(tBanco *banco){
    int i=0, n_conta=0, flag_sacou=0;
    float valor=0;
    scanf("%d %f", &n_conta, &valor);
    for(i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], n_conta)){
            DepositoConta(banco->contas[i], valor);
            flag_sacou=1;
        }
    }
    if(flag_sacou == 0){
        printf("Usuario nao encontrado na lista de usuarios do banco\n");
    }
}

void TransferenciaContaBanco(tBanco *banco){
    int n_destino=0, n_origem=0, i=0, flag_sacou=0;
    float valor = 0;
    scanf("%d %d %f", &n_destino, &n_origem, &valor);
    for(i=0; i<banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], n_origem)){
            SaqueConta(banco->contas[i], valor);
            flag_sacou=1;
        }
    }
    if(flag_sacou==1){
        for(i=0; i<banco->qtdContas; i++){
            if(VerificaConta(banco->contas[i], n_destino)){
                DepositoConta(banco->contas[i], valor);
            }
        }
    }else{
        printf("nao foi possivel realizar o saque para transferencia\n");
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    int i=0;
    printf("===| Imprimindo Relatorio |===\n");
    for(i=0; i<banco->qtdContas; i++){
        ImprimeConta(banco->contas[i]);
    }
}