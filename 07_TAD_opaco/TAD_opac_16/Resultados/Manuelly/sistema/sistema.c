#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sistema.h"
//Ver sobre as tarifas
struct Sistema{
    float faturamento;
};

tSistema* CriaSistema(){
    tSistema * sys = (tSistema*) calloc(1, sizeof(tSistema));
    sys->faturamento=0;
    return sys;
}

void DestroiSistema(tSistema* sys){
    free(sys);
}

void LeSistema(tSistema* sys){
    tData * Entrada;
    tData * Saida;
    int proximo=0, i=0, controle=0;
    char string[40], dia_semana_e[2], data_e[13], horario_e[7], dia_semana_s[2], data_s[13], horario_s[7], caracter;

    while(scanf(" %[^\n]\n", string)!= EOF){
        string[40] = '\0';

        Entrada = CriaData();
        Saida = CriaData();
        sscanf(string, " %[^;];%[^;];%[^;];%[^;];%[^\n]\n", dia_semana_e, data_e, horario_e, data_s, horario_s);
        ProcessaDiaDaSemana( Entrada,dia_semana_e);
        ProcessaDiaMesAno( Entrada,data_e);
        ProcessaDiaMesAno( Saida,data_s);    
        ProcessaHorario( Entrada,horario_e);
        ProcessaHorario( Saida,horario_s);
        sys->faturamento += CalculaPrecoTiquete(sys, Entrada, Saida);
        printf("O tiquete processado tem valor: %.2f reais\n", CalculaPrecoTiquete(sys, Entrada, Saida));
        free(Entrada);
        free(Saida);
    }

}

float CalculaPrecoTiquete(tSistema* sys, tData* dataEntrada, tData* dataSaida){
    int parte_inteira=0;
    float copia_valor=0, arredonda=0, horas_ultimo_dia=0, horas_primeiro_dia=0;

    if(CalculaDiferencaDias(dataEntrada, dataSaida)<1){
            parte_inteira = CalculaHorasEntreDatas(dataEntrada, dataSaida);
            copia_valor = CalculaHorasEntreDatas(dataEntrada, dataSaida);
            arredonda = 1 - (copia_valor-parte_inteira);
        if(DataEhSabadoOuDomingo(dataEntrada)){     
            if(copia_valor > 0.25){
                return (copia_valor+arredonda) * 2;
            }else{
                return 0;
            }
        }else{
            if(copia_valor>0.25){
                if(arredonda >0.5){
                    return parte_inteira * 1;
                }else{
                    return (copia_valor+arredonda) * 1;
                }
            }else{
                return 0;
            } 
        }
    }else{
        float horas_uteis = 0;
        float horas_fds = 0;
        
        tData *aux_primeiro = CriaData();
        tData *aux_fim = CriaData();
        
        CopiaDiaMesAno(dataEntrada, aux_primeiro);
        CopiaDiaMesAno(dataEntrada, aux_fim);
        
        while(ComparaDiaMesAno(aux_fim, dataSaida) != 0){ 
            DataDiaSeguinte(aux_fim);
        }
        
        DataDiaSeguinte(aux_primeiro); 
        
        float horas_primeiro = CalculaHorasEntreDatas(dataEntrada, aux_primeiro);
        if(DataEhSabadoOuDomingo(dataEntrada)){
            horas_fds += horas_primeiro;
        } else {
            horas_uteis += horas_primeiro;
        }
        
        while(ComparaDiaMesAno(aux_primeiro, aux_fim) != 0){
            if(DataEhSabadoOuDomingo(aux_primeiro)){
                horas_fds += 24;
            } else {
                horas_uteis += 24;
            }
            DataDiaSeguinte(aux_primeiro);
        }
        
        float horas_ultimo = CalculaHorasEntreDatas(aux_fim, dataSaida);
        if(DataEhSabadoOuDomingo(aux_fim)){
            horas_fds += horas_ultimo;
        } else {
            horas_uteis += horas_ultimo;
        }
        
        DestroiData(aux_primeiro);
        DestroiData(aux_fim);
        //Arredondando as horas individualmente
        int inteiros_uteis = horas_uteis;
        if(horas_uteis > inteiros_uteis){
            horas_uteis = inteiros_uteis + 1;
        }
        
        int inteiros_fds = horas_fds;
        if(horas_fds > inteiros_fds){
            horas_fds = inteiros_fds + 1;
        }
        
        return (horas_uteis * 1.0) + (horas_fds * 2.0);
}
}

void ImprimeFaturamentoSistema(tSistema *sys){
    printf("O sistema faturou: %.2f reais\n", sys->faturamento);
}