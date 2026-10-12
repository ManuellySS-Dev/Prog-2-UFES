/*codigo que converte um numero decimal pra sua forma octal*/
#include <stdio.h>

#define OITO 8

int main(){
    int num_algarismo_do_num_octal = 0, resto_divisao = 0, resultado_divisao = 1, decimal = 0, i = 0, j = 0; 
    int num_octal[100];

    scanf("%d", &decimal);

    resultado_divisao = decimal;

    while(resultado_divisao > 0){
        resto_divisao = resultado_divisao % OITO;
        resultado_divisao = resultado_divisao / OITO;
        num_octal[i] = resto_divisao;
        i++;
    }

    for(j = (i-1); j >= 0; j--){
        printf("%d", num_octal[j]);
    }

    return 0;
}