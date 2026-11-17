#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "histograma.h"
#include "imagem.h"

int main(){
    Histograma * histograma;
    Imagem * img;
    int nIntervalos=0;
    
    scanf("%d\n",&nIntervalos);
    img = LerImagem();

    histograma = CalcularHistograma(img, nIntervalos);
    MostrarHistograma(histograma);

    DestruirHistograma(histograma);
    DestruirImagem(img);

    return 0;
}