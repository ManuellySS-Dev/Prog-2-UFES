#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario usuario;
    strcpy(usuario.nome, nome);
    strcpy(usuario.cpf, cpf);
    return usuario;
}

void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}