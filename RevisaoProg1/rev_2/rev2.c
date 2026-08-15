#include <stdio.h>
/*Codigo que imprime o triangulo de Floyd recebendo do usuario quantas linhas o triangulo deve conter*/

void ImprimeTriangulo(int n){
    int i=0, numero_impresso=0, linha =1;

    while (linha <=n){
        for(i=0; i < linha; i++){
            numero_impresso++;
            printf("%d ", numero_impresso);
        }
        printf("\n");
        linha++;
    }
}

int main(){
    int n=0;
    scanf("%d", &n);
    ImprimeTriangulo(n);
return 0;
}