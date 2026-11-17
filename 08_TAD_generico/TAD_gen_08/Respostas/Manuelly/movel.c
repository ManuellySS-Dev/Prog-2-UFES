#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "fila.h"
#include "movel.h"

struct Movel{
    char * nome;
};

tMovel *CriaMovel(char *nome){
    tMovel * movel = (tMovel*) calloc(1, sizeof(tMovel));
    movel->nome = (char*) calloc(100, sizeof(char));
    strcpy(movel->nome, nome);
    return movel;
}

void DestroiMovel(tMovel *m){
    free(m->nome);
    free(m);
}

tMovel *LeMovel(){
    char nome[100];
    scanf(" %[^\n]\n", nome);
    return CriaMovel(nome);
}

void ImprimeMovel(tMovel *m){
    printf("%s\n", m->nome);
}