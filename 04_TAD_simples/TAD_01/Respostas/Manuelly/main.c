#include <stdio.h>
#include "jogo.h"

int main(){
    tJogo jogo;
    while(1){
        jogo = CriaJogo();
        ComecaJogo(jogo);
        if(!ContinuaJogo()){
            break;
        }
    }
    return 0;
}