#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

tTabuleiro CriaTabuleiro(){
    int linha=0, coluna=0;
    tTabuleiro tabuleiro;
    tabuleiro.pecaVazio = '-';
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';

    for(linha=0; linha<TAM_TABULEIRO; linha++){
        for(coluna=0; coluna<TAM_TABULEIRO; coluna++){
            tabuleiro.posicoes[linha][coluna] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == 1){
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    }else if(peca == 2){
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;
    }else{
        exit(0);
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int linha=0, coluna=0;
    for(linha=0; linha<TAM_TABULEIRO; linha++){
        for(coluna=0; coluna<TAM_TABULEIRO; coluna++){
            if(tabuleiro.posicoes[linha][coluna] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == 1){
        if(tabuleiro.posicoes[y][x] == tabuleiro.peca1){
            return 1;
        }
    }else if(peca == 2){
        if(tabuleiro.posicoes[y][x] == tabuleiro.peca2){
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio){
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x < TAM_TABULEIRO && x>=0 && y<TAM_TABULEIRO && y>=0){
        return 1;
    }else{
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    //descricao diz que verifica se tabuleiro tah cheio vou ver se eh pra verificar se ganharam o jogo no caso
    int linha=0, coluna=0;

    for(linha=0; linha<TAM_TABULEIRO; linha++){
        printf("	");
        for(coluna=0; coluna<TAM_TABULEIRO; coluna++){
            printf("%c", tabuleiro.posicoes[linha][coluna]);
        }
        printf("\n");
    }
}