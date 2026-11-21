#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto{
    int codigo, quantidade;
    float preco;
    char nome[51];
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto* prod = (tProduto*) calloc(1, sizeof(tProduto));
    prod->codigo = codigo;
    prod->preco = preco;
    prod->quantidade = quantidade;
    strcpy(prod->nome, nome);
    return prod;
}

void DestroiProduto(tProduto *produto){
    free(produto);
}

tProduto *LeProduto(FILE *arquivo){
    int codigo, quantidade;
    float preco;
    char nome[51];
    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), 50, arquivo);
    nome[51] = '\0';
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&quantidade, sizeof(int), 1, arquivo);
    return CriaProduto(codigo, nome, preco, quantidade);
}

int TemEstoqueProduto(tProduto *produto){
    if(produto->quantidade >0){
        return 1;
    }
    return 0;
}

void ImprimeProduto(tProduto *produto){
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->quantidade);
}

int GetQuantidadeVendidaProduto(tProduto *produto){
    return produto->quantidade;
}

float GetPrecoProduto(tProduto *produto){
    return produto->preco;
}