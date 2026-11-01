#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "computador.h"

struct Jogo{
    int n;
    int qtd_tentativas;
    int max, min;
    int valor_a_ser_adivinhado;
};

tJogo* CriaJogo(){
    tJogo * jogo = (tJogo*) calloc(1, sizeof(tJogo));
    return jogo;
}

void DestroiJogo(tJogo* jogo){
    free(jogo);
}

void DefineMaximo(tJogo* jogo, int max){
    jogo->max = max;
}

void DefineMinimo(tJogo* jogo, int min){
    jogo->min = min;
}

int EhPrimo(long long int num) {
    if (num <= 1) return 0;
    for (long long int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void CalculaValorASerAdivinhado(tJogo *jogo, int n){
    long long int termo_atual = 1; //no teste 3 os numeros estavam estourando o tamanho do int
    long long int anterior = 0;
    long long int proximotermo;
    int primos_encontrados = 0;
    int parte_inteira = 0;
    long long int f = 0; 
    
    while (primos_encontrados < n) {
        proximotermo = anterior + termo_atual;
        anterior = termo_atual;
        termo_atual = proximotermo;

        if (EhPrimo(anterior)) {
            primos_encontrados++;
            if (primos_encontrados == n) {
                f = anterior;
                break;
            }
        }
    }
    
    int r = f % 101;
    
    float x = (((float)r / 100.0) * (jogo->max - jogo->min)) + jogo->min;

    parte_inteira = (int)x;
    if (x - parte_inteira >= 0.5) {
        jogo->valor_a_ser_adivinhado = parte_inteira + 1;
    } else {
        jogo->valor_a_ser_adivinhado = parte_inteira;
    }
}


void CalculaNumeroTentativas(tJogo *jogo){
    int parte_inteira=0;
    float mc=0;
    mc = log2(jogo->max - jogo->min + 1) + 1; //log2 eh uma funcao que calcula logo na base 2 logo(2) calcula log de 2 na base e
    parte_inteira = mc;
    jogo->qtd_tentativas = parte_inteira;
}

int ProcessaTentativas(tJogo* jogo){
    CalculaNumeroTentativas(jogo);
    printf("\nVoce tem direito a %d tentativas\n", jogo->qtd_tentativas);
    int i=0, n=0;
    for(i=0; i<jogo->qtd_tentativas; i++){
        scanf("%d", &n);
        if(n == jogo->valor_a_ser_adivinhado){
            printf("Tentativa %d: \n", (i+1));
            printf("Parabens, voce ganhou!");
            return 1;
        }else if(n > jogo->valor_a_ser_adivinhado){
            printf("Tentativa %d: \nAlta\n", (i+1));
        }else{
            printf("Tentativa %d: \nBaixa\n", (i+1));
        }
    }
    printf("Voce perdeu! O numero escolhido foi %d\n", jogo->valor_a_ser_adivinhado);
    return 0;
}