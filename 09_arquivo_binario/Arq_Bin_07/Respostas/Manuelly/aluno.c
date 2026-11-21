#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

struct Aluno{
    char nome[52];
    char dataNascimento[11];
    char curso[52];
    float prctConclusao;
    float cfRendimento;
};

tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento){
    tAluno * aluno = (tAluno*) calloc(1, sizeof(tAluno));
    aluno->cfRendimento = cfRendimento;
    aluno->prctConclusao = prctConclusao;
    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);
    return aluno;
}

void DestroiAluno(tAluno *aluno){
    free(aluno);
}

tAluno *LeAluno(){
    float p, c;
    char nome[52], data[11], curso[52];
    scanf(" %[^\n]\n", nome);
    scanf(" %[^\n]\n", data);
    scanf(" %[^\n]\n", curso);
    scanf(" %f", &p);
    scanf(" %f", &c);
    return CriaAluno(nome, data, curso, p, c);
}

int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2){
    return strcmp(aluno1->nome, aluno2->nome);
}

int SalvaAluno(tAluno *aluno, FILE *file){ //tah voltando errado a quantidade de bytes
    int n_bytes=0;
    n_bytes += fwrite(aluno->nome, sizeof(char), 51, file);
    n_bytes += fwrite(aluno->dataNascimento, sizeof(char), 10, file);
    n_bytes += fwrite(aluno->curso, sizeof(char), 51, file);
    n_bytes += fwrite(&aluno->prctConclusao, sizeof(float), 1, file);
    n_bytes += fwrite(&aluno->cfRendimento, sizeof(float), 1, file);
    return n_bytes;
}

int CarregaAluno(tAluno *aluno, FILE *file){
    int n_bytes=0;
    n_bytes += fread(aluno->nome, sizeof(char), 51, file);
    aluno->nome[52] = '\0';
    n_bytes += fread(aluno->dataNascimento, sizeof(char), 10, file);
    aluno->dataNascimento[11] = '\0';    
    n_bytes += fread(aluno->curso, sizeof(char), 51, file);
    aluno->curso[52] = '\0';   
    n_bytes += fread(&aluno->prctConclusao, sizeof(float), 1, file);
    n_bytes += fread(&aluno->cfRendimento, sizeof(float), 1, file);
    return n_bytes;
}

void ImprimeNomeAluno(tAluno *aluno){
    printf("%s\n", aluno->nome);
}