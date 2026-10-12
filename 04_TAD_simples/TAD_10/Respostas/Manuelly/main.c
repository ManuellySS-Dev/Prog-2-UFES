#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "biblioteca.h"

int main(){
    int i=0, n_operacoes=0, operacao=0;
    char titulo[100];
    tBiblioteca biblioteca;
    tLivros livro;
    biblioteca = inicializarBiblioteca();
    scanf("%d", &n_operacoes);
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    for(i=0; i<n_operacoes; i++){
        scanf(" %d\n", &operacao);
        if(operacao ==1){
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }else if(operacao == 2){
            scanf(" %[^\n]\n", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }else if(operacao ==3){
            listarLivrosDaBiblioteca(biblioteca);
        }else{
            printf("Operacao invalida!\n");
            break;
        }
    }


    return 0;
}