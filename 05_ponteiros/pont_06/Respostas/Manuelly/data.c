#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    //tratando datas invalidas
    if(InformaQtdDiasNoMes(data) < dia){
        data->dia = InformaQtdDiasNoMes(data);
    }
    if(data->dia <1){
        data->dia =1;
    }
    if(data->mes >12){
        data->mes =12;
    }
    if(data->mes <1){
        data->mes =1;
    }
}

void LeData( tData *data ){
    int dia=0, mes=0, ano=0;
    scanf("%d %d %d\n", &dia, &mes, &ano);
    InicializaDataParam(dia,mes,ano, data);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if(data->ano %100 ==0){
        if(data->ano %400 ==0){
            return 1;
        }
    }
    if(data->ano %4 ==0){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 2){
        if(EhBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }
    if(data->mes == 4 || data->mes ==6|| data->mes ==9 ||data ->mes == 11){
        return 30;
    }else{
        return 31;
    }
    return 0;
}

void AvancaParaDiaSeguinte( tData *data ){
    data->dia++;
    if(data->dia > InformaQtdDiasNoMes(data)){
        data->dia = 1;
        data->mes++;
        if(data->mes >12){
            data->mes =1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if(data1->dia == data2->dia){
        if(data1->mes == data2->mes){
            if(data1->ano == data2->ano){
                return 1;
            }
        }
    }
    return 0;
}