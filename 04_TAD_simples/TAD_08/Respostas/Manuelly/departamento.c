#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"
#include <string.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento Departamento;
    strcpy(Departamento.c1, c1);
    strcpy(Departamento.c2, c2);
    strcpy(Departamento.c3, c3);
    strcpy(Departamento.nome, nome);
    strcpy(Departamento.diretor, diretor);
    Departamento.m1 = m1;
    Departamento.m2 = m2;
    Departamento.m3 = m3;
    Departamento.media_geral = calculaMediaGeralDepartamento(Departamento);
    return Departamento;
}

void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n\n", calculaDesvioPadraoDepartamento(depto));
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    tDepartamento departamento;
    int i=0, j=0;
    for(i=0; i<tamanho-1; i++){
        for(j=0; j<tamanho-i-1; j++){
            if(calculaMediaGeralDepartamento(d[j]) < calculaMediaGeralDepartamento(d[j+1])){
                departamento = d[j];
                d[j] = d[j+1];
                d[j+1] = departamento;
            }
        }
    }
}

int validaMediaDepartamento (int media){
    if(media >=0 && media<= 10){
        return 1;
    }
    return 0;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double somatorio=0;
    somatorio += (depto.m1 - depto.media_geral) * (depto.m1 - depto.media_geral);
    somatorio += (depto.m2 - depto.media_geral) * (depto.m2 - depto.media_geral);
    somatorio += (depto.m3 - depto.media_geral) * (depto.m3 - depto.media_geral);  
    return sqrt(somatorio/3.0);
}

double calculaMediaGeralDepartamento(tDepartamento depto){
   return ((depto.m1+depto.m2+depto.m3)/3.0); 
}
