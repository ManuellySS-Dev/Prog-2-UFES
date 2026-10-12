#include <stdio.h>
#include "data.h"

int main(){
    int mes=0, mes2=0, dia=0, dia2=0, ano=0, ano2=0;
    //le e verifica se datas sao validas
    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    if(verificaDataValida(dia, mes, ano) == 0){
        printf("A data informada eh invalida\n");
        return 0;
    }

    //Imprime datas por extenso
    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    //Ano bissexto
    if(verificaBissexto(ano) ==1){
        printf("O ano informado eh bissexto\n");
    }else{
        printf("O ano informado nao eh bissexto\n");
    }

    //compara datas
    printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));
 
    //diferenca em dias
    printf("A data seguinte eh: ");
    imprimeProximaData( dia,  mes,  ano);
return 0;
}