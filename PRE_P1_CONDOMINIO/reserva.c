#include "area.h"
#include "morador.h"
#include "data.h"
#include "reserva.h"
#include <string.h>
#include <stdio.h>

Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    Reserva reserva;
    reserva.morador = morRes;
    reserva.area = aRes;
    reserva.data = dRes;
    reserva.qtdConvidados = qtdConvidados;
    return reserva;
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    int i=0;
    //Se o morador tem menos de 18 anos nao pode reservar
    if(calculaIdadeMorador(morRes, dRes) < 18){
        return 0;
    }
    //Se o numero de convidados eh maior que a capacidade da area nao pode reservar
    if(qtdConvidados > aRes.capacidade){
        return 0;
    }
    for(i=0; i<nRes; i++){
        //Se o morador ja tem reserva em um dia igual ele nao pode marcar outra
        if(comparaMorador(morRes, agendaReservas[i].morador)){
            if(comparaData(dRes, agendaReservas[i].data)){
                return 0;
            }
        }
        //Se a area jah foi reservada em um dia igual ele nao pode marcar reserva na mesma area
        if(comparaArea(aRes, agendaReservas[i].area)){
            if(comparaData(dRes, agendaReservas[i].data)){
                return 0;
            }
        }
    } 
    return 1;
}

void imprimeReserva(Reserva r){
int taxa_de_ocupacao = 0;

taxa_de_ocupacao = ((r.qtdConvidados*100)/(r.area.capacidade));

printf("--------- RESERVA -----------\n");
printf("Morador: \n");
imprimeMorador(r.morador);
printf("\n");
printf("Area reservada: \n");
imprimeArea(r.area);
printf("Data da reserva: ");
imprimeData(r.data);
printf("\n");
printf("Quantidade de convidados: %d\n",r.qtdConvidados);
printf("Taxa de ocupação: %.2d%%\n", taxa_de_ocupacao);
printf("------------------------------\n");
}