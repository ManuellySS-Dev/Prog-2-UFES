#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tadgen.h"

struct generic{
    void * vetor;
    Type tipo;
    int qtd_elementos;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric * generico = (tGeneric*) calloc(1, sizeof(tGeneric));
    if(generico == NULL){
        exit (0);
    }
    if(type == FLOAT){
        generico->vetor = (float*) calloc(numElem, sizeof(float));
    }else{
        generico->vetor = (int*) calloc(numElem, sizeof(int));
    }

    generico->tipo = type;
    generico->qtd_elementos = numElem;
    return generico;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");

    for(int i=0; i<gen->qtd_elementos; i++){
        if(gen->tipo == FLOAT){
            float* v_float = (float*) gen->vetor; //cast pra float antes de ler assim o scanf sabe o tamanho do que vai leir 
            scanf("%f", &v_float[i]); //como o endereço de v_float é igual ao endereco de gen_vetor ao ler o v_float eu altero também o gen->vetor de uma vez
        }else{
            int* v_int = (int*) gen->vetor;
            scanf("%d", &v_int[i]);
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    for(int i=0; i<gen->qtd_elementos; i++){
        if(gen->tipo == FLOAT){
            float* v_float = (float*) gen->vetor;
            printf("%.2f ", v_float[i]);
        }else{
            int* v_int = (int*) gen->vetor;
            printf("%d ", v_int[i]);
        }
    }
    printf("\n");
}
