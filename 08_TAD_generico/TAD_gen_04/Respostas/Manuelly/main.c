#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

int main(){
    char operacao = '\0';
    int num=0;
    tBanco * banco;
    banco= CriaBanco();
    LeBanco(banco);

    while(scanf(" %c", &operacao)==1){
        if(operacao == 'A'){
            tAgencia * agencia;
            agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }else if(operacao == 'C'){
            tConta * conta = CriaConta();
            LeConta(conta);
            scanf(" %d\n", &num);
            InsereContaBanco(banco, num, conta);
        }else{
            break;
        }
    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);
    return 0;
}