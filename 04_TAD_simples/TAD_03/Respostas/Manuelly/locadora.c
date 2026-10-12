#include <stdio.h>
#include "filme.h"
#include "locadora.h"

tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i=0, j=0;
    for(i=0; i<locadora.numFilmes; i++){
        if(codigo == locadora.filme[i].codigo){
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
if (verificarFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
        return locadora;
    }
    locadora.filme[locadora.numFilmes] = filme;
    printf("Filme cadastrado %d - ", filme.codigo );
    imprimirNomeFilme(filme);
    printf("\n");
    locadora.numFilmes++;
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    tFilme filme;
    int codigo=0;
    while(scanf("%d,", &codigo) == 1){
        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }
    scanf("%*c");
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i=0, j=0, total_alugueis=0, custo=0,encontrou_filme_estoque=0;
    for(i=0; i<quantidadeCodigos; i++){
            encontrou_filme_estoque=0;
        for(j=0; j<locadora.numFilmes; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                encontrou_filme_estoque =1;
                if(locadora.filme[j].qtdEstoque > 0){
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                total_alugueis++;
                custo += locadora.filme[j].valor;
                }else{
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                }
            }

        }
                    if(!encontrou_filme_estoque){
                printf("Filme %d nao cadastrado.\n", codigos[i]);
            }
    }
    if(total_alugueis >0){
        printf("Total de filmes alugados: %d com custo de R$%d\n",total_alugueis, custo);
    }
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora){
    int i=0, codigos[100];
    while(scanf("%d\n", &codigos[i]) ==1){
        i++;
    }
    locadora = alugarFilmesLocadora(locadora, codigos, i);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
int i = 0, j = 0, f=0;

    for (i = 0; i < quantidadeCodigos; i++) {
        if (!verificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }


        for (j = 0; j < locadora.numFilmes; j++) {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                if(locadora.filme[j].qtdAlugada >0){
                locadora.filme[j] = devolverFilme(locadora.filme[j]);
                printf("Filme %d - %s Devolvido!\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                locadora.lucro += locadora.filme[j].valor;
                break;
                }else{
                printf("Nao e possivel devolver o filme %d - %s.\n", codigos[i], locadora.filme[j].nome); 
                break;   
                }
            }
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int i=0, codigos[100];
    while(scanf("%d\n", &codigos[i]) ==1){
        i++;
    }
    locadora = devolverFilmesLocadora(locadora, codigos, i);
    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int i=0, j=0;
    tFilme aux;
    for(i=0; i<locadora.numFilmes-1; i++){
        for(j=0; j<locadora.numFilmes-i-1; j++){
            if(compararNomesFilmes(locadora.filme[j], locadora.filme[j+1]) > 0){
                aux = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j+1];
                locadora.filme[j+1] = aux;
            }
        }
    }
    return locadora;   
}

void consultarEstoqueLocadora (tLocadora locadora){
    int i=0, j=0;
    locadora = ordenarFilmesLocadora(locadora);
    printf("~ESTOQUE~\n");
    for(i=0; i<locadora.numFilmes; i++){
        printf("%d - ", locadora.filme[i].codigo);
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", locadora.filme[i].qtdEstoque);
    }
}

void consultarLucroLocadora(tLocadora locadora){
    if(locadora.lucro>0){
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}