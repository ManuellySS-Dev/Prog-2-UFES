#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    tAluno * alunos[100];
    tAluno * aux;
    int i=0, qtd_alunos=0, j=0;
    scanf("%d", &qtd_alunos);
    CriaAluno(aux);
    
    for(i=0; i<qtd_alunos; i++){
        alunos[i] = CriaAluno;
        LeAluno(alunos[i]);
    }

    for(i=0; i<qtd_alunos; i++){
        for(j=0; j<qtd_alunos; j++){
            if(ComparaMatricula(alunos[j], alunos[j+1])){
                aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }

    for(i=0; i<qtd_alunos; i++){
        ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }
    ApagaAluno(aux);
    return 0;
}