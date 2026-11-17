#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"
#include "tarefasoma.h"

struct impr{
    char * msg;
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr * impressao = (tImpr*) calloc(1, sizeof(tImpr));
    impressao->msg = (char*) calloc(50, sizeof(char));
    strcpy(impressao->msg, msg);
    return impressao;
}

void ExecutaTarefaImprimir(void *imp){
    tImpr * impressao = (tImpr*) imp;
    printf("\n%s", impressao->msg);
}

void DestroiTarefaImprimir(void *imp){
    tImpr * impressao = (tImpr*) imp;
    free(impressao->msg);
    free(impressao);
}