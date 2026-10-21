#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"

tBiblioteca* InicializarBiblioteca(){
    tBiblioteca * biblioteca = (tBiblioteca*) calloc(1, sizeof(tBiblioteca));
    if(biblioteca == NULL){
        exit(0);
    }
    //biblioteca->livros= (tLivros*) calloc(MAX_LIVROS, sizeof(tLivros));
    return biblioteca;
}

void ApagaBiblioteca(tBiblioteca* biblioteca){
    int i=0;
    for(i=0; i<biblioteca->tamanho; i++){
        ApagaLivro(biblioteca->livros[i]);
    }
    free(biblioteca);
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if(biblioteca->tamanho <10){
        biblioteca->livros[biblioteca->tamanho] = livro;
        biblioteca->tamanho++;
        printf("Livro adicionado com sucesso!\n");
    }else{
        ApagaLivro(livro);
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    int achou=0, i=0, j=0;
    for(i=0; i<biblioteca->tamanho; i++){
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i],titulo)){
            achou=1;
            ApagaLivro(biblioteca->livros[i]);
            for(j=i; j<biblioteca->tamanho-1; j++){
                biblioteca->livros[j] = biblioteca->livros[j+1];
            }
            biblioteca->tamanho--;
            printf("Livro removido com sucesso!\n");
            break;
        }
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