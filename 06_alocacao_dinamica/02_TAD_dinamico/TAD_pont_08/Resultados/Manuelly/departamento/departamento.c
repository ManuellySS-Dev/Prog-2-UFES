#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "departamento.h"
#include <math.h>

tDepartamento* CriaDepartamento(){
    tDepartamento * depto = (tDepartamento*) calloc(1, sizeof(tDepartamento));
    depto->nome = (char*) calloc(STRING_MAX, sizeof(char));
    depto->diretor = (char*) calloc(STRING_MAX, sizeof(char));
    depto->c1 = (char*) calloc(STRING_MAX, sizeof(char));
    depto->c2 = (char*) calloc(STRING_MAX, sizeof(char));
    depto->c3 = (char*) calloc(STRING_MAX, sizeof(char));
    return depto;
}

void LiberaMemoriaDepartamento(tDepartamento* depto){
    free(depto->c1);
    free(depto->c3);
    free(depto->c2);
    free(depto->nome);
    free(depto->diretor);
    free(depto);
}

void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    strcpy(depto->nome, nome);
    strcpy(depto->diretor, diretor);
    strcpy(depto->c2, c2);
    strcpy(depto->c1, c1);
    strcpy(depto->c3, c3);
    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;
    depto->media_geral = CalculaMediaGeralDepartamento(depto);
}

void ImprimeAtributosDepartamento (tDepartamento* depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto->nome);
    printf("diretor => %s\n", depto->diretor);
    printf("curso1 => %s, media1 => %d\n", depto->c1, depto->m1);
    printf("curso2 => %s, media2 => %d\n", depto->c2, depto->m2);
    printf("curso3 => %s, media3 => %d\n", depto->c3, depto->m3);
    printf("media geral => %.2f\n", depto->media_geral);
    printf("desvio padrao => %.2f\n\n", CalculaDesvioPadraoDepartamento(depto));
    //LiberaMemoriaDepartamento(depto);
}

int ValidaMediaDepartamento (int media){
    if(media >=0 && media <=10){
        return 1;
    }else{
        return 0;
    }
}

double CalculaDesvioPadraoDepartamento(tDepartamento* depto){
    float somatorio=0, media;
    media = CalculaMediaGeralDepartamento(depto);
    somatorio += (depto->m1 - media) * (depto->m1 - media);
    somatorio += (depto->m2 - media) * (depto->m2 - media);
    somatorio += (depto->m3 - media) * (depto->m3 - media);
    return sqrt(somatorio/3.0);
}

double CalculaMediaGeralDepartamento(tDepartamento* depto){
    return ((depto->m1 +depto->m2+depto->m3)/3.0);
}

void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho){
    int i=0, j=0;
    tDepartamento * aux;

    for(i=0; i<tamanho-1; i++){
        for(j=0; j<tamanho-i-1; j++){
            if(d[j]->media_geral < d[j+1]->media_geral){
                aux = d[j];
                d[j] = d[j+1];
                d[j+1] = aux;
            }
        }
    }
}