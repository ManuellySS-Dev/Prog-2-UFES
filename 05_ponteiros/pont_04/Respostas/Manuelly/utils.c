#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

void LeNumeros(int *array, int tamanho){
    int i=0;
    for(i=0; i<tamanho; i++){
        scanf("%d ", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int i=0;
    *media =0;
    *maior = -1000;
    *menor = 1000;
    for(i=0; i<tamanho; i++){
        if(array[i] < *menor){
            *menor = array[i];
        }
        if(array[i] > *maior){
            *maior = array[i];
        }
        *media+= array[i];
    }
    *media = ((*media)/tamanho);
}