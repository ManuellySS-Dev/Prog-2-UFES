#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"

int main(){
    tAgencia * agencia;
    agencia = CriaAgencia();
    int qtd_contas=0, i=0;
    printf("--- Agencia Bancaria ---\n");
    LeOperacoes(agencia);
    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);
    DestroiAgencia(agencia);
    return 0;
}