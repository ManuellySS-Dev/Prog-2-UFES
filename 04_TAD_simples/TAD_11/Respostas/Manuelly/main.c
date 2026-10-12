#include <stdio.h>
#include <string.h>
#include "vendedor.h"
#include "loja.h"

int main(){
    int id=0, salario=0, aluguel =0,qtd_lojas=0, qtd_vendedores=0,i=0, operacao=1, lojas_abertas=0;
    float prct=0, valor=0;
    char nome[50];
    scanf("%d", &qtd_lojas);
    tVendedor vendedor;
    tLoja lojas[qtd_lojas];

    while(operacao !=0){
        scanf("%d ", &operacao);

        if(operacao == 1){
            scanf("%d %d", &id, &aluguel);
            lojas[lojas_abertas] = AbreLoja(id, aluguel);
            lojas_abertas++;
        }else if(operacao == 2){
            scanf(" %[^ ] %d %f %d", nome, &salario, &prct, &id);
            vendedor = RegistraVendedor(nome, salario, prct);
            lojas[id-1] = ContrataVendedor(lojas[id-1], vendedor);
        }else if(operacao == 3){
            scanf(" %d %[^ ] %f", &id, nome, &valor);
            lojas[id-1] = RegistraVenda(lojas[id-1], nome, valor);
        }else if(operacao == 4){
            for(i=0; i<qtd_lojas; i++){
                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }
    return 0;
}