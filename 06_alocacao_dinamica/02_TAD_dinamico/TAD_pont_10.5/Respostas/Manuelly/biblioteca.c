#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

tBiblioteca* InicializarBiblioteca(){
    tBiblioteca * biblioteca = (tBiblioteca*) calloc(1, sizeof(tBiblioteca));
    if(biblioteca == NULL){
        exit(0);
    }
    biblioteca->livros = (tLivros**) calloc(NUM_INICIAL_LIVROS, sizeof(tLivros*));
    biblioteca->tam_max_atual=5;
    biblioteca->tamanho=0;
    return biblioteca;
}

void ApagaBiblioteca(tBiblioteca* biblioteca){
    int i=0;
    for(i=0; i<biblioteca->tamanho; i++){
        ApagaLivro(biblioteca->livros[i]);
    }
    free(biblioteca->livros);
    free(biblioteca);
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if(biblioteca->tamanho < biblioteca->tam_max_atual){
        biblioteca->livros[biblioteca->tamanho] = livro;
        biblioteca->tamanho++;
        printf("Livro adicionado com sucesso!\n");
    }else{
        biblioteca->livros = realloc(biblioteca->livros, (biblioteca->tamanho + 5) * sizeof(tLivros*));
        biblioteca->livros[biblioteca->tamanho] = livro;
        biblioteca->tamanho++;
        biblioteca->tam_max_atual = biblioteca->tam_max_atual+5;
        printf("Livro adicionado com sucesso!\n");
    }
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    int achou=0, i=0, j=0;
    for(i=0; i<biblioteca->tamanho; i++){
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i],titulo)){
            achou=1;
            ApagaLivro(biblioteca->livros[i]);
            for(j=i; j<biblioteca->tamanho-1; j++){
                biblioteca->livros[j] = biblioteca->livros[j+1]; //movendo os itens uma posicao pra tras
            }
            biblioteca->tamanho--; //diminuindo a qtd de livros
            biblioteca->livros[biblioteca->tamanho] = NULL; //deixando o ultimo ponteiro da lista como NULL
            printf("Livro removido com sucesso!\n"); 
            break;
        }
    }
    for(i=biblioteca->tamanho; i<biblioteca->tam_max_atual; i++){
        free(biblioteca->livros[i]);
    }
    if(achou == 0){
        printf("Livro nao encontrado na biblioteca.\n");
    }
}

int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    return strcmp(titulo, livro->titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    int i=0;
    if(biblioteca->tamanho <=0){
        printf("A biblioteca esta vazia!\n");
    }else{
        printf("\nLista de Livros na Biblioteca:\n");
        for(i=0; i<biblioteca->tamanho; i++){
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}