#include "conta.h"
#include "usuario.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char operacao = '\0';
    tBanco * banco;

    banco = CriaBanco();

    while(1){
        scanf(" %c", &operacao);
        if(operacao == 'A'){
            AbreContaBanco(banco);
        }else if(operacao == 'S'){
            SaqueContaBanco(banco);
        }else if(operacao == 'T'){
            TransferenciaContaBanco(banco);
        }else if(operacao == 'D'){
            DepositoContaBanco(banco);
        }else if(operacao == 'F'){
            break;
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return 0;
}