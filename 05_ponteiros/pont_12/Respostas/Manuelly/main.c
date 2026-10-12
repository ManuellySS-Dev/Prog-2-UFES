#include <stdio.h>
#include "vetor.h"
#include <stdlib.h>

int soma(int a, int b){
    return a+b;
}
int multiplica(int a, int b){
    return a*b;
}
int main(){
    Vetor vetor;
    LeVetor(&vetor);
    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, multiplica));
    return 0;
}