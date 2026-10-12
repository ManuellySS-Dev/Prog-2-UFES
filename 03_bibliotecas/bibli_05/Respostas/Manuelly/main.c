#include <stdio.h>
#include "string_utils.h"
//Tenho que consertar com base nos casos da main eu fiz os prints no string utils mas nao era pra ser assim
int main(){
    int opcao_escolhida=0, tamanho_da_str=0;
    char str[100], dest[100];
    scanf("%99[^\n]", str);
    scanf("\n");
    while(opcao_escolhida != 6){
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d\n", &opcao_escolhida);

        if(opcao_escolhida == 1){
            tamanho_da_str = string_length(str);
            printf("Tamanho da string: %d\n", tamanho_da_str);
        }else if(opcao_escolhida == 2){
            string_copy(str, dest);
            printf("String copiada: %s\n", dest);
        }else if(opcao_escolhida == 3){
            string_upper(str);
            printf("String convertida para maiusculas: %s\n", str);
        }else if(opcao_escolhida == 4){
            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);
        }else if(opcao_escolhida == 5){
            string_reverse(str);
            printf("String invertida: %s\n", str);
        }
            printf("\n");
    }
    return 0;
}