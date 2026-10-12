#include <stdio.h>
#include <stdlib.h>

int SomaElementosPares(int* vet, int numElementos);

int SomaElementosPares(int* vet, int numElementos){

    numElementos--;

    if(numElementos < 0){
        return 0; // Quando acabam os numeros pra somar a ultima chamada retorna 0 porque nao faz diferenca na soma
    }

    if(vet[numElementos] % 2 == 0){
        return vet[numElementos] + SomaElementosPares(vet, numElementos); //recursao vai retornar pra chamada anterior o valor somado e o return da proximah
    }else{
        return SomaElementosPares(vet, numElementos); //se o elemento for impar o retorno eh soh chamar a funcao sem somar nenhum elemento
    }
}


int main(){
    int qtd_vetores = 0, qtd_elementos=0, i=0, j=0;

    scanf("%d\n", &qtd_vetores);

    for(i=0; i<qtd_vetores; i++){
        scanf("%d\n", &qtd_elementos);
        int vetor[qtd_elementos];
        for(j=0; j<qtd_elementos; j++){
            scanf("%d ", &vetor[j]);
        }
        printf("%d\n", SomaElementosPares(vetor, qtd_elementos));
    }
    return 0;
}