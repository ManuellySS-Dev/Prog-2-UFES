#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"
#include "candidato.h"
#include "eleicao.h"

int main(){
    tEleicao eleicao;
    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao (eleicao);
    ImprimeResultadoEleicao(eleicao);
    return 0;
}