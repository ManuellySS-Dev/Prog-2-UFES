#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

struct Banco{
    tAgencia ** agencias;
    char * nome;
    int qtd_agencias;
};

tBanco *CriaBanco(){
    tBanco * banco = (tBanco*) calloc(1, sizeof(tBanco));
    banco->nome = (char*) calloc(100, sizeof(char));
    banco->agencias = NULL;
    return banco;
}

void DestroiBanco(tBanco *banco){
    free(banco->nome);
    for(int i=0; i<banco->qtd_agencias; i++){
        DestroiAgencia(banco->agencias[i]);
    }
    free(banco->agencias);
    free(banco);
}

void LeBanco(tBanco *banco){
    scanf(" %[^\n]\n", banco->nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    tAgencia ** temp;
    temp = (tAgencia**) realloc(banco->agencias,((banco->qtd_agencias+1) * sizeof(tAgencia*)));
    if(temp == NULL){
        exit(0);
    }
    banco->agencias = temp;
    banco->agencias[banco->qtd_agencias] = agencia;
    banco->qtd_agencias++;
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    int flag_achou=0;
    for(int i=0; i<banco->qtd_agencias; i++){
        if(ComparaAgencia(numAgencia, banco->agencias[i])){
            AdicionaConta(banco->agencias[i], cliente);
            flag_achou=1;
            break;
        }
    }
    if(flag_achou == 0){
        DestroiConta(cliente);
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for(int i=0; i<banco->qtd_agencias; i++){
        ImprimeDadosAgencia(banco->agencias[i]);
    }
}