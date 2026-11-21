#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "lista_contato.h"
#include "vector.h"

struct ListaContato{
    Vector * contatos;
    int qtd_contatos;
};

tListaContato *CriarListaContato(){
    tListaContato * lc = (tListaContato*) calloc(1, sizeof(tListaContato));
    lc->contatos = VectorConstruct();

    return lc;
}

void DestroiContatoGenerico(DataType dado){
    tContato*contato = (tContato*) dado;
    DestruirContato(contato);
}
void DestruirListaContato(tListaContato *l){
    VectorDestroy(l->contatos, DestroiContatoGenerico);
    free(l);
}

void AdicionarContatoListaContato(tListaContato *l, tContato *contato){
    int contato_repetido=0;
    for(int i=0; i<l->qtd_contatos; i++){
        if(ComparaNomeContato(contato, VectorGet(l->contatos, i))){
            printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
            contato_repetido =1;
            DestruirContato(contato);
            return;
        }
    }
    for(int i=0; i<l->qtd_contatos; i++){
        if(ComparaTelefoneContato(contato, VectorGet(l->contatos, i))){
            printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
            contato_repetido =1;
            DestruirContato(contato);
            return;
        }
    }
    if(contato_repetido == 0){
        //ImprimirContato(contato);
        VectorPushBack(l->contatos, contato);
        l->qtd_contatos++;
    }   
}

void CarregarListaContato(tListaContato *l, char* nomeArquivo){
    FILE *lista_completa = fopen(nomeArquivo, "rb");
    if(lista_completa != NULL){
        int qtd = 0;
        if (fread(&qtd, sizeof(int), 1, lista_completa) == 1 && qtd > 0) {
            for(int i = 0; i < qtd; i++){
                tContato *c = CarregarContato(lista_completa);
                if (c != NULL) {
                    char *nome = GetNomeContato(c);
                    if (nome != NULL) {
                        nome[100] = '\0'; //garantindo o \0 pro strcmp nao dar problema
                    }
                    VectorPushBack(l->contatos, c);
                    l->qtd_contatos++;
                }
            }
        }
        fclose(lista_completa);
    }
}

void SalvarListaContato(tListaContato *l, char* nomeArquivo){
    FILE * lista_completa = fopen(nomeArquivo, "wb");
    if(lista_completa != NULL){
        fwrite(&l->qtd_contatos, sizeof(int), 1, lista_completa);
        for(int i=0; i<l->qtd_contatos; i++){
            SalvarContato(VectorGet(l->contatos,i), lista_completa);
        }
        fclose(lista_completa);
    }
}

void BuscarPorNumeroTelefoneListaContato(tListaContato *l){
    unsigned long int telefone;
    scanf("%lu", &telefone);

    for(int i=0; i<l->qtd_contatos; i++){
        if(GetTelefoneContato(VectorGet(l->contatos, i)) == telefone){
            ImprimirContato(VectorGet(l->contatos, i));
            return;
        }
    }
    printf("Contato nao encontrado\n");
}

void BuscarPorNomeListaContato(tListaContato *l){
    char nome[101];
    scanf(" %[^\n]\n", nome);
    
    for(int i=0; i<l->qtd_contatos; i++){
        if(!strcmp(GetNomeContato(VectorGet(l->contatos, i)), nome)){
            ImprimirContato(VectorGet(l->contatos, i));
            return;
        }
    }
    printf("Contato nao encontrado\n");
}

void ImprimirListaContato(tListaContato *l){
    printf("\nLista de contatos cadastrados\n");

    for(int i=0; i<l->qtd_contatos; i++){
        ImprimirContato(VectorGet(l->contatos, i));
        printf("\n");
    }
}

void RemoverContatoListaContato(tListaContato *l){
if (l == NULL) return;

    unsigned long int telefone;
    if (scanf("%lu", &telefone) != 1) return;

    for(int i = 0; i < l->qtd_contatos; i++){
        tContato *alvo = (tContato *)VectorGet(l->contatos, i);
        if(GetTelefoneContato(alvo) == telefone){
            DestruirContato(alvo);
            VectorRemove(l->contatos, i);
            l->qtd_contatos--;
            printf("Contato removido com sucesso\n");
            return;
        }
    }
    printf("Nao existe um contato cadastrado com esse numero de telefone\n");

}