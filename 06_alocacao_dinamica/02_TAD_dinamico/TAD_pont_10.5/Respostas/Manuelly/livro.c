#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"

tLivros* CriaLivro(){
    tLivros * livro = (tLivros*) calloc(1, sizeof(tLivros));
    if(livro == NULL){
        printf("Nao foi possivel alocar memoria para livro");
        exit(0);
    }
    livro->titulo =  (char*) calloc(100, sizeof(char));
    livro->autor =  (char*) calloc(100, sizeof(char));
    return livro;
}

void LerLivro(tLivros* livro){
    scanf(" %[^\n]\n", livro->titulo);
    scanf(" %[^\n]\n", livro->autor);
    scanf("%d", &livro->anoPublicacao);
}

void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\n\n", livro->titulo, livro->autor, livro->anoPublicacao);
}

void ApagaLivro(tLivros* livro){
    free(livro->titulo);
    free(livro->autor);
    free(livro);
}