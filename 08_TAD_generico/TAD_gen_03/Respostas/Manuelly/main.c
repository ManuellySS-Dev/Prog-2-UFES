#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

void DestroiElementosVetor(data_type elemento){
    tAluno * aluno = (tAluno*) elemento;
    DestroiAluno(aluno);
}

int main(){
    Vector * vetor;

    int qtd_alunos=0;

    scanf("%d\n", &qtd_alunos);

    vetor = VectorConstruct();

    for(int i=0; i<qtd_alunos; i++){
        tAluno * aluno;
        aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, aluno);
    }
    
    ImprimeRelatorio(vetor);
    VectorDestroy(vetor, DestroiAluno);


    return 0;
}