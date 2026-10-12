#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
float soma(float a, float b){
    return a+b;
}
float s(float a, float b){
    return a-b;
}
float m(float a, float b){
    return a*b;
}
float d(float a, float b){
    return a/b;
}
int main(){
    char op='\0';
    float a=0,b=0;
    while(scanf(" %c\n", &op)==1){
        scanf("%f %f", &a, &b);
        if (op == 'a') {
            printf("%.2f + %.2f = %.2f\n", a, b, Calcular(a, b, soma));
        } else if (op == 's') {
            printf("%.2f - %.2f = %.2f\n", a, b, Calcular(a, b, s));
        } else if (op == 'm') {
            printf("%.2f x %.2f = %.2f\n", a, b, Calcular(a, b, m));
        } else if (op == 'd') {
            printf("%.2f / %.2f = %.2f\n", a, b, Calcular(a, b, d));
        }
        if(op == 'f'){
            exit(0);
        }
    }

    return 0;
}