#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    int i=1;
    tTabuleiro tabuleiro_anterior;
    while(1){
        if(AcabouJogo(jogo) == 1){
            break;
        }
        if(i%2 != 0){
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro); 
        }else{
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro); 
        }
        ImprimeTabuleiro(jogo.tabuleiro);
        i++;
    }
}

int AcabouJogo(tJogo jogo){
    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }
    
    if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }
    
    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        printf("Sem vencedor!\n");
        return 1;
    }

    return 0;
}

int ContinuaJogo(){
char decisao = '\0';
    printf("Jogar novamente? (s,n)\n");
    
    while (scanf(" %c", &decisao) == 1) {
        if (decisao == 's' || decisao == 'S') {
            return 1;
        }
        if (decisao == 'n' || decisao == 'N') {
            return 0;
        }
    }
    return 0;
}

