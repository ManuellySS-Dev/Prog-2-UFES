#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

Data *criaData(int dia, int mes, int ano){
    Data * data = (Data*) calloc(1, sizeof(Data));
    if(data == NULL){
        printf("Nao foi possivel alocar memoria para data\n");
        exit(0);
    }
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

Data *lerData(){
    int dia=0, mes=0, ano=0;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    return criaData(dia,mes,ano);;
}

int diferencaAnoData(Data *inicial, Data *atual){
    int diferenca_anos=0;

    diferenca_anos = atual->ano - inicial->ano;
    if(atual->mes < inicial->mes){
        diferenca_anos--;
    }else if(atual->mes == inicial->mes){
        if(atual->dia < inicial->dia){
            diferenca_anos--;
        }
    }

    return diferenca_anos;
}

void imprimeData(Data *d){
    printf("%02d/%02d/%d\n", d->dia, d->mes, d->ano);
}

void liberaData(Data *d){
    free(d);
}