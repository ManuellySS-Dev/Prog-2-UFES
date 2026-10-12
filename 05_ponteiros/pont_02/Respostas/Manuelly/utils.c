#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void LeIntervalo(int * m, int * n){
    scanf("%d %d\n", m, n);
}

int EhPrimo(int n){
    int numero_divisores=0,i=0;
    if(n==2){
        return 1;
    }
    if(n % 2 != 0){
        for(i=2; i<n; i++){
            if(n%i ==0){
                //printf("numero:%d | divisor: %d\n", n, i);
                numero_divisores++;
            }
        }
        if(numero_divisores != 0){
            return 0;
        }else{
            return 1;
        }
    }
    return 0;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    //printf("entrou na funcao \n");
    *maior = -3000;
    *menor = 30000;
    int primo=0;
    primo = m;
    while(primo != n+1){
        if(EhPrimo(primo)){
            if(primo<*menor){
                *menor = primo;
            }
            if(primo > *maior){
                *maior = primo;
            }
        }
        primo++;
    }
}