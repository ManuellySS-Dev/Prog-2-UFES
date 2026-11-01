#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "missil.h"
#include "cidade.h"
#include "defesa.h"

int main(){
    tCidade cidade;
    cidade = CriaCidade();
    LeEntrada(cidade);
    ProcessaAtaques(cidade);
    ImprimeDados(cidade);
    LiberaCidade(cidade);
    return 0;
}