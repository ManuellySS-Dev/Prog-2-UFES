#include "string_utils.h"

int string_length(char *str){
    int tamanho = 0;
    while(str[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

void string_copy(char *src, char *dest){
    int tamanho = 0;
    while(src[tamanho] != '\0'){
        dest[tamanho] = src[tamanho];
        tamanho++;
    }
    dest[tamanho] = '\0';
}

void string_upper(char *str){
    int tamanho = 0;
    while(str[tamanho] != '\0'){
        if(str[tamanho] >= 'a' && str[tamanho] <= 'z'){
            str[tamanho] = str[tamanho] - 32;
        }
        tamanho++;
    }
}

void string_lower(char *str){
    int tamanho = 0;
    while(str[tamanho] != '\0'){
        if(str[tamanho] >= 'A' && str[tamanho] <= 'Z'){
            str[tamanho] = str[tamanho] + 32;
        }
        tamanho++;
    }  
}

void string_reverse(char *str){
    int tamanho=0, i=0, j=0;
    char copy_string[100];

    tamanho = string_length(str);
    for(i=(tamanho-1); i>=0; i--){
        copy_string[j] = str[i];
        j++;
    }
    copy_string[j] = '\0'; //adicionando fim pra na hora de copiar a condicao do while ter fim 
    string_copy(copy_string, str);
}