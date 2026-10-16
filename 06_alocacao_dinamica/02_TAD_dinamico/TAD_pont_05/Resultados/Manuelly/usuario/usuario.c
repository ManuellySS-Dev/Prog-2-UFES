#include "conta.h"
#include "usuario.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tUsuario *CriaUsuario(){
    tUsuario * usuario = (tUsuario*) calloc (1, sizeof(tUsuario));
    if(usuario == NULL){
        exit(0);
    }
    return usuario;
}

void DestroiUsuario(tUsuario *user){
    free(user);
}

void LeUsuario(tUsuario *user){
    scanf(" %[^ ] ", user->nome);
    scanf(" %[^ ] ", user->cpf);
}

void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}