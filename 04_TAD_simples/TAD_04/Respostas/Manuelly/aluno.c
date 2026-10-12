#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno aluno;
    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;
    return aluno;
}

tAluno LeAluno(){
    tAluno aluno;
    scanf("%[^\n]\n", aluno.nome);
    scanf("%d\n%d %d %d\n", &aluno.matricula, &aluno.n1, &aluno.n2, &aluno.n3);
    aluno = CriaAluno(aluno.nome, aluno.matricula, aluno.n1, aluno.n2, aluno.n3);
    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if(aluno1.matricula > aluno2.matricula){
        return 1;
    }else if(aluno1.matricula == aluno2.matricula){
        return 0;
    }else if(aluno1.matricula < aluno2.matricula){
        return -1;
    }
}

int CalculaMediaAluno(tAluno aluno){
    return ((aluno.n1 + aluno.n2 + aluno.n3)/3);
}

int VerificaAprovacao(tAluno aluno){
    if(CalculaMediaAluno (aluno)>=7){
        return 1;
    }else{
        return 0;
    }
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}