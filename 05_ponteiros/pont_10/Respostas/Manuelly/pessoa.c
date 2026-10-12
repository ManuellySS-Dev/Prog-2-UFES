#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    char nome[100];
    *pessoa = CriaPessoa();
    scanf(" %[^\n]", nome);
    strcpy(pessoa->nome, nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL|| pessoa->mae != NULL){
        return 1;
    }else{
        return 0;
    }
}

void ImprimePessoa(tPessoa *pessoa){

if (VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        printf("PAI: ");
        if (pessoa->pai != NULL) {
            printf("%s\n", pessoa->pai->nome);
        } else {
            printf("NAO INFORMADO\n");
        }

        printf("MAE: ");
        if (pessoa->mae != NULL) {
            printf("%s\n", pessoa->mae->nome);
        } else {
            printf("NAO INFORMADO\n");
        }

        printf("IRMAO: ");
        if (pessoa->irmao != NULL) {
            printf("%s\n\n", pessoa->irmao->nome);
        } else {
            printf("NAO INFORMADO\n\n");
        }
    }

}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai){
        return 1;
    }else{
        return 0;
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int i_mae=0, i_pai=0, i_filho=0, qtd_ass=0, i=0, j=0;
    scanf(" %d", &qtd_ass);

    for(i=0; i<qtd_ass; i++){
        scanf(" mae: %d, pai: %d, filho: %d", &i_mae, &i_pai, &i_filho);
        
        if(i_mae != -1){
            pessoas[i_filho].mae = &pessoas[i_mae];
        }
        if(i_pai != -1){
            pessoas[i_filho].pai = &pessoas[i_pai];
        }
    }
    for(i=0; i<numPessoas; i++){
        for(j=0; j<numPessoas; j++){
            if(i!=j){
                if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])){
                    pessoas[i].irmao = &pessoas[j];
                }
            }
        }
    }
}