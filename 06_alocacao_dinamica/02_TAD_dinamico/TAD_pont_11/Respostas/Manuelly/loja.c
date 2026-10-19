#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"

tLoja* AbreLoja(int id, float aluguel){
    tLoja * loja = (tLoja*) calloc(1, sizeof(tLoja));
    loja->vendedores = (tVendedor**) calloc(10, sizeof(tVendedor*));
    loja->id = id;
    loja->aluguel = aluguel; 
    loja->totalVendedores=0;
    return loja;
}

void ApagaLoja(tLoja* loja){
    int i=0;
    for(i=0; i<loja->totalVendedores; i++){
        ApagaVendedor(loja->vendedores[i]);
    }
    free(loja->vendedores);
    free(loja);
}

int VerificaIdLoja(tLoja* loja, int id){
    if(id == loja->id){
        return 1;
    }else{
        return 0;
    }
}

void ContrataVendedor(tLoja* loja, tVendedor* vendedor){
    loja->vendedores[loja->totalVendedores] = vendedor;
    loja->totalVendedores++;
}

void RegistraVenda(tLoja* loja, char* nome, float valor){
    int i=0;
    for(i=0; i<loja->totalVendedores; i++){
        if(VerificaNomeVendedor( loja->vendedores[i], nome)){
            ContabilizaVenda(loja->vendedores[i], valor);
        }
    }
}

void CalculaLucro(tLoja* loja){
    int i=0;
    for(i=0; i<loja->totalVendedores; i++){
        loja->lucro += GetTotalVendido(loja->vendedores[i]);
    }
    for(i=0; i<loja->totalVendedores; i++){
        loja->lucro -= GetTotalRecebido(loja->vendedores[i]);
    }
        loja->lucro -= loja->aluguel;
}

void ImprimeRelatorioLoja(tLoja* loja){
    int i=0;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for(i=0; i<loja->totalVendedores; i++){
        ImprimeRelatorioVendedor(loja->vendedores[i]);
    }
}