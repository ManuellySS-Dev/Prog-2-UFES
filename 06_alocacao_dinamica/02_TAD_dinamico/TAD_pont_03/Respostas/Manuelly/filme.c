#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

tFilme* CriarFilme(){
    tFilme * filme = (tFilme*) calloc(1, sizeof(tFilme));
    if(filme == NULL){
        printf("Nao foi possivel alocar memoria para filme\n");
        exit(0);
    }
    return filme;
}

void LeFilme(tFilme *filme, int codigo){
    filme->codigo = codigo;
    scanf(" %[^,],", filme->nome);
    scanf(" %d,", &filme->valor);
    scanf(" %d", &filme->qtdEstoque);
    filme->qtdAlugada=0;

}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    printf("- %s -", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtdAlugada;
}   

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    if(filme->codigo == codigo){
        return 1;
    }
    return 0;
}

void AlugarFilme (tFilme* filme){
    if(filme->qtdEstoque>1){
        filme->qtdAlugada++;
        filme->qtdEstoque--;
    }
}

void DevolverFilme (tFilme* filme){
    if(filme->qtdAlugada>1){
        filme->qtdAlugada--;
        filme->qtdEstoque++;
    }
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}