#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tadgen.h"

int main(){
    int tipo=0, qtd_elementos=0;

    tGeneric * gen;


    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d", &tipo,&qtd_elementos);
    
    gen = CriaGenerico(tipo, qtd_elementos);

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return 0;
}