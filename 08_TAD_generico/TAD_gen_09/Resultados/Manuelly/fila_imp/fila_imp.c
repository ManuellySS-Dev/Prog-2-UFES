#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "receita.h"
#include "documento.h"

struct _FilaImp{
    Documento ** documentos;
    int qtd_documentos;
    float preco_total;
};

FilaImp *criaFilaImp(){
    FilaImp * fila = (FilaImp*) calloc(1, sizeof(FilaImp));
    return fila;
}

void desalocaFilaImp(FilaImp *f){
    for(int i=0; i<f->qtd_documentos; i++){
        desalocaDocumento(f->documentos[i]);
    }
    free(f->documentos);
    free(f);
}

void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime, func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco){
    f->documentos = (Documento**) realloc(f->documentos,(f->qtd_documentos +1) * sizeof(Documento*));
    f->documentos[f->qtd_documentos] = criaDocumento(dado, imprime, desaloca, calculaPreco);
    f->qtd_documentos++;
}

int quantidadeDocumentosNaFilaImp(FilaImp *f){
    return f->qtd_documentos;
}

float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere){
    for(int i=0; i<f->qtd_documentos; i++){
        f->preco_total += calculaPrecoImpressaoDocumento(f->documentos[i], precoCaractere);
    }
    return f->preco_total;
}

void imprimeFilaImp(FilaImp *f){
    for(int i=0; i<f->qtd_documentos; i++){
        imprimeDocumento(f->documentos[i]);
    }
}