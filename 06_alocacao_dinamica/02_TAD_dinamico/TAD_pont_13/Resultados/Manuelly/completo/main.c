#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

void Relatorio(int num_pacientes, Paciente * pacientes[]){
    Data * dataBase;
    dataBase  = criaData(14,8,2023);
    int i=0, media_idades=0, total_lesoes=0, total_cirurgias=0;
    for(i=0; i<num_pacientes; i++){
        total_lesoes += getNumLesoesPaciente(pacientes[i]);
    }
    for(i=0; i<num_pacientes; i++){
        total_cirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
    }
    for(i=0; i<num_pacientes; i++){
        media_idades += calculaIdadePaciente(pacientes[i], dataBase);
    }
    media_idades = media_idades/num_pacientes;
    printf("TOTAL PACIENTES: %d\nMEDIA IDADE (ANOS): %d\nTOTAL LESOES: %d\nTOTAL CIRURGIAS: %d\nLISTA DE PACIENTES:\n", num_pacientes, media_idades, total_lesoes, total_cirurgias);
    for(i=0; i<num_pacientes; i++){
        imprimePaciente(pacientes[i]);
    }
    liberaData(dataBase);
}
int main(){
    char operacao='\0';
    int i=0, num_pacientes=0, achou=0;
    Paciente * pacientes[100];
    Lesao * lesao;

    while(scanf("%c\n", &operacao ) == 1){
        if(operacao == 'P'){
            pacientes[num_pacientes] = lerPaciente();
            num_pacientes++;
        }else if(operacao == 'L'){
            lesao = lerLesao();
            achou=0;
            for(i=0; i<num_pacientes; i++){
                if(!strcmp(getCartaoSusLesao(lesao), getCartaoSusPaciente(pacientes[i]))){
                    vinculaLesaoPaciente(pacientes[i], lesao);
                    achou=1;
                    break;
                }
            }
                if(achou==0){
                    liberaLesao(lesao);
                }
        }else if(operacao == 'F'){
            if(num_pacientes>0){
                Relatorio(num_pacientes, pacientes);
            }else{
                printf("TOTAL PACIENTES: 0\nMEDIA IDADE (ANOS): -\nTOTAL LESOES: 0\nTOTAL CIRURGIAS: 0\nLISTA DE PACIENTES:\n");
            }
            break;
        }
    }

    for(i=0; i<num_pacientes; i++){
        liberaPaciente(pacientes[i]);
    }
    return 0;
}