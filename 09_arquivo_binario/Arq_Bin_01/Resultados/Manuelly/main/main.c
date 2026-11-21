#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aluno.h"

int main() {
    Aluno **vetor_alunos = NULL;
    int num_alunos = 0;
    printf("Digite o numero de alunos: ");
    scanf("%d", &num_alunos);

    vetor_alunos = CriaVetorAlunos(num_alunos);
    LeAlunos(vetor_alunos, num_alunos);

    SalvaAlunosBinario(vetor_alunos, "alunos.bin", num_alunos);

    LiberaAlunos(vetor_alunos, num_alunos);
    vetor_alunos = CriaVetorAlunos(num_alunos);

    CarregaAlunosBinario(vetor_alunos, "alunos.bin");
    ImprimeAlunos(vetor_alunos, num_alunos);
    LiberaAlunos(vetor_alunos, num_alunos);

    return 0;
}