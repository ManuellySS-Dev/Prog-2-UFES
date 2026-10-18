#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "departamento.h"

int main(){
    int qtd_deptos=0, i=0;
    scanf("%d\n", &qtd_deptos);
    tDepartamento * departamentos[qtd_deptos];
    char nome[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX]; 
    int m1=0,m2=0,m3=0;
    for(i=0; i<qtd_deptos; i++){
        departamentos[i] = CriaDepartamento();
        scanf(" %[^\n]\n", nome);
        scanf(" %[^\n]\n", diretor);
        scanf(" %[^\n]\n", curso1);
        scanf(" %[^\n]\n", curso2);
        scanf(" %[^\n]\n", curso3);
        scanf("%d %d %d", &m1,&m2,&m3);
        PreencheDadosDepartamento(departamentos[i], curso1,curso2,curso3, nome,m1,m2,m3, diretor);
    }

    OrdenaPorMediaDepartamentos(departamentos, qtd_deptos);

    for(i=0; i<qtd_deptos; i++){
        ImprimeAtributosDepartamento(departamentos[i]);
        LiberaMemoriaDepartamento(departamentos[i]);
    }

    return 0;
}