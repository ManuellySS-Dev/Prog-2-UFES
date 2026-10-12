#include "data.h"
#include <stdio.h>
#include "paciente.h"
#include "lesao.h"

Data criaData(int dia, int mes, int ano){
    Data data;
    data.dia=dia;
    data.mes=mes;
    data.ano=ano;
    return data;
}

Data lerData(){
    Data data;
    int dia=0, mes=0, ano=0;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    data = criaData(dia, mes, ano);
    return data;   
}

int diferencaAnoData(Data inicial, Data atual){
    int diferenca=0;
    if(inicial.mes < atual.mes){
        diferenca = (atual.ano - inicial.ano);
    }else if(inicial.mes == atual.mes){
        if(inicial.dia == atual.dia){
            diferenca = (atual.ano - inicial.ano);
        }else if(inicial.dia < atual.dia){
            diferenca = (atual.ano - inicial.ano);
        }else if(inicial.dia > atual.dia){
            diferenca = (atual.ano - inicial.ano)-1;
        }
    }else if(inicial.mes > atual.mes){
        diferenca = (atual.ano - inicial.ano)-1;
    }
    return diferenca;
}

void imprimeData(Data d){
    printf("%02d/%02d/%d\n", d.dia, d.mes, d.ano);
}