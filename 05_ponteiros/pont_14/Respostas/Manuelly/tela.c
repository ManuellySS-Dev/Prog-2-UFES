#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "botao.h"
#include "tela.h"

Tela CriarTela(int altura, int largura){
    Tela t;
    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b){
    t->botoes[t->qntBotoes] = b;
    t->qntBotoes= t->qntBotoes+1;
}

void DesenhaTela(Tela t){
    int i=0;
    printf("##################\n");
    for(i=0; i<3; i++){
        DesenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n");
}

void OuvidorEventosTela(Tela t){
    int opcao_escolhida=0;
    scanf("%d", &opcao_escolhida);
    printf("- Escolha sua acao: ");
    if(opcao_escolhida==0){
        ExecutaBotao(t.botoes[0]);
    }else if(opcao_escolhida==1){
        ExecutaBotao(t.botoes[1]);
    }else if(opcao_escolhida ==2){
        ExecutaBotao(t.botoes[2]);
    }else{
        exit(0);
    }
}
