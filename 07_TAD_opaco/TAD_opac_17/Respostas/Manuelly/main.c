#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "computador.h"

int main(){
    tComputador * computer;

    computer = CriaComputador();
    GerenciaJogo(computer);
    ImprimeRelatorio(computer);
    DestroiComputador(computer);

    return 0;
}