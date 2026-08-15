#include <stdio.h>
//Modularizar melhorrrrrrrrrrrrrrrrrr
typedef struct {
    int identificador;
}tLivro;

void OrdenaListaEmOrdemCrescente(int lista[], int n){
    int auxiliar=0, j=0, i=0;
    for(i=0; i<n;i++){
        for(j=0; j<n; j++){
            if(lista[j] > lista[i]){
                auxiliar = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliar;
            }
        }
    }
}

int main(){
    int qtd_livros=0, i=0, j=0, tem_copia=0, tem_nenhum=0, n=0;
    scanf("%d\n", &qtd_livros);
    tLivro livro[qtd_livros];
    int lista[qtd_livros];
    for(i=0; i<qtd_livros; i++){
        scanf("%d ", &livro[i].identificador);
    }

    for(i=0; i<qtd_livros; i++){
        for(j=0; j<qtd_livros; j++){
            if(j != i){
            if(livro[i].identificador == livro[j].identificador){
                tem_copia = 1;
                break;
            }else{
                tem_copia = 0;
            }
        }
        }
        if(tem_copia == 0){
            tem_nenhum =1;
            lista[n] = livro[i].identificador;
            n++;
        }
    }

    OrdenaListaEmOrdemCrescente(lista, n);
    for(i=0; i<n; i++){
            if(i>0){
            printf(" %d", lista[i]);
            }else{
            printf("%d", lista[i]);
            }
    }

    if(tem_nenhum ==0){
        printf("NENHUM");
    }
    return 0;
}