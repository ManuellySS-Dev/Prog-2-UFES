#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

tData* CriaData(){
    tData * data = (tData*) calloc(1, sizeof(tData));
    return data;
}

void LeData(tData* data){
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

void LiberaData(tData* data){
    free(data);
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

void ImprimeDataExtenso(tData* data){
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

void ImprimeMesExtenso(tData* data){
    if(data->mes ==1){
        printf("Janeiro");
    }else if(data->mes ==1){
        printf("Janeiro");
    }else if(data->mes ==2){
        printf("Fevereiro");
    }else if(data->mes ==3){
        printf("Marco");
    }else if(data->mes ==4){
        printf("Abril");        
    }else if(data->mes ==5){
        printf("Maio");        
    }else if(data->mes ==6){
        printf("Junho");        
    }else if(data->mes ==7){
        printf("Julho");        
    }else if(data->mes ==8){
        printf("Agosto");        
    }else if(data->mes ==9){
        printf("Setembro");        
    }else if(data->mes ==10){
        printf("Outubro");        
    }else if(data->mes ==11){
        printf("Novembro");        
    }else if(data->mes ==12){
        printf("Dezembro");        
    }
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

int ComparaData(tData* data1, tData* data2){
    if(data1->ano > data2->ano){
        return 1;
    }else if(data1->ano < data2->ano){
        return -1;
    }else if(data1->ano == data2->ano){
        if(data1->mes > data2->mes){
            return 1;
        }else if(data1->mes < data2->mes){
            return -1;
        }else if(data1->mes == data2->mes){
            if(data1->dia > data2-> dia){
                return 1;
            }else if( data1->dia < data2->dia){
                return -1;
            }else if(data1->dia == data2->dia){
                return 0;
            }
        }
    }
    return -2;
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


    if(ComparaData(data1, data2) == 0){
        LiberaData(data_aux);
        return 0;
    }if(ComparaData(data1, data2) == 1){
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

    LiberaData(data_aux);
    return diferenca_dias;
}