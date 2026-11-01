#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "missil.h"
#include "cidade.h"
#include "defesa.h"

#define MAX_MISSEIS 20
#define MAX_DEFESAS 20

struct cidade{
    float x,y, efetividade;
    tMissil * misseis;
    tDefesa * defesas;
    int qtd_misseis, qtd_defesas;
    float dano_sofrido;
    float dano_possivel;
};

tCidade CriaCidade(){
    tCidade cidade = (tCidade) calloc(1, sizeof(struct cidade));
    cidade->misseis = (tMissil*) calloc(MAX_MISSEIS, sizeof(tMissil));
    cidade->defesas = (tDefesa*) calloc(MAX_DEFESAS, sizeof(tDefesa));
    return cidade;
}

tCidade LeEntrada(tCidade cidade){
    char caracter = '\0';
    while(1){
        scanf(" %c", &caracter);
        if(caracter == 'M'){
            cidade->misseis[cidade->qtd_misseis] = LeMissil();
            cidade->dano_possivel += (GetMissilPoder(cidade->misseis[cidade->qtd_misseis]));
            cidade->qtd_misseis++;
        }else if(caracter == 'D'){
            cidade->defesas[cidade->qtd_defesas] = LeDefesa();
            cidade->qtd_defesas++;  
        }else if(caracter == 'F'){
            break;
        }
    }
    return cidade;
}

void LiberaCidade(tCidade cidade){
    int i=0;
    for(i=0; i<cidade->qtd_misseis; i++){
        LiberaMissil(cidade->misseis[i]);
    }
    free(cidade->misseis);

    for(i=0; i<cidade->qtd_defesas; i++){
        LiberaDefesa(cidade->defesas[i]);
    }
    free(cidade->defesas);

    free(cidade);
}

void ProcessaAtaques(tCidade cidade){
    int i=0, j=0;

    for(i=0; i<cidade->qtd_misseis; i++){
        for(j=0; j<cidade->qtd_defesas; j++){
            if(VerificaSeDentroArea(cidade->defesas[j], GetMissilX(cidade->misseis[i]), GetMissilY(cidade->misseis[i]))){
                if(PodeDefender(cidade->defesas[j])){
                    UsaDefesa(cidade->defesas[j]);
                    ReduzPoder(cidade->misseis[i], GetDefesaPoder(cidade->defesas[j]));
                }
            }
        }
        cidade->dano_sofrido += GetMissilPoder(cidade->misseis[i]);
    }
}

void ImprimeDados(tCidade cidade){
    int i=0;
    float dano_possivel=0;

    for(i=0; i<cidade->qtd_defesas; i++){
        ImprimeDefesa(cidade->defesas[i]);
    }

    for(i=0; i<cidade->qtd_misseis; i++){
        ImprimeMissil(cidade->misseis[i]);
    }
    cidade->efetividade = (cidade->dano_possivel - cidade->dano_sofrido)*100/cidade->dano_possivel;
    printf("Efetividade: %.2f%%\n", cidade->efetividade);
}