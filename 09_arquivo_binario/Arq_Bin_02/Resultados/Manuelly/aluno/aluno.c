#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno{
    char nome[100];
    char dataNascimento[100];
    char curso[100];
    int periodo;
    float cr;
};

tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno * aluno = (tAluno*) calloc(1, sizeof(tAluno));
    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);
    aluno->periodo = periodo;
    aluno->cr = coeficienteRendimento;
    return aluno;
}

void DestruirAluno(tAluno* aluno){
    free(aluno);
}

tAluno *LeAluno(FILE *arquivo_binario){
    int tamanho_palavras = 0;

    char nome[101];
    fread(nome, sizeof(char), 100, arquivo_binario);
    nome[101] = '\0';

    char dataNascimento[12];
    fread(dataNascimento, sizeof(char), 11, arquivo_binario);
    dataNascimento[12] = '\0';

    char curso[51];
    fread(curso, sizeof(char), 50, arquivo_binario);
    curso[51] = '\0';

    int periodo;
    fread(&periodo, sizeof(int), 1, arquivo_binario);

    float cr;
    fread(&cr, sizeof(float), 1, arquivo_binario);

    return CriarAluno(nome, dataNascimento, curso, periodo, cr);
}

float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->cr;
}