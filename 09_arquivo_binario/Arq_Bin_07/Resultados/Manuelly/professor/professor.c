#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "professor.h"

struct Professor{
    char nome[52];
    char dataNascimento[11];
    char departamento[52];
};

tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento){
    tProfessor * prof = (tProfessor*) calloc(1, sizeof(tProfessor));
    
    strcpy(prof->nome, nome);
    strcpy(prof->dataNascimento, dataNascimento);
    strcpy(prof->departamento, departamento);

    return prof;
}

void DestroiProfessor(tProfessor *prof){
    free(prof);
}

tProfessor *LeProfessor(){
    char nome[52];
    char dataNascimento[11];
    char departamento[52];

    scanf(" %[^\n]\n", nome);
    scanf(" %[^\n]\n", dataNascimento);
    scanf(" %[^\n]\n", departamento);

    return CriaProfessor(nome, dataNascimento, departamento);
}

int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2){
    return strcmp(prof1->nome, prof2->nome);
}

int SalvaProfessor(tProfessor *prof, FILE *file){
    int n_bytes=0;
    n_bytes += fwrite(prof->nome, sizeof(char), 51, file);
    n_bytes += fwrite(prof->dataNascimento, sizeof(char), 10, file);
    n_bytes += fwrite(prof->departamento, sizeof(char), 51, file);
     return n_bytes;
}

int CarregaProfessor(tProfessor *prof, FILE *file){
    int n_bytes=0;
    n_bytes += fread(prof->nome, sizeof(char), 51, file);
    prof->nome[51] = '\0';
    n_bytes += fread(prof->dataNascimento, sizeof(char), 10, file);
    prof->dataNascimento[10] = '\0';
    n_bytes += fread(prof->departamento, sizeof(char), 51, file);
    prof->departamento[51] = '\0';
    return n_bytes;
}

void ImprimeNomeProfessor(tProfessor *prof){
    printf("%s\n", prof->nome);
}