#include <stdio.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario funcionario;
    funcionario.id =id;
    funcionario.salario = salario;
    return funcionario;
}

tFuncionario leFuncionario(){
    int id=0;
    float salario=0;
    tFuncionario funcionario;
    scanf("%d %f\n", &id, &salario);
    funcionario = criaFuncionario(id, salario);
    return funcionario;
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}