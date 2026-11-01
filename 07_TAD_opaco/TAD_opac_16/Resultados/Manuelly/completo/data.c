#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sistema.h"

struct Data{
    int dia_semana;
    int dia, mes, ano;
    int hora, minuto;
};

enum DiasDaSemana {
    Domingo,    // Valor 0
    Segunda,    // Valor 1
    Terca,      // Valor 2
    Quarta,     // Valor 3
    Quinta,     // Valor 4
    Sexta,      // Valor 5
    Sabado      // Valor 6
};

tData* CriaData(){
    tData * data = (tData*) calloc(1, sizeof(tData));
    return data;
}

void DestroiData(tData* data){
    free(data);
}

void ProcessaDiaMesAno(tData* data, char* str){
    sscanf(str, " %d/%d/%d", &data->dia, &data->mes, &data->ano); //sscanf le de uma string ao inves do buffer
}

void ProcessaDiaDaSemana(tData* data, char* str){
    sscanf(str, " %d", &data->dia_semana); //sscanf le de uma string ao inves do buffer
}

void ProcessaHorario(tData* data, char* str){
    sscanf(str, " %d:%d", &data->hora, &data->minuto);
}

int VerificaDataValida(tData* data){
    if(VerificaBissexto(data)){
        if(data->mes == 2){
            if(data->dia >=1 && data->dia <=29){
                return 1;
            }else{
                return 0;
            }
        }
    }else{
        if(data->mes == 2){
            if(data->dia >=1 && data->dia <=28){
                return 1;
            }else{
                return 0;
            }
        }  
    }
    if(data->mes == 4 || data->mes ==6 ||data->mes ==9 || data->mes ==11){
        if(data->dia >=1 && data->dia<=30){
            return 1;
        }else{
            return 0;
        }
    }else if(data->mes == 1 || data->mes ==3 ||data->mes ==5 || data->mes ==7|| data->mes ==8 || data->mes ==12 || data->mes ==10){
        if(data->dia >=1 && data->dia<=31){
            return 1;
        }else{
            return 0;
        }  
    }
    return 0;
}

int VerificaBissexto(tData* data){
    if(data->ano % 4 == 0){
        if(data->ano % 100 == 0){
            if(data->ano % 400 ==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

int NumeroDiasMes(tData* data){
    if(VerificaBissexto(data)){
        if(data->mes == 2){
            return 29;
        }
    }else{
        if(data->mes == 2){
            return 28;
        }  
    }
    if(data->mes == 4 || data->mes ==6 ||data->mes ==9 || data->mes ==11){
        return 30;
    }else if(data->mes == 1 || data->mes ==3 ||data->mes ==5 || data->mes ==7|| data->mes ==8 || data->mes ==12 || data->mes == 10){
        return 31;
    }
    return 0;
}

int ComparaDiaMesAno(tData* data1, tData* data2){
    if(data1->ano>data2->ano){
        return 1;
    }else if(data1->ano<data2->ano){
        return -1;
    }else if(data1->ano == data2->ano){
        if(data1->mes > data2->mes){
            return 1;
        }else if(data1->mes < data2->mes){
            return -1;
        }else if(data1->mes == data2->mes){
            if(data1->dia > data2->dia){
                return 1;
            }else if(data1->dia < data2->dia){
                return -1;
            }else if(data1->dia == data2->dia){
                return 0;
            }
        }
    }
    return 0;
}

int CalculaDiasAteMes(tData* data){
    int dias_ateh=0;
    tData * data_aux;
    data_aux = CriaData();
    data_aux->mes =1 ;
    while(data_aux->mes < data->mes){
        dias_ateh += NumeroDiasMes(data_aux);
        data_aux->mes++;
    }
    free(data_aux);
    return dias_ateh;
}

int CalculaDiferencaDias(tData* data1, tData* data2){
    int diferenca_dias=0;
    tData * data_aux;
    data_aux = CriaData();

    if(ComparaDiaMesAno(data1, data2) == 0){
        DestroiData(data_aux);
        return 0;
    }if(ComparaDiaMesAno(data1, data2) == 1){
        data_aux->dia = data2->dia;
        data_aux->mes = data2->mes;
        data_aux->ano = data2->ano;
        while(data_aux->dia!= data1->dia && data_aux->mes != data1->mes && data_aux->ano!= data1->ano){
            if(data_aux->dia < NumeroDiasMes(data_aux)){
                data_aux->dia++;
            }else{
                if(data_aux->mes <12){
                    data_aux->dia =1;
                    data_aux->mes++;
                }else{
                    data_aux->ano++;
                    data_aux->dia =1;
                    data_aux->mes =1;
                }
            }
            diferenca_dias++;
        }
    }else{
        data_aux->dia = data1->dia;
        data_aux->mes = data1->mes;
        data_aux->ano = data1->ano;
        while(data_aux->dia!= data2->dia || data_aux->mes != data2->mes || data_aux->ano!= data2->ano){
            if(data_aux->dia < NumeroDiasMes(data_aux)){
                data_aux->dia++;
            }else{
                if(data_aux->mes <12){
                    data_aux->dia =1;
                    data_aux->mes++;
                }else{
                    data_aux->ano++;
                    data_aux->dia =1;
                    data_aux->mes =1;
                }
            }
            //ImprimeDataExtenso(data_aux);
            diferenca_dias++;
        }
    }

    DestroiData(data_aux);
    return diferenca_dias;
}

float CalculaHorasEntreDatas(tData* data1, tData* data2){
    int diferenca_minutos=0, controle=0;
    tData * aux;
    aux = CriaData();
    aux->hora = data1->hora;
    aux->minuto = data1->minuto;
    CopiaDiaMesAno(data1, aux);
    while(aux->dia != data2->dia || aux->mes != data2->mes || aux->ano != data2->ano || aux->hora != data2->hora || aux->minuto != data2->minuto){
        if(aux->minuto <59){
            diferenca_minutos++;
            aux->minuto++;
        }else{
            diferenca_minutos++;
            aux->minuto=0;
            if(aux->hora <23){
                aux->hora++;
            }else{
                DataDiaSeguinte(aux);
                aux->hora=0;
            }
        }
    }
    DestroiData(aux);
    return (diferenca_minutos/60.0);
}

int DataEhSabadoOuDomingo(tData* data){
    if(data->dia_semana == Domingo || data->dia_semana == Sabado){
        return 1;
    }
    return 0;
}

void DataDiaSeguinte(tData* data){
    if(data->dia_semana < 6){
        data->dia_semana++;
    }else{
        data->dia_semana = 0;
    }

    if(data->dia <NumeroDiasMes(data)){
        data->dia++;
    }else{
        data->dia = 1;
        if(data->mes < 12){
            data->mes++;
        }else{
            data->mes = 1;
            data->ano++;
        }
    }
}

void CopiaDiaMesAno(tData* src, tData* tgt){
    tgt->dia = src->dia;
    tgt->dia_semana = src->dia_semana;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
}
