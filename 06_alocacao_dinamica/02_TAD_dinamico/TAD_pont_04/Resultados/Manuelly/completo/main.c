#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    int qtd_alunos=0, i=0, j=0;

    scanf("%d", &qtd_alunos);

    tAluno * alunos[qtd_alunos];
    tAluno *aux;

    for(i=0; i<qtd_alunos; i++){
        tAluno * aluno;
        aluno = CriaAluno();
        LeAluno(aluno);
        alunos[i] = aluno;
    }
    //ordena alunos
    for(i=0; i<qtd_alunos-1; i++){
        for(j=0; j<qtd_alunos-1-i; j++){
            if(ComparaMatricula(alunos[j], alunos[j+1]) >0){
                aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }
    //imprime alunos e apaga depois
    for(i=0; i<qtd_alunos; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }
    return 0;
}