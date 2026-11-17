#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include "agendatarefas.h"

int main(){
    tAgendaTarefas * agenda;
    int num_tarefas=0, prioridade=0, qtd_cadastradas=0;
    char operacao = '\0';
    char msg[100];
    float n1=0, n2=0;
    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &num_tarefas);
    agenda = CriaAgendaDeTarefas(num_tarefas);

    while(scanf("%d\n", &prioridade)==1){
        scanf(" %c ", &operacao);
        if(qtd_cadastradas < num_tarefas){
            if(operacao == 'I'){
                scanf(" %[^\n]\n", msg);
                CadastraTarefaNaAgenda(agenda,prioridade, CriaTarefaImprimir(msg), ExecutaTarefaImprimir, DestroiTarefaImprimir);
                qtd_cadastradas++;
            }else if(operacao == 'S'){
                scanf(" %f %f\n", &n1, &n2);
                CadastraTarefaNaAgenda(agenda,prioridade, CriaTarefaSoma(n1,n2), ExecutaTarefaSoma, DestroiTarefaSoma);
                qtd_cadastradas++;
            }else if(operacao == 'M'){
                scanf(" %f %f\n", &n1, &n2);
                CadastraTarefaNaAgenda(agenda,prioridade, CriaTarefaMultiplicar(n1, n2), ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                qtd_cadastradas++;
            }else{
                scanf(" %[^\n]\n", msg);
                printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            }
        }
    }

    ExecutarTarefasDaAgenda(agenda);

    DestroiAgendaDeTarefas(agenda);

    return 0;
}