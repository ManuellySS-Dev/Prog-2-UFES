#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "fila.h"
#include "movel.h"
void DestroiElemento(DataType Elemento){
    tMovel*movel = (tMovel*) Elemento;
    DestroiMovel(movel);
}

int main(){
    int num_operacoes=0;
    char operacao[30];
    Fila * fila;
    fila = FilaConstruct();
    scanf("%d\n", &num_operacoes);

    for(int i=0; i<num_operacoes; i++){
        scanf(" %8s", operacao);
        if(!strcmp(operacao, "ENTRADA")){
            FilaPush(fila, LeMovel());
        }else{
            tMovel * movel = (tMovel*) FilaPop(fila);
            ImprimeMovel(movel);
            DestroiMovel(movel);
        }
    }
    FilaDestroy(fila, DestroiElemento);
    return 0;
}