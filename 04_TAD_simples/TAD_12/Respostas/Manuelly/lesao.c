#include "data.h"
#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"

Lesao criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade){
    Lesao lesao;
    strcpy(lesao.cartaoSus,cartaoSus); 
    strcpy(lesao.id, id); 
    strcpy(lesao.diagnostico,diagnostico); 
    strcpy(lesao.regiao,regiao); 
    lesao.malignidade = malignidade;
    return lesao; 
}


Lesao lerLesao(){
    Lesao lesao;
    int malignidade=0;
    char cartao[MAX_CARTAO_LES], id[MAX_ID_LES], diagonostico[MAX_DIAG_LES], regiao[MAX_REG_LES];
    scanf("%[^\n]\n", cartao);
    scanf("%[^\n]\n", id);
    scanf("%[^\n]\n", diagonostico);
    scanf("%[^\n]\n", regiao);
    scanf("%d\n", &malignidade);
    lesao = criaLesao(cartao,id,diagonostico,regiao,malignidade);
    return lesao;
}


void getCartaoSusLesao(Lesao l, char *cartaoSus){
    strcpy(cartaoSus, l.cartaoSus);
}

int verificaCirurgicaLesao(Lesao l){
    if(l.malignidade >50){
        return 1;
    }
    return 0;
}

void imprimeIdLesao(Lesao l){
    printf("%s\n", &l.id);
}