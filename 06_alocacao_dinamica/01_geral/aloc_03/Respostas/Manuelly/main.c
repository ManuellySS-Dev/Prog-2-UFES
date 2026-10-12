#include "utils_char.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//main
int main(){
    char * vetor;
    int tamanho =0;

    scanf("%d\n", &tamanho);

    vetor = CriaVetor(tamanho);
    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);
    return 0;
}