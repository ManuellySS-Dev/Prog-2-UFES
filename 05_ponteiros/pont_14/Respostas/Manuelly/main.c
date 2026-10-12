#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "botao.h"
#include "tela.h"

void Salvar(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void Excluir(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void Opcoes(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    Tela t;

    Botao b_salvar, b_excluir, b_opcoes;
    t = CriarTela(200,400);
    b_salvar = CriarBotao("Salvar", 12,"FFF", 1, Salvar);
    RegistraBotaoTela(&t, b_salvar);
    b_excluir = CriarBotao("Excluir", 18, "000", 1, Excluir);
    RegistraBotaoTela(&t, b_excluir);
    b_opcoes = CriarBotao("Opcoes",  10, "FF0000", 2, Opcoes);
    RegistraBotaoTela(&t, b_opcoes);

    DesenhaTela(t);

    OuvidorEventosTela(t);
    
    return 0;
}