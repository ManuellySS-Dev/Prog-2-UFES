#include <stdio.h>
#include "funcionario.h"
#include "empresa.h"

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    int i = 0;
    
    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa(){
    int id = 0, qtd = 0;
    tEmpresa empresa;
    
    scanf("%d", &id); 
    
    empresa = criaEmpresa(id);
    
    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i = 0;

    for(i = 0; i < empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario)){
            return empresa;
        }
    }

    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;
    
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i = 0;
    printf("Empresa %d:\n", empresa.id);
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}