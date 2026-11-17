#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

struct pacote {
    Type tipo;
    void * mensagem;
    int soma_mensagem;
    int qtd_elementos;
};

tPacote* CriaPacote(Type type, int numElem){
    tPacote * pacote = (tPacote*) calloc(1, sizeof(tPacote));
    if(type == CHAR){
        pacote->mensagem = (char*) calloc(numElem, sizeof(char)); 
    }else{
        pacote->mensagem = (int*) calloc(numElem, sizeof(int)); 
    }
    pacote->qtd_elementos = numElem;
    pacote->tipo = type;
    return pacote;
}

void DestroiPacote(tPacote* pac){
    free(pac->mensagem);
    free(pac);
}

void LePacote(tPacote* pac){
    for(int i=0; i<pac->qtd_elementos; i++){
        if(pac->tipo == CHAR){
            char * m_char = (char*) pac->mensagem;
            scanf(" %c", &m_char[i]);
        }else{
            int * m_int = (int*) pac->mensagem;
            scanf(" %d", &m_int[i]); 
        }
    }
}

void ImprimePacote(tPacote* pac){
    for(int i=0; i<pac->qtd_elementos; i++){
        if(pac->tipo == CHAR){
            char * m_char = (char*) pac->mensagem;
            printf("%c ", m_char[i]);
        }else{
            int * m_int = (int*) pac->mensagem;
            printf("%d ", m_int[i]); 
        }
    }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
      for(int i=0; i<pac->qtd_elementos; i++){
        if(pac->tipo == CHAR){
            char * m_char = (char*) pac->mensagem;
            pac->soma_mensagem += m_char[i];
        }else{
            int * m_int = (int*) pac->mensagem;
            pac->soma_mensagem += m_int[i];
        }
    }  
}