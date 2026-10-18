#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"



int main(){
    int qtd_empresas=0, i=0, j=0, qtd_funcionarios=0;
    scanf("%d", &qtd_empresas);
    tEmpresa * empresas[qtd_empresas];

    for(i=0; i<qtd_empresas; i++){
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }
    for(i=0; i<qtd_empresas; i++){
        ImprimeEmpresa(empresas[i]);
    }
    for(i=0; i<qtd_empresas; i++){
        ApagaEmpresa(empresas[i]);
    }
    return 0;
}