#include <stdio.h>
#include <string.h>
#include "filme.h"
#include "locadora.h"

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;
    filme.codigo = codigo;
    strcpy(filme.nome, nome);
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

tFilme leFilme(int codigo){
    tFilme filme;
    scanf("%[^,],%d,%d\n", filme.nome, &filme.valor, &filme.qtdEstoque);
    filme = criarFilme(filme.nome, codigo, filme.valor, filme.qtdEstoque);
    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    }else{
        return 0;
    }
}

tFilme alugarFilme (tFilme filme){
    filme.qtdAlugada = filme.qtdAlugada +1;
    filme.qtdEstoque = filme.qtdEstoque-1;
    return filme;
}

tFilme devolverFilme (tFilme filme){
    filme.qtdAlugada = filme.qtdAlugada -1;
    filme.qtdEstoque = filme.qtdEstoque+1;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    if(strcmp(filme1.nome, filme2.nome)==1){ //se o nome 1 eh maior que o nome 2
        return 1;
    }else if(strcmp(filme1.nome, filme2.nome)==0){
        return 0;
    }else{
        return -1;
    }
}

