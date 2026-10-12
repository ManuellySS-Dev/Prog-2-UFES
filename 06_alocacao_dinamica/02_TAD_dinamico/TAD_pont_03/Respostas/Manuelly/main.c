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
        if(!strcmp(operacao, "Cadastrar")){
            LerCadastroLocadora(locadora);
        }
        if(!strcmp(operacao, "Estoque")){
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }
        if(!strcmp(operacao, "Alugar")){
            LerAluguelLocadora(locadora);
        }
        if(!strcmp(operacao, "Devolver")){
            LerDevolucaoLocadora(locadora);
        }
    }
    return 0;
}