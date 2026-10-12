#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

tJogo* CriaJogo(){
    tJogo * jogo = (tJogo*) calloc(1, sizeof(tJogo));
    return jogo;
}

void ComecaJogo(tJogo* jogo){
    int i=1;
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);
    do{
        if(i % 2 != 0){
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
        }else{
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
        }
        i++;
    }while(AcabouJogo(jogo) == 0);
}

int AcabouJogo(tJogo* jogo){
    if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }else if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }else if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro)){
        printf("Sem vencedor!\n");
        return 1;
    }
    return 0;
}

int ContinuaJogo(){
    char opcao = '\0';
    printf("Jogar novamente? (s,n)\n");
    do{
        scanf(" %c", &opcao);
    }while(opcao != 's' && opcao!= 'n');
    if(opcao == 's'){
        return 1;
    }else{
        return 0;
    }
}

void DestroiJogo(tJogo* jogo){
    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}