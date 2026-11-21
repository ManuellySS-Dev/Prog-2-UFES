#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

struct Contato{
    char nome[101];
    unsigned long int telefone;
};

tContato *CriarContato(char *nome, unsigned long int telefone){
    tContato*cont = (tContato*) calloc(1, sizeof(tContato));
    strcpy(cont->nome, nome);
    cont->telefone = telefone;
    return cont;
}

void DestruirContato(tContato *contato){
    free(contato);
}

void ImprimirContato(tContato *contato){
    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %lu\n", contato->telefone);
}

void SalvarContato(tContato *contato, FILE *arquivo){
    fwrite(contato->nome, sizeof(char), 100, arquivo);
    fwrite(&contato->telefone, sizeof(unsigned long int), 1, arquivo);
}

tContato *LeContato(){
    char nome[101];
    unsigned long int telefone;
    scanf(" %[^\n]\n", nome);
    scanf("%lu", &telefone);
    return CriarContato(nome, telefone);
}

tContato *CarregarContato(FILE *arquivo){
    char nome[101];
    unsigned long int telefone;
    fread(nome, sizeof(char), 100, arquivo);
    nome[101] = '\0';
    fread(&telefone, sizeof(unsigned long int), 1, arquivo);
    return CriarContato(nome, telefone);
}

int ComparaTelefoneContato(tContato *c1, tContato *c2){
    if(c1->telefone == c2->telefone){
        return 1;
    }else{
        return 0;
    }
}

int ComparaNomeContato(tContato *c1, tContato *c2){
    if(!strcmp(c1->nome, c2->nome)){
        return 1;
    }else{
        return 0;
    }
}

unsigned long int GetTelefoneContato(tContato *contato){
    return contato->telefone;
}

char *GetNomeContato(tContato *contato){
    return contato->nome;
}