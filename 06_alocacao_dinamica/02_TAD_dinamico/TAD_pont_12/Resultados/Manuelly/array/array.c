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
    int limite_anterior = 0;
    int limite_final = array->tamanho - 1; 
    int indice_tentado;

    while (limite_anterior <= limite_final) {
        // Calcula o ponto médio correto entre os dois limites atuais
        indice_tentado = limite_anterior + (limite_final - limite_anterior) / 2;


        if (array->data[indice_tentado] == elementoBuscado) {
            return indice_tentado; // Achou! Retorna o índice
        } 
        else if (array->data[indice_tentado] > elementoBuscado) {
            // O elemento buscado é menor, então descartamos a metade direita
            limite_final = indice_tentado - 1;
        } 
        else {
            // O elemento buscado é maior, então descartamos a metade esquerda
            limite_anterior = indice_tentado + 1;
        }
    }

    // Se o loop terminar e não achou, o elemento não está no array
    return -1;
}