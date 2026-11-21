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
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){
    float total_vendido=0;

    for(int i=0; i<estabelecimento->qtd_produtos; i++){
        tProduto * produto = (tProduto*) VectorGet(estabelecimento->produtos, i);
        if(GetQuantidadeVendidaProduto(produto) > 0){
            total_vendido += GetQuantidadeVendidaProduto(produto) * GetPrecoProduto(produto);
        }
    }
    return total_vendido;
}
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){
    int ha_produtos_em_falta=0;
    
    printf("Valor total vendido: R$ %.2f\n", GetValorTotalVendidoEstabelecimento(estabelecimento));
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    for(int i=0; i<estabelecimento->qtd_produtos; i++){
        tProduto * produto = (tProduto*) VectorGet(estabelecimento->produtos, i);
        if(GetQuantidadeVendidaProduto(produto) > 0){
            ImprimeProduto(produto);
            float porcentagem = GetQuantidadeVendidaProduto(produto)*GetPrecoProduto(produto)*100/GetValorTotalVendidoEstabelecimento(estabelecimento);
            printf(";%.2f%%", porcentagem);
            ha_produtos_em_falta = 1;
            printf("\n");
        }
    }
    if(ha_produtos_em_falta == 0){
        printf("Nao ha produtos vendidos!\n");
    }
}