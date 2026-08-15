#include <stdio.h>
#include <stdlib.h>

/*Programa que auxilia um jogador a sair de uma posicao inicial e ir ateh uma final dentro de uma matriz*/
typedef struct{
    int Yi;
    int Xi;
    int Ya;//posicao atual do jogador
    int Xa;
    int Yf;
    int Xf;
    int indice_Xa; //a posicao na matriz comeca em 0 e os x e y comecam em 1 dai preciso regular isso
    int indice_Ya;
    char prioridade[4];
}tJogador;

void PensaCaminhoJogador(int qtd_linhas, int qtd_colunas, int matriz[][qtd_colunas], tJogador jogador){
    int i=0, moveu=0;
    jogador.indice_Ya = jogador.Ya-1; //o indice eh soh pra eu saber a posicao atual na matriz
    jogador.indice_Xa = jogador.Xa-1;
    matriz[jogador.indice_Ya][jogador.indice_Xa]=1; //pra nao voltar caminho

    while(1){
        moveu =0;
        if(jogador.Xa == jogador.Xf && jogador.Ya == jogador.Yf){
            exit(0);
        }

        for(i=0; i<4; i++){
            if(jogador.prioridade[i] == 'B'){
                if(jogador.indice_Ya+1 < qtd_linhas){
                    if(matriz[jogador.indice_Ya+1][jogador.indice_Xa] == 0){
                        moveu = 1;
                        jogador.Ya++;
                        jogador.indice_Ya++;
                        matriz[jogador.indice_Ya][jogador.indice_Xa]=1; //pra nao voltar caminho
                        printf("(%d,%d) ", jogador.Ya, jogador.Xa);
                        break;
                    }
                }
            }
            if(jogador.prioridade[i] == 'C'){
                if(jogador.indice_Ya-1 >= 0){
                    if(matriz[jogador.indice_Ya-1][jogador.indice_Xa] == 0){
                        moveu = 1;
                        jogador.Ya--;
                        jogador.indice_Ya--;
                        matriz[jogador.indice_Ya][jogador.indice_Xa]=1; //pra nao voltar caminho
                        printf("(%d,%d) ", jogador.Ya, jogador.Xa);
                        break;
                    }
                }
            }
            if(jogador.prioridade[i] == 'D'){
                if(jogador.indice_Xa+1 < qtd_colunas){
                    if(matriz[jogador.indice_Ya][jogador.indice_Xa+1] == 0){
                        moveu = 1;
                        jogador.Xa++;
                        jogador.indice_Xa++;
                        matriz[jogador.indice_Ya][jogador.indice_Xa]=1; //pra nao voltar caminho
                        printf("(%d,%d) ", jogador.Ya, jogador.Xa);
                        break;
                    }
                }
            }
            if(jogador.prioridade[i] == 'E'){
                if(jogador.indice_Xa-1 >= 0){
                    if(matriz[jogador.indice_Ya][jogador.indice_Xa-1] == 0){
                        moveu = 1;
                        jogador.Xa--;
                        jogador.indice_Xa--;
                        matriz[jogador.indice_Ya][jogador.indice_Xa]=1; //pra nao voltar caminho
                        printf("(%d,%d) ", jogador.Ya, jogador.Xa);
                        break;
                    }
                }
            }
        }

        if(moveu == 0 ){
            exit(0); //se o for acabou e nao houve nenhum movimento eh porque nao da mais pra mover
        }
    }
}

int main(){
    int i = 0, j = 0, qtd_colunas=0, qtd_linhas=0;
    tJogador jogador;
    scanf("%d %d\n", &qtd_linhas, &qtd_colunas);
    int matriz[qtd_linhas][qtd_colunas];

    for(i=0; i<qtd_linhas; i++){
        for(j=0; j<qtd_colunas; j++){
            scanf("%d ", &matriz[i][j]);
        }
        scanf("\n");
    }

    scanf("%d %d\n%d %d\n", &jogador.Yi, &jogador.Xi, &jogador.Yf, &jogador.Xf);

    for(i=0; i<4; i++){
        scanf("%c",&jogador.prioridade[i]);
    }
    jogador.Xa = jogador.Xi;
    jogador.Ya = jogador.Yi;
    printf("(%d,%d) ", jogador.Yi, jogador.Xi);
    PensaCaminhoJogador(qtd_linhas, qtd_colunas, matriz, jogador);
    return 0;
}