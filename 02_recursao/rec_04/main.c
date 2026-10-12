#include <stdio.h>
#include <string.h>
/*Codigo que testa se uma palavra eh palindromo ou nao*/
int palindromo(char *string, int tamanho);

int palindromo(char *string, int tamanho){
    int indice_caracter_mais_a_esquerda_sendo_testado=0, tamanho_total_da_palavra=0, indice_caracter_mais_a_direita_testado=0;

    tamanho_total_da_palavra = strlen(string);
    indice_caracter_mais_a_esquerda_sendo_testado = tamanho_total_da_palavra - tamanho;
    tamanho--;
    indice_caracter_mais_a_direita_testado = tamanho;

    if(indice_caracter_mais_a_esquerda_sendo_testado == indice_caracter_mais_a_direita_testado || (indice_caracter_mais_a_direita_testado-indice_caracter_mais_a_esquerda_sendo_testado < 1)){ 
        //quando chega no meio da palavra sem ter tido nenhuma diferenca a recursao jah pode parar pq eh palindromo
        return 1;
    }

    if(string[indice_caracter_mais_a_direita_testado] == string[indice_caracter_mais_a_esquerda_sendo_testado]){
        return palindromo(string, tamanho);
        //se as letras forem iguais a gente repete o laco pra testar o proximo par
    }else{
        return 0;
        //se tiver letras diferentes jah pode parar porque nao eh palindromo
    }
}

int main(){
    char string[500];
    int tamanho=0;

    while(scanf("%s", string) ==1){
        tamanho = strlen(string);
        if(palindromo(string, tamanho)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }
    return 0;
}