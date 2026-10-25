#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

struct Locadora{
    tFilme ** filmes;
    int qtd_filmes;
    int lucro;
};

tLocadora* CriarLocadora (){
    tLocadora * locadora = (tLocadora*) calloc(1, sizeof(tLocadora));
    locadora->filmes = (tFilme**) calloc(MAX_CARACTERES, sizeof(tFilme*));
    return locadora;
}

void DestruirLocadora (tLocadora* locadora){
    int i=0;
    for(i=0; i<locadora->qtd_filmes; i++){
        DestruirFilme(locadora->filmes[i]);
    }
    free(locadora->filmes);
    free(locadora);
}


int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    int i=0;
    for(i=0; i<locadora->qtd_filmes; i++){
        if(EhMesmoCodigoFilme(locadora->filmes[i], codigo)){
            return 1;
        }
    }
    return 0;
}


void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))){
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme); //eh necessario desalocar agora o filme que nao vai pro vetor de filmes porque soh o vetor de filmes eh destruido em apaga locadora e esse fica de fora
    }else{
        locadora->filmes[locadora->qtd_filmes] = filme;
        printf("Filme cadastrado - %d - ", ObterCodigoFilme(locadora->filmes[locadora->qtd_filmes]));
        ImprimirNomeFilme(locadora->filmes[locadora->qtd_filmes]);
        printf("\n");
        locadora->qtd_filmes++;
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
    int i=0, j=0, custo=0, alugados=0;
    for(i=0; i<quantidadeCodigos; i++){
        if(!VerificarFilmeCadastrado(locadora, codigos[i])){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }else{
            for(j=0; j<locadora->qtd_filmes; j++){
                if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                    if(ObterQtdEstoqueFilme(locadora->filmes[j])>0){
                        AlugarFilme(locadora->filmes[j]);
                        custo+= ObterValorFilme(locadora->filmes[j]);
                        alugados++;
                    }else{
                        printf("Filme %d - ", ObterCodigoFilme(locadora->filmes[j])); 
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    }
                }
            }
        }
    }
    if(alugados>0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", alugados, custo);
    }
}

void LerAluguelLocadora (tLocadora* locadora){
    int codigos[10], qtd_codigos=0;

    while(scanf(" %d", &codigos[qtd_codigos])==1){
        qtd_codigos++;
    }
    scanf("*c");
    AlugarFilmesLocadora(locadora, codigos, qtd_codigos);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i=0, j=0;
    for(i=0; i<quantidadeCodigos; i++){
        if(!VerificarFilmeCadastrado(locadora, codigos[i])){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }else{
            for(j=0; j<locadora->qtd_filmes; j++){
                if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                    if(ObterQtdAlugadaFilme(locadora->filmes[j])>0){
                        DevolverFilme(locadora->filmes[j]);
                        printf("Filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(" Devolvido!\n");
                        locadora->lucro += ObterValorFilme(locadora->filmes[j]);
                    }else{
                        printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(".\n");
                    }
                }
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora){
    int codigos[10], qtd_codigos=0;

    while(scanf(" %d", &codigos[qtd_codigos])==1){
        qtd_codigos++;
    }
    scanf("*c");
    DevolverFilmesLocadora(locadora, codigos, qtd_codigos);
}

void OrdenarFilmesLocadora (tLocadora* locadora){
    int i=0, j=0; 
    tFilme * aux;
    for(i=0; i<locadora->qtd_filmes-1; i++){
        for(j=0; j<locadora->qtd_filmes-1-i; j++){
            if(CompararNomesFilmes(locadora->filmes[j+1], locadora->filmes[j]) < 0){
                aux = locadora->filmes[j+1];
                locadora->filmes[j+1] = locadora->filmes[j];
                locadora->filmes[j] = aux;
            }
        }    
    } 
}

void ConsultarEstoqueLocadora (tLocadora* locadora){
    int i=0; 
    OrdenarFilmesLocadora(locadora);
    printf("~ESTOQUE~\n");
    for(i=0; i<locadora->qtd_filmes; i++){
        printf("%d - ",ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);
        printf(" - Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
    }

}

void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro >0){
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}