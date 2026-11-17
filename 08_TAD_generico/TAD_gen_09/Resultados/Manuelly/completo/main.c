#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "documento.h"
#include "receita.h"
#include "encaminhamento.h"
#include "exame.h"

int main(){
    FilaImp * fila;
    fila = criaFilaImp();
    char operacao[50];
    float preco_carac=0;

    scanf("%f\n", &preco_carac);

    while(1){
        
        scanf(" %[^\n]\n", operacao);

        if(!strcmp(operacao, "FIM")){
            break;
        }else if(!strcmp(operacao, "RECEITA")){
            insereDocumentoFilaImp(fila, leReceita(), imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        }else if(!strcmp(operacao, "EXAME")){
            insereDocumentoFilaImp(fila, leExame(), imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }else if(!strcmp(operacao, "ENCAMINHAMENTO")){
            insereDocumentoFilaImp(fila, leEncaminhamento(), imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        }else if(!strcmp(operacao, "IMPRIME")){
            imprimeFilaImp(fila);
        }else if(!strcmp(operacao, "QUANTIDADE")){
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(fila));
        }else if(!strcmp(operacao, "PRECO")){
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(fila, preco_carac));
        }
    }

    desalocaFilaImp(fila);
}