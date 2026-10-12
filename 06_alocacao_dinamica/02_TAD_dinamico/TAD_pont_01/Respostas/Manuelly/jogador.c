#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

tJogador* CriaJogador(int idJogador){
    tJogador * jogador = (tJogador*) calloc(1, sizeof(tJogador));
    jogador->id = idJogador;
    return jogador;
}

void DestroiJogador(tJogador* jogador){
    free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
int x = 0, y = 0;
    
    while(1){
        printf("Jogador %d\n", jogador->id);
        tJogada * jogada = (tJogada*) calloc(1, sizeof(tJogada));
        LeJogada(jogada);
        
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        
        if(FoiJogadaBemSucedida(jogada) && EhPosicaoValidaTabuleiro(x, y)){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
                printf("Jogada [%d,%d]!\n", x, y);
                MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
                DestroiJogada(jogada);
                break;
            } else {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            }
        } else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
        
        // Libera a jogada inválida para evitar vazamento ou lixo em loop
        DestroiJogada(jogada);
    }
}

int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    if(jogador->id == 1){
        if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[0][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[0][2] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[1][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][2] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[2][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[0][2] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][0] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][0] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][0] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[0][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][1] ==  tabuleiro->peca1){
            return 1;
        }else if(tabuleiro->posicoes[0][2] ==  tabuleiro->peca1 && tabuleiro->posicoes[1][2] ==  tabuleiro->peca1 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca1){
            return 1;
        }
    }else if(jogador->id == 2){
        if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[0][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[0][2] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[1][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][2] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[2][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[0][2] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][0] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[0][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][0] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][0] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[0][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][1] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][1] ==  tabuleiro->peca2){
            return 1;
        }else if(tabuleiro->posicoes[0][2] ==  tabuleiro->peca2 && tabuleiro->posicoes[1][2] ==  tabuleiro->peca2 && tabuleiro->posicoes[2][2] ==  tabuleiro->peca2){
            return 1;
        }
    }else{
        printf("teste jogador ganhou invalido - Manu\n");
    }

    return 0;
}