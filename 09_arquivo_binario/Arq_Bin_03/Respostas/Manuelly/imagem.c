#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

struct tImagem{
    void ** matriz_imagem;
    int n_colunas, n_linhas;
    int tipo;
    int n_bytes;
};

Imagem *LerImagem(const char *caminho){
    Imagem * img = (Imagem*) calloc(1, sizeof(Imagem));
    img->matriz_imagem = NULL;

    FILE * arquivo_imagem = fopen(caminho, "rb");

    img->n_bytes += fread(&img->n_linhas, sizeof(int), 1, arquivo_imagem);
    img->n_bytes += fread(&img->n_colunas, sizeof(int), 1, arquivo_imagem);
    img->n_bytes += fread(&img->tipo, sizeof(int), 1, arquivo_imagem);

    if (img->tipo == INT) {
        int **matriz_int = calloc(img->n_linhas, sizeof(int *));
        for (int i = 0; i < img->n_linhas; i++) {
            matriz_int[i] = calloc(img->n_colunas, sizeof(int));
            img->n_bytes += fread(matriz_int[i], sizeof(int), img->n_colunas, arquivo_imagem);        
        }
        img->matriz_imagem = (void **)matriz_int;
    } else {
        float **matriz_float = calloc(img->n_linhas, sizeof(float *));
        for (int i = 0; i < img->n_linhas; i++) {
            matriz_float[i] = calloc(img->n_colunas, sizeof(float));
            img->n_bytes += fread(matriz_float[i], sizeof(float), img->n_colunas, arquivo_imagem);        
        }
        img->matriz_imagem = (void **)matriz_float;
    }

    fclose(arquivo_imagem);
    return img;
}

void DestruirImagem(Imagem *img){
    for (int i = 0; i < img->n_linhas; i++) {
        free(img->matriz_imagem[i]);
    }
    free(img->matriz_imagem);
    free(img);
}

int ObterNumeroBytesLidos(Imagem *img){
    return img->n_bytes;
}

void ImprimirImagem(Imagem *img){
    for(int i=0; i<img->n_linhas; i++){
        for(int j=0; j<img->n_colunas; j++){
            if(img->tipo == INT){
                int ** matriz_int = (int**) img->matriz_imagem;
                printf("%d ", matriz_int[i][j]);
            }else{
                float ** matriz_float = (float**) img->matriz_imagem;
                printf("%.2f ", matriz_float[i][j]);
            }
        }
            printf("\n");
    }
}
