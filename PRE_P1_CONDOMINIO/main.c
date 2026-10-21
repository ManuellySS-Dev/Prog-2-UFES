#include <stdio.h>
#include "area.h"
#include "morador.h"
#include "data.h"
#include "reserva.h"
#include <string.h>

int main(){
    int qtd_areas=0, i=0, qtd_moradores=0, qtd_reservas=0, indice_morador=0, indice_area=0, qtd_convidados=0, n_reservas=0, qtd_solicitacoes=0;
    char cpf[MAX_TAM_CPF], identificador_area[10];
    Data datareserva;
    Reserva agendareservas[100];

    scanf("%d\n", &qtd_areas);
    Area area[qtd_areas];

    for(i=0; i<qtd_areas; i++){
        area[i] = lerArea();
    }

    scanf("%d\n", &qtd_moradores);
    Morador morador[qtd_moradores];

    for(i=0; i<qtd_moradores; i++){
        morador[i] = lerMorador();
    }

    scanf("%d\n", &qtd_solicitacoes);
    for(i=0; i<qtd_solicitacoes; i++){
        //verifica qual das areas pertence esse identificador
        scanf("%[^\n]\n", identificador_area);
        scanf("%[^\n]\n", cpf);
        datareserva = lerData();
        scanf("%d\n", &qtd_convidados);
    
        for(indice_area=0; indice_area<qtd_areas; indice_area++){
            if(verificaIdArea(area[indice_area], identificador_area)){
                break;
            }
        }
        if(indice_area == qtd_areas){
            printf("deu errado");
            continue;
        }
        //verifica a qual dos moradores pertence esse cpf
        for(indice_morador=0; indice_morador<qtd_moradores; indice_morador++){
            if(verificaCPFMorador(morador[indice_morador], cpf)){
                break;
            }
        }
        if(indice_morador == qtd_moradores){
            continue;
        }
        

        if(verificaSolicitacaoReserva(agendareservas, n_reservas, morador[indice_morador], area[indice_area], datareserva, qtd_convidados)){
            agendareservas[n_reservas] = criaReserva(morador[indice_morador], area[indice_area], datareserva, qtd_convidados);
            n_reservas++;
        } 
    }
        for(i=0; i<n_reservas; i++){
            imprimeReserva(agendareservas[i]);
        }

return 0;
}