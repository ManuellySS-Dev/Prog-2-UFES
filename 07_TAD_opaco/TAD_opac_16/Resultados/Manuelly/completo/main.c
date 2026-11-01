#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sistema.h"


int main(){
    tSistema * sistema;
    sistema = CriaSistema();
    LeSistema(sistema);
    ImprimeFaturamentoSistema(sistema);
    DestroiSistema(sistema);
    return 0;
}