#include <stdio.h>
#include "data.h"

int main(){
    int mes1=0, mes2=0, dia1=0, dia2=0, ano1=0, ano2=0;
    //le e verifica se datas sao validas
    scanf("%d/%d/%d\n", &dia1, &mes1, &ano1);
    if(verificaDataValida(dia1, mes1, ano1) == 0){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    if(verificaDataValida(dia2, mes2, ano2) ==0){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
    //Imprime datas por extenso
    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    //compara datas
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0){
        printf("As datas sao iguais\n");
    }else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        printf("A segunda data eh mais antiga\n");
    }else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        printf("A primeira data eh mais antiga\n");
    }
 
    //diferenca em dias
    printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
return 0;
}