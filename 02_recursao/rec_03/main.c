#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){

    numElementos--;
    if(numElementos < 0){
        return 0;
    }
    if(vet[numElementos] == numeroProcurado){
        return ContaOcorrencias(vet, numElementos, numeroProcurado) + 1;
    }else{
        return ContaOcorrencias(vet, numElementos, numeroProcurado);
    }

}

int main(){
    int i=0, j=0, qtd_vetores=0, qtd_elementos=0, numero_a_ser_achado=0;

    scanf("%d\n", &qtd_vetores);

    for(i=0; i<qtd_vetores; i++){
        scanf("%d %d\n", &numero_a_ser_achado, &qtd_elementos);
        int vetor[qtd_elementos];
        for(j=0; j<qtd_elementos; j++){
            scanf("%d ", &vetor[j]);
        }
        scanf("\n");
        printf("%d\n", ContaOcorrencias(vetor, qtd_elementos, numero_a_ser_achado));
    }
return 0;
}