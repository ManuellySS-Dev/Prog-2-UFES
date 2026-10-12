#include <stdio.h>
#include "filme.h"
#include "locadora.h"
#include "string.h"

int main(){
    tLocadora locadora;
    char operacao[100], carac='\0';
    int i=0;
    scanf(" %99[^\n]", operacao);
    locadora.lucro=0;
    locadora.numFilmes=0;
    if(!strcmp (operacao, "Cadastrar")){
        locadora = lerCadastroLocadora(locadora);
    }
    
    while(1){
            scanf(" %99[^\n]", operacao);
            if(!strcmp (operacao, "Alugar")){
                printf("\n");
                locadora = lerAluguelLocadora(locadora);
            }else if(!strcmp (operacao, "Devolver")){
                printf("\n");
                locadora = lerDevolucaoLocadora(locadora);
            }else if(!strcmp (operacao, "Estoque")){
                printf("\n");
                locadora = ordenarFilmesLocadora(locadora);
                consultarEstoqueLocadora(locadora);
            }else if(!strcmp (operacao, "Cadastrar")){
                printf("\n");
                locadora = lerCadastroLocadora(locadora);
            }
            if(i>50){
                consultarLucroLocadora(locadora);
                break;
            }
            i++;
    }
return 0;
}
