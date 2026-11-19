#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

int main(){
    Imagem * img;
    char caminho[100];
    scanf(" %[^\n]\n", caminho);
    img = LerImagem(caminho);
    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(img));
    ImprimirImagem(img);
    DestruirImagem(img);
    return 0;
}