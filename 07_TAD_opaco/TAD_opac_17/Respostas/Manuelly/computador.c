#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "computador.h"
//tah dando diferenca de um espaco em branco no diff na linha 163 do caso 3 por algum motivo inexplicavel
struct Computador{
    int n;
    int min, max;
    int valor_a_ser_adivinhado;
    int jogos_jogados, jogos_ganhos, jogos_perdidos;
    tJogo * jogo;
};

tComputador* CriaComputador(){
    printf("Jogo de adivinhação\n");
    tComputador * computador = (tComputador*) calloc(1, sizeof(tComputador));
    computador->jogo = CriaJogo();
        computador->jogos_ganhos=0;
        computador->jogos_jogados=0;
        computador->jogos_perdidos=0;
    return computador;
}

void DestroiComputador(tComputador* comp){
    DestroiJogo(comp->jogo);
    free(comp);
}

void GerenciaJogo(tComputador *computador){

    do{
        printf("\nForneca um numero no intervalo entre 1 e 10000: \n");
        scanf(" %d", &computador->n);
    }while(computador->n <1 || computador->n >10000);
    
    printf("Forneca um intervalo de numeros naturais: ");
    do{
        scanf(" %d %d", &computador->min, &computador->max);
        if(computador->min >= computador->max){
            printf("\nO primeiro numero do intervalo deve ser inferior ao segundo\n");
            printf("Forneca um intervalo de numeros naturais: ");
        }
        if(computador->max >= 1000000000){
            printf("\nO segundo numero do intervalo deve ser menor que 1.000.000.000\n");
            printf("Forneca um intervalo de numeros naturais: ");
        }
    }while(computador->min >= computador->max || computador->max >= 1000000000);
    //printf("%d %d %d\n", computador->max, computador->min, computador->n);
    DefineMaximo(computador->jogo, computador->max);
    DefineMinimo(computador->jogo, computador->min);
    CalculaValorASerAdivinhado(computador->jogo, computador->n);
    CalculaNumeroTentativas(computador->jogo);

    if(ProcessaTentativas(computador->jogo)){
        computador->jogos_ganhos++;
    }else{
        computador->jogos_perdidos++;
    }
    computador->jogos_jogados++;
}

void ImprimeRelatorio (tComputador* computador){
    char opcao = '\0';
    while(opcao != 'n' && opcao != 's'){
        scanf(" %c", &opcao);
        printf("\nDeseja continuar a jogar (s/n): ");
    }
    if(opcao == 's'){
        GerenciaJogo(computador);
        ImprimeRelatorio(computador);
    }else{
        printf("\nObrigado por jogar comigo. Desta vez, voce jogou %d jogo(s), ganhou %d jogo(s) e perdeu %d jogo(s). Ate a proxima!\n", computador->jogos_jogados, computador->jogos_ganhos, computador->jogos_perdidos);
    }
}