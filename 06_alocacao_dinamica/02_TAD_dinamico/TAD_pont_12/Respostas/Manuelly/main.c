#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int main (){
    int numero_a_ser_encontrado=0, resultado_busca=0;
    Array * array;

    array = CriarArray();
    LerArray(array);
    scanf("%d", &numero_a_ser_encontrado);
    OrdenarArray(array);
    resultado_busca = BuscaBinariaArray(array, numero_a_ser_encontrado);
    if(resultado_busca != -1){
        printf("Elemento %d encontrado no índice %d.\n", numero_a_ser_encontrado, resultado_busca);
    }else{
        printf("Elemento %d não encontrado no array (-1).\n", numero_a_ser_encontrado);
    }
    DestruirArray(array);
    return 0;
}

