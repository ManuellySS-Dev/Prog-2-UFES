#include <stdio.h>
#include <math.h>
/*Programa que soma os digitos de um numero inteiro positivo usando o conceito de recursao*/
int somaDigitos(int n){
    if(n<=0){
        return 0;
    }
    return n%10 + somaDigitos(n/10); 
    /*geralmente eu divido um numero por uma potencia de 10 especifica e depois tiro o resto da divisao por 10 pra pegar o algarismo mais a 
    direita desse numero e assim vou pegando os algarismos um a um, passei isso pra recursao apenas eliminando o while que geralmente uso
    dai a propria recursao jah faz as divisoes por 10 em cada chamada e tambem soma os restos da divisao desses n por 10 */
}

int main(){
    int numero=0;
    scanf("%d", &numero);
    printf("%d\n", somaDigitos(numero));

return 0;
}