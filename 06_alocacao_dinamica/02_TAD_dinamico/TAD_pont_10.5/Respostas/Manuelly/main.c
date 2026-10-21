#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"

int main(){
    int qtd_op=0, i=0, operacao=0;
    char titulo[100];
    tBiblioteca * biblioteca;
    biblioteca = InicializarBiblioteca();

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");

    scanf("%d", &qtd_op);

    for(i=0; i<qtd_op; i++){

        scanf("%d", &operacao);

        if(operacao == 1){
            tLivros * livro;
            livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);
        }else if(operacao == 2){
            scanf(" %[^\n]\n", titulo);
            RemoverLivroDaBiblioteca(biblioteca, titulo);
        }else if(operacao == 3){
            ListarLivrosDaBiblioteca(biblioteca);
        }else{
            printf("Operacao invalida!\n");
            break;
        }
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}