#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_NOME 50
struct Aluno
{
    int matricula, n1, n2, n3;
    char *nome;
};

tAluno *CriaAluno()
{
    tAluno *aluno = (tAluno *)calloc(1, sizeof(tAluno));
    aluno->nome = (char *)calloc(MAX_NOME, sizeof(char));
    return aluno;
}

void ApagaAluno(tAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno)
{
    scanf(" %[^\n]\n", aluno->nome);
    scanf(" %d", &aluno->matricula);
    scanf(" %d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno *aluno1, tAluno *aluno2)
{
    if (aluno1->matricula > aluno2->matricula)
    {
        return 1;
    }
    else if (aluno1->matricula < aluno2->matricula)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int CalculaMediaAluno(tAluno *aluno)
{
    return ((aluno->n1 + aluno->n2 + aluno->n3) / 3);
}

int VerificaAprovacao(tAluno *aluno)
{
    if (CalculaMediaAluno(aluno) >= 7)
    {
        return 1;
    }
    return 0;
}

void ImprimeAluno(tAluno *aluno)
{
    printf("%s\n", aluno->nome);
}