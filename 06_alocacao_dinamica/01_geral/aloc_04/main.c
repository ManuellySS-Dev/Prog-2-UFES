#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"

int main(){
    char * ptrvetor;
    int tamanho=10;

    ptrvetor = CriaVetorTamPadrao();
    ptrvetor = LeVetor(ptrvetor, &tamanho);
    ImprimeString(ptrvetor);
    LiberaVetor(ptrvetor);
    return 0;
}