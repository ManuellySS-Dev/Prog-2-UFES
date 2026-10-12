#include <stdio.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia= dia;
    data.mes = mes;
    data.ano= ano;
    return data;
}

int VerificaDataValida(tData data){
    if(data.dia > 31 || data.dia <1){
        return 0;
    }
    if(data.mes <1 || data.mes >12){
        return 0;
    }

    if(data.dia > NumeroDiasMes(data)){
        return 0;
    }

    return 1;
}

void ImprimeMesExtenso(tData data){
    if(data.mes == 1){
        printf("Janeiro");
    }else if(data.mes == 2){
        printf("Fevereiro");
    }else if(data.mes == 3){
        printf("Março");
    }else if(data.mes == 4){
        printf("Abril");
    }else if(data.mes == 5){
        printf("Maio");
    }else if(data.mes == 6){
        printf("Junho");
    }else if(data.mes == 7){
        printf("Julho");
    }else if(data.mes == 8){
        printf("Agosto");
    }else if(data.mes == 9){
        printf("Setembro");
    }else if(data.mes == 10){
        printf("Outubro");
    }else if(data.mes == 11){
        printf("Novembro");
    }else if(data.mes == 12){
        printf("Dezembro");
    }
}

void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

int VerificaBissexto(tData data){
    if(data.ano % 4 != 0){
        return 0;
    }
    if(data.ano % 100 == 0){
        if(data.ano % 400 != 0){
            return 0;
        }
    }
    return 1;
}

int NumeroDiasMes(tData data){
    if(data.mes == 2){
        if(VerificaBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }

    if(data.mes == 1 || data.mes ==3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes ==10 || data.mes == 12){
        return 31;
    }else{
        return 30;
    }
}

int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano){
        return 1;
    }else if(data1.ano < data2.ano){
        return -1;
    }else if(data1.ano == data2.ano){
        if(data1.mes > data2.mes){
            return 1;
        }else if(data1.mes < data2.mes){
            return -1;
        }else if (data1.mes == data2.mes){
            if(data1.dia > data2.dia){
                return 1;
            }else if(data1.dia <data2.dia){
                return -1;
            }else if (data1.dia == data2.dia){
                return 0;
            }
        }
    }
    return 0;
}

int CalculaDiasAteMes(tData data){
    int i=0, dias_ate_mes=0;
    tData aux = data;
    for(i=1; i<data.mes; i++){
        aux.mes = i; 
        dias_ate_mes += NumeroDiasMes(aux);
    }
    return dias_ate_mes;
}

int CalculaDiferencaDias(tData data1, tData data2){
    int diferenca_de_dias=0, i=0;
    //acertar essa conta
    if(ComparaData(data1, data2) == 0){
        return 0;
    }
    if(data1.ano == data2.ano){
        if(data1.mes > data2.mes){
            diferenca_de_dias += CalculaDiasAteMes(data1) - CalculaDiasAteMes (data2);
            diferenca_de_dias -= data2.dia;
            diferenca_de_dias += data1.dia;
        }else if(data1.mes < data2.mes){
            diferenca_de_dias += CalculaDiasAteMes(data2) - CalculaDiasAteMes (data1);
            diferenca_de_dias -= data1.dia;
            diferenca_de_dias += data2.dia;
        }else{
            if(data1.dia > data2.dia){
                diferenca_de_dias += data1.dia - data2.dia;
            }else{
                diferenca_de_dias += data2.dia - data1.dia;
            }
        }
    }else{
        if(data1.ano < data2.ano){
            for(i=0; i<(data2.ano-data1.ano); i++){
                tData ano_teste;
                ano_teste.ano = data1.ano + i; 
                if(VerificaBissexto(ano_teste)){
                    diferenca_de_dias += 366;
                }else{
                    diferenca_de_dias += 365;
                }
            }
        }else if(data1.ano>data2.ano){
            for(i=0; i<(data1.ano-data2.ano); i++){
                tData ano_teste;
                ano_teste.ano = data2.ano + i; 
                if(VerificaBissexto(ano_teste)){
                    diferenca_de_dias += 366;
                }else{
                    diferenca_de_dias += 365;
                }
            }
        }
        if(data1.mes > data2.mes){
            diferenca_de_dias += CalculaDiasAteMes(data1) - CalculaDiasAteMes (data2);
            diferenca_de_dias -= data2.dia;
            diferenca_de_dias += data1.dia;
        }else if(data1.mes < data2.mes){
            diferenca_de_dias += CalculaDiasAteMes(data2) - CalculaDiasAteMes (data1);
            diferenca_de_dias -= data1.dia;
            diferenca_de_dias += data2.dia;
        }

    }
    return diferenca_de_dias;
}

















