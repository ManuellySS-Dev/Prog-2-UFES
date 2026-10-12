#include "data.h"
#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"

int main(){
    Paciente pacientes[15];
    Lesao l;
    char operacao ='\0', cartaoP[MAX_CARTAO_SUS], cartaoL[MAX_CARTAO_LES];
    int n_pacientes=0, i=0;

    while(scanf("%c\n", &operacao)==1){
        if(operacao == 'P'){
            pacientes[n_pacientes] = lerPaciente();
            n_pacientes++;
        }else if(operacao == 'L'){
            l = lerLesao();
            getCartaoSusLesao(l, cartaoL);
            for(i=0; i<n_pacientes; i++){
                getCartaoSusPaciente(pacientes[i], cartaoP);
                if(!strcmp(cartaoP, cartaoL)){
                    pacientes[i] = vinculaLesaoPaciente(pacientes[i], l);
                }
            }
        }else if(operacao == 'F'){
            if(n_pacientes>0){
            int total_lesoes=0, total_cirurgias=0, media=0;
            Data dataBase;
            dataBase = criaData(12,9,2023);
            for(i=0; i<n_pacientes; i++){
                media += calculaIdadePaciente(pacientes[i], dataBase);
                total_lesoes += getNumLesoesPaciente(pacientes[i]);
                total_cirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
            }
            media = media/n_pacientes;
                printf("TOTAL PACIENTES: %d\n", n_pacientes);
                printf("MEDIA IDADE (ANOS): %d\n", media);
                printf("TOTAL LESOES: %d\n", total_lesoes);
                printf("TOTAL CIRURGIAS: %d\n", total_cirurgias);
                printf("LISTA DE PACIENTES:\n");
            for(i=0; i<n_pacientes; i++){
                imprimePaciente(pacientes[i]);
            }
        }else{
            printf("TOTAL PACIENTES: 0\nMEDIA IDADE (ANOS): -\nTOTAL LESOES: 0\nTOTAL CIRURGIAS: 0\nLISTA DE PACIENTES:\n");
        }
            break;
        }
    }




    return 0;
}