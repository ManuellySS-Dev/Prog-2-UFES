#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

int main(){
    char operacao[100];
    tLocadora * locadora;
    locadora = CriarLocadora();

    while(scanf(" %[^\n]\n", operacao) >0){
        //cadastro de filmes
        //printf("\n\n%s\n\n", operacao);
        if(!strcmp(operacao, "Cadastrar")){
            LerCadastroLocadora(locadora);
            printf("\n");
        }
        if(!strcmp(operacao, "Estoque")){
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            printf("\n");
        }
        if(!strcmp(operacao, "Alugar") || !strcmp(operacao, "Alugar ")){
            LerAluguelLocadora(locadora);
            printf("\n");
        }
        if(!strcmp(operacao, "Devolver") || !strcmp(operacao, "Devolver ")){
            LerDevolucaoLocadora(locadora);
            printf("\n");
        }
    }
    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);
    return 0;
}