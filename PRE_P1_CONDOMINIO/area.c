#include "area.h"
#include "morador.h"
#include "data.h"
#include "reserva.h"
#include <string.h>
#include <stdio.h>

Area lerArea(){
    Area area;
    scanf("%[^\n]\n", area.nome);
    scanf("%[^\n]\n", area.id);
    scanf("%d\n", &area.capacidade);
    return area;
}

void imprimeArea(Area a){
    //printf("Area reservada: \n");
    printf("Nome: %s\n", a.nome);
    printf("Id: %s\n", a.id);
    printf("Capacidade: %d convidado(s)\n", a.capacidade);
}

int comparaArea(Area a1, Area a2){
    if(!strcmp(a1.id, a2.id)){ //se sao iguais strcmp retorna 0
        return 1;
    }else{
        return 0;
    }
}

int verificaIdArea(Area a, char *id){
    if(!strcmp(a.id, id)){ //se sao iguais strcmp retorna 0
        return 1;
    }else{
        return 0;
    }
}

int getCapacidadeArea(Area a){
    return a.capacidade;
}
