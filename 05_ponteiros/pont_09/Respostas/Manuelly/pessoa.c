#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
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
            printf("%s\n\n", pessoa->mae->nome);
        } else {
            printf("NAO INFORMADO\n\n");
        }
    }

}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int i_mae=0, i_pai=0, i_filho=0, qtd_ass=0, i=0;;
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
}