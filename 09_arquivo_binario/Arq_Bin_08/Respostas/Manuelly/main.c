#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "lista_contato.h"
#include "vector.h"

int main(){
    char caminho_lista[100];
    char lixo[30];
    int controle=0;
    tListaContato * lc;
    lc = CriarListaContato();
    scanf(" %[^\n]\n", caminho_lista);
    FILE * entrada = fopen(caminho_lista, "rb");

    if(entrada != NULL){
        fclose(entrada);
        CarregarListaContato(lc, caminho_lista);
    }


    int operacao =0;

    while(1){
        if(scanf("%d", &operacao) == 1){
            printf("1 - Cadastrar contato\n");
            printf("2 - Remover contato\n");
            printf("3 - Realizar busca\n");
            printf("4 - Exibir todos os contatos\n");
            printf("0 - Sair da lista de contatos\n");
            printf("Opcao escolhida: \n");
            if(operacao == 1){
                tContato * contato = LeContato();
                AdicionarContatoListaContato(lc, contato);
            }else if(operacao == 2){
                RemoverContatoListaContato(lc);
            }else if(operacao ==3){
                printf("\n1 - Buscar pelo nome\n2 - Buscar pelo numero de telefone\nOpcao escolhida: \n");
                int tipo_busca;
                scanf("%d", &tipo_busca);
                if(tipo_busca ==1){
                    BuscarPorNomeListaContato(lc);
                }else{
                    BuscarPorNumeroTelefoneListaContato(lc);
                }
            }else if(operacao == 4){
                ImprimirListaContato(lc);
            }else if(operacao == 0){
                break;
            }
        }else{
            if(operacao != EOF){
                scanf("%[^\n]\n", lixo);
            }else{
                break;
            }
        }
        controle++;
        if(controle == 100){
            break;
        }
    }
    scanf(" %[^\n]\n", caminho_lista);
    SalvarListaContato(lc, caminho_lista);
    DestruirListaContato(lc);

    return 0;
}