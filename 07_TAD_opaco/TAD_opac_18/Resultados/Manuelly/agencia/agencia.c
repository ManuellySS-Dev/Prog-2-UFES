#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"

#define MAX_CONTAS 30
#define MAX_OPERACOES 100


struct Agencia{
    tConta ** contas;
    tOperacao ** operacoes;
    int qtd_contas, qtd_operacoes;
    float saldo_total;
};

tAgencia* CriaAgencia(){
    tAgencia * agencia = (tAgencia*) calloc(1, sizeof(tAgencia));
    agencia->contas = (tConta**) calloc(MAX_CONTAS, sizeof(tConta*));
    agencia->operacoes = (tOperacao**) calloc(MAX_OPERACOES, sizeof(tOperacao*));
    return agencia;
}

void DestroiAgencia(tAgencia* agencia){
    int i=0;
    for(i=0; i<agencia->qtd_contas; i++){
        DestroiConta(agencia->contas[i]);
    }
    free(agencia->contas);

    for(i=0; i<agencia->qtd_operacoes; i++){
        DestroiOperacao(agencia->operacoes[i]);
    }
    free(agencia->operacoes);

    free(agencia);
}

void LeOperacoes(tAgencia *agencia){
    int qtd_c=0, id=0, valido=0, repetido=0, i=0, qtd_op=0, j=0;
    float valor=0;
    scanf("%d\n", &qtd_c);
    while(agencia->qtd_contas < qtd_c){
        valido = 0;
        repetido = 0;
        scanf(" %d", &id);

        for(i=0; i<agencia->qtd_contas; i++){
            if(ConfereIdConta(agencia->contas[i], id)){
                repetido =1;
                break;
            }
        }
        if(id<0){
            printf("\nDigite um id valido para a conta a ser cadastrada!");
        }
        if(repetido == 1){
            printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
        }

        if(id < 0 || repetido ==1){
            valido = 0;
        }else{
            valido=1;
        }

        if(valido==1){
            agencia->contas[agencia->qtd_contas] = CriaConta(id);
            agencia->qtd_contas++;
        }
    }
    scanf("%d\n", &qtd_op);
    while(agencia->qtd_operacoes < qtd_op){
        scanf("%d %f", &id, &valor);

        if(BuscaContaPorId(agencia, id) != NULL){
            agencia->operacoes[agencia->qtd_operacoes] = CriaOperacao(BuscaContaPorId(agencia, id) , valor);
            AlteraSaldoConta(BuscaContaPorId(agencia, id) , valor);
            agencia->saldo_total+= valor;
            agencia->qtd_operacoes++;
        }else{
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
        }
    }
}

tConta* BuscaContaPorId(tAgencia *agencia, int id){
    int i=0;
    for(i=0; i<agencia->qtd_contas; i++){
        if(ConfereIdConta(agencia->contas[i], id)){
            return agencia->contas[i];
        }
    }
    return NULL;
}

void ImprimeOperacoesSuspeitas(tAgencia* agencia){
    int i=0;
    printf("\nA lista de operações suspeitas:");
    for(i=0; i<agencia->qtd_operacoes; i++){
        if(ConsultaValorOperacao(agencia->operacoes[i]) >= 20000 || ConsultaValorOperacao(agencia->operacoes[i]) <= -20000){
            ImprimeOperacao(agencia->operacoes[i]);
        }
    }
}

void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia){
    int i=0, indice_maior, indice_segundo_maior;
    float maior1=-32000, maior2= -32000;
    for(i=0; i<agencia->qtd_contas; i++){
        if(RetornaSaldoConta(agencia->contas[i]) > maior1){
            maior1 = RetornaSaldoConta(agencia->contas[i]);
            indice_maior = i;
        }
    }
    for(i=0; i<agencia->qtd_contas; i++){
        if(RetornaSaldoConta(agencia->contas[i]) > maior2 && i!= indice_maior){
            maior2 = RetornaSaldoConta(agencia->contas[i]);
            indice_segundo_maior = i;
        }
    }
    printf("\nOs dois correntistas com maior saldo são:\n");
    printf("Id: %d, Saldo: %.2f\nId: %d, Saldo: %.2f\n", RetornaIdConta(agencia->contas[indice_maior]), RetornaSaldoConta(agencia->contas[indice_maior]),RetornaIdConta(agencia->contas[indice_segundo_maior]), RetornaSaldoConta(agencia->contas[indice_segundo_maior]));
}

void ImprimeSaldoTotal(tAgencia* agencia){
    printf("O saldo total da agencia eh: %.2f\n", agencia->saldo_total);
}



