#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"
#include "tarefasoma.h"

typedef struct {
    int prioridade;
    void (*executa)(void*);
    void (*destroi)(void*);
    void * tarefa;
}tTarefa;

struct agendatarefas{
    tTarefa ** tarefas;
    int numElementos;
    int qtd_cadastradas;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas * agenda = (tAgendaTarefas*) calloc(1, sizeof(tAgendaTarefas));
    agenda->numElementos = numElem;
    agenda->tarefas = (tTarefa**) calloc(numElem, sizeof(tTarefa*));
    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    for(int i=0; i<tar->numElementos; i++){
        tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa); //liberando o elemento tarefa
        free(tar->tarefas[i]); //liberando a posicao na lista
    }
    free(tar->tarefas); //liberando a lista em si
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    if(tar->qtd_cadastradas < tar->numElementos){
        //eh necessario alocar memoria pra cada posicao do vetor de tarefas pois o calloc deixa as posicoes nulas no cria agenda
        tTarefa * nova_tarefa = (tTarefa*) calloc(1, sizeof(tTarefa));
        if (nova_tarefa == NULL){
            exit(0);
        }

        nova_tarefa->prioridade = prioridade;
        nova_tarefa->executa = executa;
        nova_tarefa->destroi = destroi;
        nova_tarefa->tarefa = tarefa;

        tar->tarefas[tar->qtd_cadastradas] = nova_tarefa;
        tar->qtd_cadastradas++;
    }
}

void OrdenaVetorTarefas(tAgendaTarefas* tar){
    int i=0, j=0;
    tTarefa * aux;
    for(i=0; i<tar->numElementos-1; i++){
        for(j=0; j<tar->numElementos -i-1; j++){
            if(tar->tarefas[j]->prioridade < tar->tarefas[j+1]->prioridade){
                aux = tar->tarefas[j];
                tar->tarefas[j] = tar->tarefas[j+1];
                tar->tarefas[j+1] = aux;
            }
        }
    }
}
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    OrdenaVetorTarefas(tar);
    for(int i=0; i<tar->numElementos; i++){
        tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
    }
}