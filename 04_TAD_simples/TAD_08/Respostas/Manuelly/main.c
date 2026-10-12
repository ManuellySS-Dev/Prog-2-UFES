#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"

int main(){
    int qtd_departamentos=0, i=0, m1=0, m2=0,m3=0, qtd_departamentos_validos=0;
    char nome[100], diretor[100], c2[100], c1[100], c3[100];
    scanf("%d\n", &qtd_departamentos);
    tDepartamento departamentos[qtd_departamentos], departamento;

    //le departamentos
    for(i=0; i<qtd_departamentos; i++){
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", c1);
        scanf("%[^\n]\n", c2);
        scanf("%[^\n]\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        departamento = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
        if(validaMediaDepartamento (calculaMediaGeralDepartamento(departamento))){
            departamentos[qtd_departamentos_validos] = departamento;
            departamentos[qtd_departamentos_validos].media_geral = calculaMediaGeralDepartamento(departamentos[qtd_departamentos_validos]);
            qtd_departamentos_validos++;
        }
    }

    //ordena departamentos buble short
    ordenaPorMediaDepartamentos(departamentos, qtd_departamentos_validos);

    //imprime atributos
    for(i=0; i<qtd_departamentos_validos; i++){
        imprimeAtributosDepartamento(departamentos[i]);
    }
    return 0;
}