#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

struct tImagem{
    void ** matriz_imagem;
    int n_colunas, n_linhas;
    int tipo;
};

/*Imagem *LerImagem(const char *caminho){
    Imagem * img = (Imagem*) calloc(1, sizeof(Imagem));
    FILE * arquivo_imagem = fopen(caminho, "rb");
    fread(&img->n_linhas, sizeof(int), 1, arquivo_imagem);

    fread(&img->n_colunas, sizeof(int), 1, arquivo_imagem);
    fread(&img->tipo, sizeof(int), 1, arquivo_imagem);
    if(img->tipo == 0){
        float * matriz =img->matriz_imagem;
    }

    return img;
}

void DestruirImagem(Imagem *img){

    free(img);
}

int ObterNumeroBytesLidos(Imagem *img){

}

void ImprimirImagem(Imagem *img){
    for(int i=0; i<img->n_linhas; i++){
        for(int j=0; j<img->n_colunas; j++){
            if(img->tipo == 0){
                int ** matriz_int = (int**) img->matriz_imagem;
                printf("%d ", matriz_int[i][j]);
            }else{
                float ** matriz_float = (float**) img->matriz_imagem;
                printf("%f ", matriz_float[i][j]);
            }
            printf("\n");
        }
    }
}*/
