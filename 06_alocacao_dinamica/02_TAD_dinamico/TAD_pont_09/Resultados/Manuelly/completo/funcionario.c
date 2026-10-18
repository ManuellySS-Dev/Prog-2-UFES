#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

tFuncionario* CriaFuncionario(){
    tFuncionario * funcionario = (tFuncionario*) calloc(1, sizeof(tFuncionario));
    return funcionario;
}

void ApagaFuncionario(tFuncionario* funcionario){
    free(funcionario);
}

void LeFuncionario(tFuncionario* funcionario){
    scanf("%d %f", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario* funcionario){
    return funcionario->id;
}

void ImprimeFuncionario(tFuncionario* funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario->id, funcionario->salario);
}
