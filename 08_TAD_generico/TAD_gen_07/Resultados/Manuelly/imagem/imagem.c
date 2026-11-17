#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "histograma.h"
#include "imagem.h"

struct tImagem{
    int altura, largura;
    Tipo tipo;
    void ** matriz;
};

int ObterAltura(Imagem *img){
    return img->altura;
}

int ObterLargura(Imagem *img){
    return img->largura;
}

Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

void *ObterDadosImagem(Imagem *img){
    return img->matriz;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo){
    Imagem * img = (Imagem*) calloc(1, sizeof(Imagem));
    if(tipo == INT){
        img->matriz = (void*) calloc(altura*largura, sizeof(int));
    }else{
        img->matriz = (void*) calloc(altura*largura, sizeof(float));
    }

    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;

    for(int i=0; i<altura*largura; i++){
        if(img->tipo == INT){
            int * matriz_int = (int*) img->matriz;
            scanf("%d ", &matriz_int[i]);
        }else{
            float * matriz_float = (float*) img->matriz;
            scanf("%f ", &matriz_float[i]);
        }
    }
    return img;
}

Imagem *LerImagem(){
    int altura, largura, tipo;

    scanf("%d %d %d\n", &altura, &largura, &tipo);
 
    return CriarImagem(altura, largura, tipo);
}

void ImprimirImagem(Imagem *img){
    //nao precisei pra nada po
}

void DestruirImagem(Imagem *img){
    free(img->matriz);
    free(img);
}