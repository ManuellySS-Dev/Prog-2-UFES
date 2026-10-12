#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

tLocadora* CriarLocadora (){
    tLocadora * locadora = (tLocadora*) calloc(1, sizeof(tLocadora));
   
    if(locadora == NULL){
        printf("nao foi possivel alocar memoria para locadora\n");
        exit(0);
    }
    locadora->filme = (tFilme**) calloc(100, sizeof(tFilme*)); 
    
    if(locadora->filme == NULL){
        printf("nao foi possivel alocar memoria para os filmes\n");
        free(locadora);
        exit(1);
    }
    return locadora;
}

void DestruirLocadora (tLocadora* locadora){
    int i=0;
    for(i=0; i<100; i++){
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    int i=0;
    for(i=0; i<locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo)){
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(VerificarFilmeCadastrado(locadora, filme->codigo)){
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme); //eh necessario desalocar agora o filme que nao vai pro vetor de filmes porque soh o vetor de filmes eh destruido em apaga locadora e esse fica de fora
    }else{
        locadora->filme[locadora->numFilmes] = filme;
        printf("Filme cadastrado - %d - ", locadora->filme[locadora->numFilmes]->codigo);
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes]);
        printf("\n");
        locadora->numFilmes++;
    }
}

void LerCadastroLocadora (tLocadora* Locadora){
    tFilme * filme;
    int codigo=0;
    scanf(" %d,", &codigo);
    do{
    filme = CriarFilme();
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
    }while(scanf(" %d,", &codigo)==1);
    scanf("#");
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i=0, j=0, flag_alugou=0, qtd_alugueis_validos=0, custo_alugueis=0;
    for(i=0; i<quantidadeCodigos; i++){
        flag_alugou=0;
        for(j=0; j<locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])){
                if(locadora->filme[j]->qtdEstoque > 0){
                    AlugarFilme(locadora->filme[j]);
                    custo_alugueis += locadora->filme[j]->valor;
                    flag_alugou=1;
                    qtd_alugueis_validos++;
                }else{
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", codigos[i], locadora->filme[j]->nome);
                    flag_alugou=1;
                }
                break;
            }
        }
        if(flag_alugou == 0){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    if(qtd_alugueis_validos>0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtd_alugueis_validos, custo_alugueis);
    }
}

void LerAluguelLocadora (tLocadora* locadora){
    int i=0, n=0;
    int * codigos = (int*) calloc(10, sizeof(int));
    while(scanf(" %d", &n) ==1){
        codigos[i] = n;
        i++;
    }
    scanf("#");
    AlugarFilmesLocadora(locadora, codigos, i);
    free(codigos);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i=0, j=0, flag_devolveu=0;
    for(i=0; i<quantidadeCodigos; i++){
        flag_devolveu=0;
        for(j=0; j<locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])){
                if(locadora->filme[j]->qtdAlugada>0){
                    DevolverFilme(locadora->filme[j]);
                    printf("Filme %d - %s Devolvido!\n", locadora->filme[j]->codigo, locadora->filme[j]->nome);
                    locadora->lucro += locadora->filme[j]->valor;
                }else{
                    printf("Nao e possivel devolver o filme %d - %s.\n", locadora->filme[j]->codigo, locadora->filme[j]->nome);
                }

                flag_devolveu = 1;
                break;
            }
        }
        if(flag_devolveu == 0){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora){
    int i=0, n=0;
    int * codigos = (int*) calloc(10, sizeof(int));
    while(scanf(" %d", &n) ==1){
        codigos[i] = n;
        i++;
    }
    scanf("#");
    DevolverFilmesLocadora(locadora, codigos, i);
    free(codigos);
}

void OrdenarFilmesLocadora (tLocadora* locadora){
    int i=0, j=0;
    tFilme * aux;
    for(i=0; i<locadora->numFilmes-1; i++){
        for(j=0; j<locadora->numFilmes-1-i; j++){
            if(CompararNomesFilmes(locadora->filme[j+1], locadora->filme[j]) < 0){
                aux = locadora->filme[j+1];
                locadora->filme[j+1] = locadora->filme[j];
                locadora->filme[j] = aux;
            }
        }
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora){
    int i=0;
    printf("~ESTOQUE~\n");
    for(i=0; i<locadora->numFilmes; i++){
        printf("%d - ", locadora->filme[i]->codigo);
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" - Fitas em estoque: %d\n", locadora->filme[i]->qtdEstoque);
    }
}

void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro>0){
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}