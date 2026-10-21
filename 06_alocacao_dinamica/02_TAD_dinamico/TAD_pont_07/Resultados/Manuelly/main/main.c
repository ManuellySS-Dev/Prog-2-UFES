#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main(){
    tData * data1;
    tData * data2;
    data1 = CriaData();
    data2 = CriaData();
    LeData(data1);
    LeData(data2);

    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        LiberaData(data1);
        LiberaData(data2);
        exit(0);
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);    
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);


    if(ComparaData(data1, data2) == 1){
        printf("A segunda data eh mais antiga\n");
        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1,data2));
    }else if(ComparaData(data1, data2) == -1){
        printf("A primeira data eh mais antiga\n");
        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1,data2));
    }else if(ComparaData(data1, data2) == 0){
        printf("As datas sao iguais\n");
        printf("A diferenca em dias entre as datas eh: 00 dias\n", CalculaDiferencaDias(data2,data1));
    }

    LiberaData(data1);
    LiberaData(data2);
    return 0;
}