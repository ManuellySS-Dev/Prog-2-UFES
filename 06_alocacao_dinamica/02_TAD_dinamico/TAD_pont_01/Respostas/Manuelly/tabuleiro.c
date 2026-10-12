#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

tTabuleiro* CriaTabuleiro() {
    int i = 0, j = 0;
    int linhas = 3;
    int colunas = 3;

    tTabuleiro *tabuleiro = (tTabuleiro*) calloc(1, sizeof(tTabuleiro));
    if (tabuleiro == NULL) {
        printf("Erro ao alocar o tabuleiro!\n");
        return NULL;
    }

    tabuleiro->posicoes = (char **) calloc(linhas, sizeof(char *));
    if (tabuleiro->posicoes == NULL) {
        printf("Erro ao alocar memória para as linhas!\n");
        free(tabuleiro); 
        return NULL;
    }

    for (i = 0; i < linhas; i++) {
        tabuleiro->posicoes[i] = (char *) calloc(colunas, sizeof(char));
        
        if (tabuleiro->posicoes[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d!\n", i);
            return NULL; 
        }
    }    
    
    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
        }
    }

    return tabuleiro;
}


void DestroiTabuleiro(tTabuleiro* tabuleiro){
    int linhas = 3; // Ou usar o valor guardado caso seja dinâmico

    // 1. Libera cada uma das linhas alocadas com calloc
    if (tabuleiro->posicoes != NULL) {
        for (int i = 0; i < linhas; i++) {
            free(tabuleiro->posicoes[i]);
        }
        // 2. Libera o vetor de ponteiros que aponta para as linhas
        free(tabuleiro->posicoes);
    }

    // 3. Libera a estrutura principal do tabuleiro
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(EstaLivrePosicaoTabuleiro(tabuleiro,x,y)){
        if(EhPosicaoValidaTabuleiro(x,y)){
            if(peca ==1){
                tabuleiro->posicoes[y][x] = tabuleiro->peca1;
            }else{
                tabuleiro->posicoes[y][x] = tabuleiro->peca2;
            }
        }
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    int i=0, j=0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i,j)){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == 1){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1){
            return 1;
        }
    }else if(peca == 2){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2){
            return 1;
        }
    }else{
        printf("posicao invalida - Manu\n");
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio){
        return 1;
    }else{
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x > 2 || x<0 || y>2 || y<0){
        return 0;
    }else{
        return 1;
    }
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i=0, j=0;
    for(i=0; i<3; i++){
        printf("	");
        for(j=0; j<3; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}

