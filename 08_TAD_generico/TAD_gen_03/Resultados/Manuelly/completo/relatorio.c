#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

void ImprimeRelatorio(Vector *alunos){
    float nota=0, media=0, prct_aprovados=0, prct_masc=0, prct_fem=0, prct_outro=0;
    char genero= '\0';
    int tamanho =0;
    tamanho = VectorSize(alunos);

    for(int i=0; i<tamanho; i++){
        tAluno * aluno_i = (tAluno*) VectorGet(alunos, i) ;
        nota = GetNotaAluno(aluno_i);
        genero = GetGeneroAluno(aluno_i);

        media += nota;

        if(nota>=6){
            prct_aprovados++;
        }

        if(genero == 'M'){
            prct_masc++;
        }else if(genero == 'F'){
            prct_fem++;
        }else{
            prct_outro++;
        }
    }

    media = media/tamanho;
    prct_masc = (prct_masc * 100) /tamanho;
    prct_outro = (prct_outro * 100) /tamanho;
    prct_fem = (prct_fem * 100) /tamanho;
    prct_aprovados = (prct_aprovados * 100) /tamanho;

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", prct_aprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", prct_masc);
    printf("Feminino: %.2f%%\n", prct_fem);
    printf("Outro: %.2f%%\n", prct_outro);
}