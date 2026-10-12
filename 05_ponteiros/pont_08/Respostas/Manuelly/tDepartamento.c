#include "tDepartamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento departamento;

    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;

    return departamento;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("Departamento: %s\n", depto.nome);
    printf("    Diretor: %s\n", depto.diretor);
    printf("    1o curso: %s\n", depto.curso1);
    printf("    Media do 1o curso: %d\n", depto.m1);
    printf("    2o curso: %s\n", depto.curso2);
    printf("    Media do 2o curso: %d\n", depto.m2);
    printf("    3o curso: %s\n", depto.curso3);
    printf("    Media do 3o curso: %d\n", depto.m3);
    printf("    Media dos cursos: %.2f\n", ((depto.m3+depto.m1+depto.m2)/3.0));
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    int medias[num_deptos], i=0, j=0;
    tDepartamento aux;

    for(i=0; i<num_deptos; i++){
        medias[i] = ((vetor_deptos[i].m3+vetor_deptos[i].m1+vetor_deptos[i].m2)/3);
    }
    for(i=0; i<num_deptos-1; i++){
        for(j=i; j<num_deptos- i-1; j++){
            if(medias[j] < medias[j+1]){
                aux = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j+1];
                vetor_deptos[j+1] = aux;
            }
        }
    }
    printf("\n");
}




