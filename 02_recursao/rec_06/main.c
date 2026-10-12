#include <stdio.h>

int fibonacci(int n);

int fibonacci(int n){
    if(n == 0){ //primeiro numero da sequencia eh 0 (quando chegar aqui a recursao para e volta entregando os resultados de cada chamada a partir desses primeiros valores)
        return 0;
    }
    if(n==1){ //o segundo valor ou posicao 1 eh igual a 1 (quando chega aqui a posicao n=1 ganha um valor que vai ajudar na volta dos outros calculos)
        return 1;
    }
    if(n>1){ //quando se trata dos valores que nao sao fixos a recursao ocorre ateh chegar neles e depois volta levando resultado de chamada em chamada
        return fibonacci(n-2) + fibonacci(n-1); //o resultado atual eh a soma dos dois anteriores mais proximos (o penultimo e o antepenultimo)
        //se eu quero calcular o 3 fibonacci eu preciso saber o 1 e o 2, dai vou precisar saber o 0 e o 1 e ai a funcao poe os valores 1 e 0 pra esses n e depois vai voltando a recursao com resultados
    }
}

int main(){
    int n=0;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}