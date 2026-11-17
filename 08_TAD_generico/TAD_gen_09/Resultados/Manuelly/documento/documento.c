#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "receita.h"
#include "documento.h"

struct _Documento{
    void * dado;
    void (*func_ptr_imprime)(void *dado);
    float (*func_ptr_calculaPreco)(void *dado, float precoCaractere);
    void (*func_ptr_desaloca)(void *dado);
    float preco_caractere;
};

Documento *criaDocumento(void *dado, func_ptr_imprime imprimeDado, func_ptr_desaloca desalocaDado, func_ptr_calculaPreco calculaPrecoDado){
    Documento * documento = (Documento*) calloc(1, sizeof(Documento));
    documento->dado = dado;
    documento->func_ptr_calculaPreco = calculaPrecoDado;
    documento->func_ptr_desaloca = desalocaDado;
    documento->func_ptr_imprime = imprimeDado;
    return documento;
}

void imprimeDocumento(Documento *doc){
    doc->func_ptr_imprime(doc->dado);
}

float calculaPrecoImpressaoDocumento(Documento *doc, float precoCaractere){
    return doc->func_ptr_calculaPreco(doc->dado, precoCaractere);
}

void desalocaDocumento(Documento *doc){
    doc->func_ptr_desaloca(doc->dado);
    free(doc);
}