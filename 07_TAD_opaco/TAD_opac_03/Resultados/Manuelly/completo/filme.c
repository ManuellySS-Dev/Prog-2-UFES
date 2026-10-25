#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

struct Filme{
    int codigo, valor, qtd_estoque, qtd_alugado;
    char nome[MAX_CARACTERES];
};

tFilme* CriarFilme(){
    tFilme * filme = (tFilme*) calloc(1, sizeof(tFilme));
    return filme;
}

void LeFilme(tFilme *filme, int codigo){
    filme->codigo = codigo;
    scanf(" %[^,],", filme->nome);
    scanf(" %d,", &filme->valor);
    scanf( "%d", &filme->qtd_estoque);
}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtd_estoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtd_alugado;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    if(codigo == filme->codigo){
        return 1;
    }
    return 0;
}

void AlugarFilme (tFilme* filme){
    if(filme->qtd_estoque>0){
        filme->qtd_alugado++;
        filme->qtd_estoque--;
    }
}

void DevolverFilme (tFilme* filme){
    if(filme->qtd_alugado>0){
        filme->qtd_estoque++;
        filme->qtd_alugado--;
    }
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}
