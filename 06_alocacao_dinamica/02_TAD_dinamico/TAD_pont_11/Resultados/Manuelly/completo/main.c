#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "vendedor.h"
#include "loja.h"

int main(){
    int max_lojas_cadastradas = 0, lojas_cadastradas =0, operacao = 0, i=0, id;
    float aluguel=0, porcentagem=0, salario=0, valor=0;
    char nome[100];
    scanf("%d", &max_lojas_cadastradas);
    tLoja * lojas[max_lojas_cadastradas];
    tVendedor * vendedor;

    while(1){
        scanf(" %d", &operacao);
        if(operacao == 1){
            scanf(" %d %f", &id, &aluguel);
            lojas[lojas_cadastradas] = AbreLoja(id, aluguel);
            lojas_cadastradas++;
        }else if(operacao == 2){
            scanf(" %[^ ] ", nome);
            scanf(" %f", &salario);
            scanf(" %f", &porcentagem);
            scanf(" %d", &id);
            vendedor = RegistraVendedor(nome, salario, porcentagem);
            ContrataVendedor(lojas[id-1], vendedor);
        }else if(operacao == 3){
            scanf(" %d", &id);
            scanf(" %[^ ] ", nome);
            scanf(" %f", &valor);
            RegistraVenda(lojas[id-1], nome, valor);
        }else if(operacao == 4){
            for(i=0; i<lojas_cadastradas; i++){
                CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }else if(operacao == 0){
            break;
        }
    }

    for(i=0; i<lojas_cadastradas; i++){
        ApagaLoja(lojas[i]);
    }

    return 0;
}