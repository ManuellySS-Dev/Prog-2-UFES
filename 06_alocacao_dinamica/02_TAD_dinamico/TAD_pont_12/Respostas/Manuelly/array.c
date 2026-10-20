#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array *CriarArray(){
    Array * array = (Array*) calloc(1, sizeof(Array));
    if(array == NULL){
        printf("Nao foi possivel alocar memoria para Array\n");
        exit(0);
    }
    array->tamanho =0;
    array->data = (int*) calloc(200, sizeof(int));
    return array;
}

void DestruirArray(Array *array){
    free(array->data);
    free(array);
}

void LerArray(Array *array){
    char carac = '\0';
    array->tamanho = 0;

    while(1){
        scanf("%d%c", &array->data[array->tamanho], &carac);
        if(carac == '.'){
            array->tamanho++;
            break;
        }
        array->tamanho++;
    }
}

void OrdenarArray(Array *array){
    int i=0, j=0, aux=0;
    for(i=0; i< array->tamanho-1; i++){
        for(j=0; j<array->tamanho-1-i; j++){
            if(array->data[j] > array->data[j+1]){
                aux = array->data[j];
                array->data[j] = array->data[j+1];
                array->data[j+1] = aux;
            }   
        }
    }
}

int BuscaBinariaArray(Array *array, int elementoBuscado){
    int i=0, indice_elemento=0, indice_tentado=0, limite_anterior=0, limite_final=0;
    limite_final = array->tamanho;
    indice_tentado = (array->tamanho/ 2);

    while(1){
        if(i>30){
            return -1;
        }
        //printf("%d\n", indice_tentado);
        if(array->data[indice_tentado] == elementoBuscado){
            indice_elemento = indice_tentado;
            return indice_elemento;
        }else if (array->data[indice_tentado] < elementoBuscado){
            limite_anterior = indice_tentado;
            indice_tentado = (limite_anterior + (indice_tentado /2));
        }else if(array->data[indice_tentado] > elementoBuscado){
            indice_tentado = (indice_tentado /2);
            limite_final = indice_tentado;
        }
        i++;
    }
}