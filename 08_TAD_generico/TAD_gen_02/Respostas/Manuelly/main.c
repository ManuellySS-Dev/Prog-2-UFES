#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

int main(){
    int opcao=0, tipo=0, qtd_elementos=0, idx=0;
    tGerenciador * gerencia;
    tPacote * pacote;
    gerencia = CriaGerenciador();
    printf("\n");
    while(scanf("%d", &opcao) ==1){
        printf("Escolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote especifico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");
        printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");

        if(opcao ==1){
            scanf("%d %d\n", &tipo, &qtd_elementos);
            if(tipo == CHAR || tipo == INT){
                pacote = CriaPacote(tipo, qtd_elementos);
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerencia, pacote);
            }
        }else if(opcao ==2){
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(gerencia, idx);
        }else if(opcao == 3){
            ImprimirTodosPacotes(gerencia);
            break;
        }
    }

    DestroiGerenciador(gerencia);

    return 0;
}