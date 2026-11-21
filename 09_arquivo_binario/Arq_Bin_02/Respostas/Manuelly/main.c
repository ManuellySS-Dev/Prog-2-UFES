#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "base_alunos.h"

int main(){
    char caminho_arq[50];
    tBaseAlunos * base;
    scanf("%[^\n]\n", caminho_arq);
    base = CriarBaseAlunos();
    LerBaseAlunos(base,caminho_arq );
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));
    DestruirBaseAlunos(base);
    return 0;
}