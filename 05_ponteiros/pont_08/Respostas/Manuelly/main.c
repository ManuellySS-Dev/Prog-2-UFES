#include "tDepartamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n_departamentos=0, i=0;
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
    scanf("%d ", &n_departamentos);
    tDepartamento departamentos[n_departamentos];

    for(i=0; i<n_departamentos; i++){
        scanf(" %[^\n]\n", nome);
        scanf(" %[^\n]\n", diretor);
        scanf(" %[^\n]\n", curso1);
        scanf(" %[^\n]\n", curso2);
        scanf(" %[^\n]\n", curso3);
        scanf("%d %d %d\n", &m1,&m2,&m3);

        departamentos[i] = CriaDepartamento(curso1,curso2,curso3, nome,m1,m2,m3, diretor);

    }

    OrdenaDepartamentosPorMedia(departamentos, n_departamentos);

    for(i=0; i<n_departamentos; i++){
        ImprimeAtributosDepartamento(departamentos[i]);
    }

    return 0;
}