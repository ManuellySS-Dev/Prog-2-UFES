#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"

struct Operacao{
    float valor;
    int id_conta;
};

tOperacao* CriaOperacao(tConta* conta, float valor){
    tOperacao * op = (tOperacao*) calloc(1, sizeof(tOperacao));
    op->id_conta = RetornaIdConta(conta);
    op->valor = valor;
    return op;
}

void DestroiOperacao(tOperacao* op){
    free(op);
}

float ConsultaValorOperacao(tOperacao* op){
    return op->valor;
}

void ImprimeOperacao(tOperacao* op){
    printf("\nOperação na conta %d com valor %.2f", op->id_conta, op->valor);
}