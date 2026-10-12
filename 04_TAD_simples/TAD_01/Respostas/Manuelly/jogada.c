#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

tJogada LeJogada(){
    tJogada jogada;
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d\n", &jogada.x, &jogada.y) == 2){
        jogada.sucesso = 1;
    }else{
        jogada.sucesso = 0;
    }
    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.sucesso == 1){
        return 1;
    }else if(jogada.sucesso == 0){
        return 0;
    }else{
        exit(0);
    }
}