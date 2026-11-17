#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

struct Aluno{
    char genero;
    char * nome;
    float nota;
};

tAluno *CriaAluno(){
    tAluno * aluno = (tAluno*) calloc(1, sizeof(tAluno));
    aluno->nome = (char*) calloc(50, sizeof(char));
    aluno->genero = '\0';
    aluno->nota = 0;
    return aluno;
}

void DestroiAluno(data_type aluno){
    tAluno * alu = (tAluno*) aluno; //cast
    free(alu->nome);
    free(alu);
}

void LeAluno(tAluno *aluno){
    scanf(" %[^;];", aluno->nome);
    scanf("%c;", &aluno->genero);
    scanf("%f\n", &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}