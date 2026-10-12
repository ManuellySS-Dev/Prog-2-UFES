#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

int main(){
    int num_pes=0, i=0;
    scanf("%d\n", &num_pes);
    tPessoa pessoas[num_pes];

    for(i=0; i<num_pes; i++){
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoas);

    for(i=0; i<num_pes; i++){
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}