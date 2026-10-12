#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
//jogo da velha
int main(){
    tJogo * jogo;
    jogo = CriaJogo();
    ComecaJogo(jogo);
    while(ContinuaJogo(jogo)){
        DestroiJogo(jogo);
        jogo = CriaJogo();
        ComecaJogo(jogo);
    }
    DestroiJogo(jogo);
    return 0;
}