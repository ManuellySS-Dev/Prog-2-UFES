#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade){
    Lesao * l = (Lesao*) calloc(1, sizeof(Lesao));
    if(l == NULL){
        exit(0);
    }
    strcpy(l->cartaoSus, cartaoSus);
    strcpy(l->id, id);
    strcpy(l->diagnostico, diagnostico);
    strcpy(l->regiao, regiao);
    l->malignidade = malignidade;
    return l;
}

Lesao *lerLesao(){
    char cartao[MAX_CARTAO_LES], id[MAX_ID_LES], diagnostico[MAX_DIAG_LES], regiao[MAX_REG_LES];
    int malignidade=0;
    scanf(" %[^\n]\n", cartao);
    scanf(" %[^\n]\n", id);
    scanf(" %[^\n]\n", diagnostico);
    scanf(" %[^\n]\n", regiao);
    scanf(" %d\n", &malignidade);
    return criaLesao(cartao, id, diagnostico, regiao, malignidade);
}

char *getCartaoSusLesao(Lesao *l){
    return l->cartaoSus;
}

int verificaCirurgicaLesao(Lesao *l){
    if(l->malignidade > 50){
        return 1;
    }else{
        return 0;
    }
}

void imprimeIdLesao(Lesao *l){
    printf("%s", l->id);
}

void liberaLesao(Lesao *l){
    free(l);
}