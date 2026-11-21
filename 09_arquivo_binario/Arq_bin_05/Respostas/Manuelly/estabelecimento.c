#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "vector.h"
#include "estabelecimento.h"

struct Estabelecimento{
    Vector * produtos;
    int qtd_produtos;
};

tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento * e = (tEstabelecimento*) calloc(1, sizeof(tEstabelecimento));
    e->produtos = VectorConstruct();
    return e;
}

void DestroiProdutoGenerico(void *dado) {//necessario porque a funcao vectordestroy precisa de uma funcao destroi que receba generico e o destroi produto soh destroi especificamente produtos
    DestroiProduto((tProduto *)dado);
}

void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    VectorDestroy(estabelecimento->produtos, DestroiProdutoGenerico);
    free(estabelecimento);
}


void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->produtos, produto);
}

void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char nome_arquivo[50];
    scanf("%[^\n]\n", nome_arquivo);
    FILE * arquivo_produtos = fopen(nome_arquivo, "rb");
    fread(&estabelecimento->qtd_produtos, sizeof(int), 1, arquivo_produtos);

    for(int i=0; i<estabelecimento->qtd_produtos; i++){
        AdicionaProdutoEstabelecimento(estabelecimento,LeProduto(arquivo_produtos));
    }

    fclose(arquivo_produtos);
}

void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    int ha_produtos_em_falta=0;
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    for(int i=0; i<estabelecimento->qtd_produtos; i++){
        tProduto * produto = (tProduto*) VectorGet(estabelecimento->produtos, i);
        if(!TemEstoqueProduto(produto)){
            ImprimeProduto(produto);
            ha_produtos_em_falta = 1;
        }
    }
    if(ha_produtos_em_falta == 0){
        printf("Nao ha produtos em falta!\n");
    }
}