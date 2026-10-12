#include <stdio.h>
#include <string.h>
#include "vendedor.h"
#include "loja.h"

tLoja AbreLoja(int id, float aluguel){
    tLoja loja;
    loja.id = id;
    loja.aluguel = aluguel;
    loja.lucro = 0;
    loja.totalVendedores=0;
    return loja;
}

int VerificaIdLoja(tLoja loja, int id){
    if(id == loja.id){
        return 1;
    }
    return 0;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor){

    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores = loja.totalVendedores + 1;
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor){
    int i=0;
    for(i=0; i<loja.totalVendedores; i++){
        if(VerificaNomeVendedor(loja.vendedores[i], nome)){
            break;
        }
    }
    loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
    loja.lucro += valor;
    return loja;
}

tLoja CalculaLucro(tLoja loja){
    int i=0, pagamento_vendedores=0;
    for(i=0; i<loja.totalVendedores; i++){
        pagamento_vendedores += GetTotalRecebido(loja.vendedores[i]);
    }
    loja.lucro -= pagamento_vendedores;
    loja.lucro -= loja.aluguel;
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja){
    int i=0;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for(i=0; i<loja.totalVendedores; i++){
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}