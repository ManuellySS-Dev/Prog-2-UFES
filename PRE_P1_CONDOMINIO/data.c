#include "area.h"
#include "morador.h"
#include "data.h"
#include "reserva.h"
#include <string.h>
#include <stdio.h>

Data lerData(){
    Data data;
    scanf("%d/%d/%d\n", &data.dia, &data.mes, &data.ano);
    return data;
}

void imprimeData(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

int comparaData(Data d1, Data d2){
    if(d1.dia == d2.dia){
        if(d1.mes == d2.mes){
            if(d1.ano == d2.ano){
                return 1;
            }
        }
    }
    return 0;
}

int calcularDiffAnosData(Data inicio, Data fim){
    if(inicio.mes == fim.mes){
        if(fim.dia >= inicio.dia){
            return (fim.ano - inicio.ano); 
        }else if(fim.dia < inicio.dia){
            return ((fim.ano - inicio.ano) -1); 
        }
    }else if(inicio.mes > fim.mes){
        return (fim.ano - inicio.ano); 
    }else if(inicio.mes < fim.mes){
        return ((fim.ano - inicio.ano) -1); 
    }
}
