#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Codigo que recebe uma frase contendo varias strings e imprime a fraze com as strings invertidas usando o conceito de recursao*/
void ImprimeInvertido(char* string);
void LeString();

void ImprimeInvertido(char* string){
    int i = 0;
    i = (strlen(string) - 1);
    while(i >= 0){
        printf("%c", string[i]);
        i--;
    }
    printf(" ");
}

void LeString(){
    char caracter = '\0', palavra[1000];
    int i = 0;

    while(1){
        if((scanf("%c", &caracter)) == 1){
            if(caracter != ' '){
                palavra[i] = caracter;
            }else{
                break;
            }
        }else{
            palavra[i] = '\0';
            ImprimeInvertido(palavra);
            exit(0);
        }
        i++;
    }
    palavra[i] = '\0';
    ImprimeInvertido(palavra);
    LeString();
}

int main(){
    LeString();
return 0;
}