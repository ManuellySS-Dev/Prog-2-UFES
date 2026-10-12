#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "botao.h"
#include "tela.h"

void SetarTexto(Botao *b, char *novoTexto){
    if(strlen(novoTexto) < MAX_TAM_TEXTO){
        strcpy(b->texto, novoTexto);
    }else{
        exit(0);
    }
}

void SetarTamFonte(Botao *b, int novoTamFonte){
    if(novoTamFonte > 0){
        b->tamFonte = novoTamFonte;
    }else{
        exit(0);
    }
}

void SetarCor(Botao *b, char *novaCor){
    if(strlen(novaCor) < 7){
        strcpy(b->corHex, novaCor);
    }else{
        exit(0);
    }
}

void SetarTipo(Botao *b, int novoTipo){
    if(novoTipo > 0){
        b->tipo = novoTipo;
    }else{
        exit(0);
    }
}

//funcao principal do callback
Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)){
    Botao b;
    SetarCor(&b, cor);
    SetarTexto(&b, texto);
    SetarTamFonte(&b, tamFonte);
    SetarTipo(&b, tipo);
    
    b.executa = executa; 
    
    return b;
}

void ExecutaBotao(Botao b){
    if(b.tipo ==1){
        printf("- Executando o botao com evento de click\n");
    }else{
        printf("- Executando o botao com evento de longo click\n");
    }
    b.executa();
}

void DesenhaBotao(Botao b, int idx){
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}
