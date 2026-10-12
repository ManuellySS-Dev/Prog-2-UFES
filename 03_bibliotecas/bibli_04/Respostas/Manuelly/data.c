#include "data.h"
#include <stdio.h>
int verificaDataValida(int dia, int mes, int ano){
    if(dia > 31 || dia <1){
        return 0;
    }
    if(mes <1 || mes >12){
        return 0;
    }

    if(dia > numeroDiasMes(mes, ano)){
        return 0;
    }

    return 1;
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }else if(mes == 2){
        printf("Fevereiro");
    }else if(mes == 3){
        printf("Março");
    }else if(mes == 4){
        printf("Abril");
    }else if(mes == 5){
        printf("Maio");
    }else if(mes == 6){
        printf("Junho");
    }else if(mes == 7){
        printf("Julho");
    }else if(mes == 8){
        printf("Agosto");
    }else if(mes == 9){
        printf("Setembro");
    }else if(mes == 10){
        printf("Outubro");
    }else if(mes == 11){
        printf("Novembro");
    }else if(mes == 12){
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano){
    if(ano % 4 != 0){
        return 0;
    }
    if(ano % 100 == 0){
        if(ano % 400 != 0){
            return 0;
        }
    }
    return 1;
}

int numeroDiasMes(int mes, int ano){
    if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }else{
            return 28;
        }
    }

    if(mes == 1 || mes ==3 || mes == 5 || mes == 7 || mes == 8 || mes ==10 || mes == 12){
        return 31;
    }else{
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }else if(ano1 < ano2){
        return -1;
    }else if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        }else if(mes1 < mes2){
            return -1;
        }else if (mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            }else if( dia1 < dia2){
                return -1;
            }else if (dia1 == dia2){
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano){
    int i=0, dias_ate_mes=0;
    for(i=1; i<mes; i++){
        dias_ate_mes += numeroDiasMes(i, ano);
    }
    return dias_ate_mes;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int diferenca_de_dias=0, i=0;
    //acertar essa conta
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0){
        return 0;
    }
    if(ano1 == ano2){
        if(mes1 > mes2){
            diferenca_de_dias += calculaDiasAteMes(mes1, ano1) - calculaDiasAteMes (mes2, ano2);
            diferenca_de_dias -= dia2;
            diferenca_de_dias += dia1;
        }else if(mes1 < mes2){
            diferenca_de_dias += calculaDiasAteMes(mes2, ano2) - calculaDiasAteMes (mes1, ano1);
            diferenca_de_dias -= dia1;
            diferenca_de_dias += dia2;
        }else{
            if(dia1 > dia2){
                diferenca_de_dias += dia1 - dia2;
            }else{
                diferenca_de_dias += dia2 - dia1;
            }
        }
    }else{
        if(ano1 < ano2){
            for(i=0; i<(ano2-ano1); i++){
                if(verificaBissexto(ano1+i)){
                    diferenca_de_dias += 366;
                }else{
                    diferenca_de_dias += 365;
                }
            }
        }else if(ano1>ano2){
            for(i=0; i<(ano1-ano2); i++){
                if(verificaBissexto(ano2+i)){
                    diferenca_de_dias += 366;
                }else{
                    diferenca_de_dias += 365;
                }
            }
        }
        if(mes1 > mes2){
            diferenca_de_dias += calculaDiasAteMes(mes1, ano1) - calculaDiasAteMes (mes2, ano2);
            diferenca_de_dias -= dia2;
            diferenca_de_dias += dia1;
        }else if(mes1 < mes2){
            diferenca_de_dias += calculaDiasAteMes(mes2, ano2) - calculaDiasAteMes (mes1, ano1);
            diferenca_de_dias -= dia1;
            diferenca_de_dias += dia2;
        }

    }
    
    return diferenca_de_dias;
}

void imprimeProximaData(int dia, int mes, int ano){
    if(dia+1 > numeroDiasMes(mes,ano)){
        dia=1;
        mes = mes+1;
        if(mes > 12){
            mes = 1;
            ano = ano +1;
        }
    }else{
        dia = dia+1;
    }
    imprimeData( dia,  mes,  ano);
}
















