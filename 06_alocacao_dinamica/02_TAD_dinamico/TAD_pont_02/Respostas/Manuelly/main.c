#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"

int main(){
    tEleicao * eleicao;
    eleicao = InicializaEleicao();
    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);
    return 0;
}