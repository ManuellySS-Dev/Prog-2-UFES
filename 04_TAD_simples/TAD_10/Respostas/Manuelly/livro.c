#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "biblioteca.h"

tLivros lerLivro(){
    char nome[100], autor[100];
    int ano=0;
    tLivros livro;
    scanf(" %[^\n]\n", nome);
    strcpy(livro.titulo, nome);
    scanf(" %[^\n]\n", autor);
    strcpy(livro.autor, autor);
    scanf("%d", &ano);
    livro.anoPublicacao = ano;
    return livro;
}

void imprimeLivro(tLivros livro){
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n\n", livro.anoPublicacao);
}