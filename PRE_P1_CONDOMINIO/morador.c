#include "area.h"
#include "morador.h"
#include "data.h"
#include "reserva.h"
#include <string.h>
#include <stdio.h>

Morador lerMorador(){
    Morador morador;
    scanf("%[^\n]\n", morador.nome);
    scanf("%[^\n]\n", morador.cpf);
    morador.dataNasc = lerData();
    scanf("%[^\n]\n", morador.idResidencia);
    return morador;
}

void imprimeMorador(Morador m){
    printf("Nome: %s\n", m.nome);
    printf("CPF: %s\n", m.cpf);
    printf("Data de Nascimento: ");
    imprimeData(m.dataNasc);
    printf("Residência: %s\n", m.idResidencia);
}

int comparaMorador(Morador m1, Morador m2){
    if(!strcmp(m1.cpf, m2.cpf)){
        return 1;
    }else{
        return 0;
    }
}

int verificaCPFMorador(Morador m1, char *cpf){
    if(!strcmp(m1.cpf, cpf)){
        return 1;
    }else{
        return 0;
    }
}

int calculaIdadeMorador(Morador m, Data dataRef){
    return calcularDiffAnosData(m.dataNasc, dataRef);
}