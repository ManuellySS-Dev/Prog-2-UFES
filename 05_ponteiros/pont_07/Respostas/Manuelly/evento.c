#include <stdio.h>
#include "evento.h"
#include "string.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    int dia=0, mes=0,ano=0;
    char nome[50];
    if(*numEventos <MAX_EVENTOS){
        scanf(" %[^\n]\n", nome);
        strcpy(eventos[*numEventos].nome, nome);
        scanf("%d %d %d\n", &dia,&mes,&ano);
        eventos[*numEventos].dia = dia;
        eventos[*numEventos].mes = mes;
        eventos[*numEventos].ano = ano;
        (*numEventos)++;
        printf("Evento cadastrado com sucesso!\n");
    }else{
        printf("numero maximo de eventos excedido!\n");
    }
}

void exibirEventos(Evento* eventos, int* numEventos){
    int i=0;
    printf("Eventos cadastrados:\n");
    for(i=0; i<*numEventos; i++){
        printf("%d - %s - %d/%d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indice_do_evento_a_ter_data_trocada=0,dia_trocado=0, mes_trocado=0,ano_trocado=0;
    scanf("%d\n", &indice_do_evento_a_ter_data_trocada);
    if(indice_do_evento_a_ter_data_trocada<*numEventos){
        scanf("%d %d %d\n", &dia_trocado, &mes_trocado, &ano_trocado);
        eventos[indice_do_evento_a_ter_data_trocada].dia = dia_trocado;
        eventos[indice_do_evento_a_ter_data_trocada].mes = mes_trocado;
        eventos[indice_do_evento_a_ter_data_trocada].ano = ano_trocado;
        printf("Data modificada com sucesso!\n");
    }else{
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    int aux_dia=0, aux_ano=0, aux_mes=0;
    char aux_nome[50];
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        //passando dados de A para auxiliares
        aux_dia = eventos[*indiceA].dia;
        aux_mes = eventos[*indiceA].mes;
        aux_ano = eventos[*indiceA].ano;
        strcpy(aux_nome, eventos[*indiceA].nome);

        //passando dados de B para A
        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceA].ano = eventos[*indiceB].ano;
        strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);

        //passando dados de A para B por meio dos auxiliares
        eventos[*indiceB].dia = aux_dia;
        eventos[*indiceB].mes = aux_mes;
        eventos[*indiceB].ano = aux_ano;
        strcpy(eventos[*indiceB].nome, aux_nome);
        printf("Eventos trocados com sucesso!\n");
    }else{
        printf("Indices invalidos!\n");
    }
}