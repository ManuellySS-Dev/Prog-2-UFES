#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtd_alunos=0, i=0, qtd_aprovados=0, j=0;
    scanf("%d\n", &qtd_alunos);
    tAluno alunos[qtd_alunos], aluno;
    for(i=0; i<qtd_alunos; i++){
        aluno = LeAluno();
        if(VerificaAprovacao(aluno) ==1){
            alunos[qtd_aprovados] = aluno;
            qtd_aprovados++;
        }
    }

    for(i=0; i<qtd_aprovados-1; i++){
        for(j=0; j<qtd_aprovados-i-1; j++){
            if(ComparaMatricula(alunos[j], alunos[j+1]) ==1){
                aluno = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aluno;
            }
        }
    }


    for(i=0; i<qtd_aprovados; i++){
        ImprimeAluno(alunos[i]);
    }
return 0;
}