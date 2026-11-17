/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

struct matrizgenerica{
    int linhas, colunas, numByteElem;
    void ** matriz;
};

tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem){
    tMatrizGenerica * mat = (tMatrizGenerica*) calloc(1 ,sizeof(tMatrizGenerica));
    mat->matriz = (void**) calloc(linhas, sizeof(void*));

    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->numByteElem = numByteElem;

    for(int i=0; i<mat->linhas; i++){
        //as colunas nao sao ponteiro void* esses sao posicoes nas linhas e as colunas sao elementos normais dentro dessas posicoes
        //linha = vetor
        //esse calloc = posicoes no vetor
        //colunas sao variaveis de tamanho numByte dentro do vetor
        //por isso na hora de liberar soh se libera as linhas posicao por posicao 
        //e depois se libera a matriz que tem o vetor linhas**
        mat->matriz[i] =  (void*) calloc(mat->colunas, mat->numByteElem);
    }
    return mat;
}


void DestroiMatrizGenerica(tMatrizGenerica * mat){
    for(int i=0; i<mat->linhas; i++){ //se libera as linhas
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    free(mat);
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat){
    return mat->linhas;
}


int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat){
    return mat->colunas;
}

void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna){
    return mat->matriz[linha][coluna];
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    mat->matriz[(linha*coluna) + coluna] = elem;
}

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))){
    for(int i=0; i<mat->linhas; i++){
        for(int j=0; j<mat->colunas; j++){
            imprime_elemento(mat->matriz[(i*j) + j]);
        }
        printf("\n");
    }
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat){
    tMatrizGenerica * transposta;
    transposta = CriaMatrizGenerica(mat->colunas, mat->linhas,mat->numByteElem);
    for(int i=0; i<transposta->linhas; i++){
        for(int j=0; j<transposta->colunas; j++){
            transposta->matriz[(i*j) + j] = mat->matriz[(i*j) + i];
        }
    }
    return transposta;
}

tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)){
    tMatrizGenerica * multipla;
    multipla = CriaMatrizGenerica(mat1->colunas, mat1->linhas, numByteTarget);
    for(int i=0; i<mat1->linhas; i++){
        for(int j=0; j<mat1->colunas; j++){
            multipla->matriz[(i*j) + j] = multi_elem (mat1->matriz[(i*j) + j], mat2->matriz[(i*j) + j]);
        }
    }
    return multipla;
}

tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)){
    tMatrizGenerica * tipo_novo;
    tipo_novo = CriaMatrizGenerica(mat2->colunas, mat2->linhas, novoNumByteElem);
    for(int i=0; i<mat2->linhas; i++){
        for(int j=0; j<mat2->colunas; j++){
            tipo_novo->matriz[(i*j) + j] = converte_elem (mat2->matriz[(i*j) + j]);
        }
    }
    return tipo_novo;
}*/
//TA DANDO TUDO ERRADO NESSA PORRA DE MATRZ EU NAO SEI FAZER ESSE CARALHO