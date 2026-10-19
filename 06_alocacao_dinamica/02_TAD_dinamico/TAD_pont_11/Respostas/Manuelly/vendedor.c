#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"

tVendedor* RegistraVendedor(char* nome, float salario, float prct_comissao){
    tVendedor * vendedor = (tVendedor*) calloc(1, sizeof(tVendedor));
    vendedor->nome = (char*) calloc(100, sizeof(char));
    strcpy(vendedor->nome, nome);
    vendedor->salario = salario;
    vendedor->prct_comissao = prct_comissao;
    vendedor->valor_vendido = 0;
    return vendedor;
}

void ApagaVendedor(tVendedor* vendedor){
    free(vendedor->nome);
    free(vendedor);
}

int VerificaNomeVendedor(tVendedor* vendedor, char* nome){
    if(!strcmp(vendedor->nome, nome)){
        return 1;
    }else{
        return 0;
    }
}

void ContabilizaVenda(tVendedor* vendedor, float valor){
    vendedor->valor_vendido += valor;
}

float GetSalario(tVendedor* vendedor){
    return vendedor->salario;
}

float GetComissao(tVendedor* vendedor){
    return vendedor->valor_vendido * vendedor->prct_comissao;
}

float GetTotalVendido(tVendedor* vendedor){
    return vendedor->valor_vendido;
}

float GetTotalRecebido(tVendedor* vendedor){
    return vendedor->salario + (GetTotalVendido(vendedor) * vendedor->prct_comissao);
}

void ImprimeRelatorioVendedor(tVendedor* vendedor){
    printf("\t%s: Total vendido: R$%.2f\n\t\tTotal recebido: R$%.2f\n", vendedor->nome, vendedor->valor_vendido, GetTotalRecebido(vendedor));
}