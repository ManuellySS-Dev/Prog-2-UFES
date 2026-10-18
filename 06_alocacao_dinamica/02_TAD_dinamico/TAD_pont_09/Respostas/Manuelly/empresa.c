#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

tEmpresa* CriaEmpresa(){
    tEmpresa * empresa = (tEmpresa*) calloc(1, sizeof(tEmpresa));
    if(empresa == NULL){
        printf("Nao foi possivel alocar memoria para empresa");
        exit(0);
    }
    empresa->funcionarios = (tFuncionario**) calloc(15, sizeof(tFuncionario*));
    empresa->qtdFuncionarios=0;
    empresa->id=0;
    return empresa;
}

void LeEmpresa(tEmpresa* empresa){
    int i=0, nao_pode_contratar =0, j=0, qtd=0;
    scanf(" %d %d", &empresa->id, &qtd);

    for(j=0; j<qtd; j++){
        nao_pode_contratar=0;
        tFuncionario * funcionario;
        funcionario = CriaFuncionario();
        LeFuncionario(funcionario);
        for(i=0; i<empresa->qtdFuncionarios; i++){
            if(i!=j){
                if(GetIdFuncionario(empresa->funcionarios[i]) == funcionario->id){
                    printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, funcionario->id);
                    nao_pode_contratar = 1;
                    ApagaFuncionario(funcionario);
                    break; //sem o break o valgrind aponta uso apos liberacao jah que o for vai continuar buscando o id do funcionario que eu jah liberei memoria
                }
            }
        }
        if(nao_pode_contratar == 0){ 
            ContrataFuncionarioEmpresa(empresa, funcionario);
        }
    }
}

void ApagaEmpresa(tEmpresa* empresa){
    int i=0;
    for(i=0; i<empresa->qtdFuncionarios; i++){
        ApagaFuncionario(empresa->funcionarios[i]);
    }
    for(i=empresa->qtdFuncionarios; i<15; i++){
        free(empresa->funcionarios[i]);
    }
    free(empresa->funcionarios);
    free(empresa);
}

void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
    empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
    empresa->qtdFuncionarios++;
}

void ImprimeEmpresa(tEmpresa *empresa){
    int i=0;
    printf("Empresa %d:\n", empresa->id);
    for(i=0; i<empresa->qtdFuncionarios; i++){
        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}