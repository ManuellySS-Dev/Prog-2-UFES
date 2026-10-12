#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

int main(){
    int qtd_contas=0, num_contas=0, operacao=0, numero_da_conta=0,i=0;
    float valor=0;
    char cpf[30], nome[200];

    scanf("%d", &qtd_contas);
    tConta conta[qtd_contas];
    tUsuario usuario;

    while(1){
        scanf("%d\n", &operacao);
        if(operacao == 1){
            scanf("%d %f\n", &numero_da_conta, &valor);
            for(i=0; i<num_contas; i++){
                if(VerificaConta(conta[i], numero_da_conta)){
                    break;
                }
            }
            conta[i] = SaqueConta(conta[i], valor);

        }else if(operacao == 2){
            scanf("%d %f\n", &numero_da_conta, &valor);
            for(i=0; i<num_contas; i++){
                if(VerificaConta(conta[i], numero_da_conta)){
                    break;
                }
            }
            conta[i] = DepositoConta(conta[i],valor);
        }else if(operacao == 3){
            scanf(" %[^ ] %[^ ] %d", nome, cpf,&numero_da_conta);
            usuario = CriaUsuario(nome,cpf);
            conta[num_contas] = CriaConta(numero_da_conta, usuario);
            num_contas++;
        }else if(operacao == 4){
            printf("===| Imprimindo Relatorio |===\n");
            for(i=0; i<num_contas; i++){
                ImprimeConta(conta[i]);
            }
        }

        if(operacao ==0){
            break;
        }
    }
return 0;
}