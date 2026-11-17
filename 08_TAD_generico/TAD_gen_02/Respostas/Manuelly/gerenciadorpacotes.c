#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

struct gerenciadorpacotes {
    int qtd_pacotes;
    tPacote** pacotes;
};

tGerenciador* CriaGerenciador() {
    tGerenciador* gen = (tGerenciador*) calloc(1, sizeof(tGerenciador));
    gen->pacotes = NULL;
    gen->qtd_pacotes = 0;
    return gen;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    //nao entendi essa parte pesquisar mais
    tPacote** aux = (tPacote**) realloc(geren->pacotes, (geren->qtd_pacotes + 1) * sizeof(tPacote*));

    if (aux == NULL) { //auxiliar pra caso de errado o realloc
        return;
    }
    geren->pacotes = aux;

    geren->pacotes[geren->qtd_pacotes] = pac;
    geren->qtd_pacotes++;
}

void DestroiGerenciador(tGerenciador* geren) {
    for (int i = 0; i < geren->qtd_pacotes; i++) {
        DestroiPacote(geren->pacotes[i]);
    }

    free(geren->pacotes);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    if (idx >= 0 && idx < geren->qtd_pacotes) {
        ImprimePacote(geren->pacotes[idx]);
    }
}

void ImprimirTodosPacotes(tGerenciador* geren) {
    for (int i = 0; i < geren->qtd_pacotes; i++) {
        ImprimePacote(geren->pacotes[i]);
    }
}