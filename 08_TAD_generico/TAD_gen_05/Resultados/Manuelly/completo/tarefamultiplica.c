#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"
#include "tarefasoma.h"

struct mult{
    float n1,n2; 
};

tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult * multiplicacao = (tMult*) calloc(1, sizeof(tMult));
    multiplicacao->n1 = n1;
    multiplicacao->n2 = n2;
    return multiplicacao;
}

void ExecutaTarefaMultiplicar(void *mult){
    tMult * mutiplicacao = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", mutiplicacao->n1, mutiplicacao->n2, (mutiplicacao->n1 * mutiplicacao->n2) );
}

void DestroiTarefaMultiplicar(void *mult){
    tMult * mutiplicacao = (tMult*) mult;
    free(mutiplicacao);
}