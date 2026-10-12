#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include "livro.h"
tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;
    biblioteca.tamanho=0;
    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho <MAX_LIVROS){
    biblioteca.livros[biblioteca.tamanho] = livro;
    biblioteca.tamanho++;
    printf("Livro adicionado com sucesso!\n");
    }else{
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int i=0, j=0;
    tLivros aux;
    for(i=0; i<biblioteca.tamanho; i++){
        if(!verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)){
            for(j=i; j<biblioteca.tamanho-1; j++){
                aux = biblioteca.livros[j+1];
                biblioteca.livros[j] = aux;
            }
            biblioteca.tamanho--;
            printf("Livro removido com sucesso!\n");
            return biblioteca;
        }
    }
    printf("Livro nao encontrado na biblioteca.\n");
    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return (strcmp(livro.titulo, titulo));
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    int i=0;

    if(biblioteca.tamanho <1){
        printf("A biblioteca esta vazia!\n");
    }else{
    printf("\nLista de Livros na Biblioteca:\n");
    for(i=0; i<biblioteca.tamanho; i++){
        imprimeLivro(biblioteca.livros[i]);
    }
    }
}