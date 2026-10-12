#include <stdio.h>

int fatorial(int n);
int fatorial(int n){
    n--;
    if(n>0){
        return (n+1) * fatorial(n); //recursao
    }else{
        return 1; //se eu colocasse 0 ia multiplicar por 0 a ultima recursao
    }
}

int main(){
    int numero =0;
    scanf("%d", &numero);
    printf("%d\n",fatorial(numero));
}