#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ponto.h"
#include "circulo.h"

struct circulo{
    float raio;
    tPonto centro;
};

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo circulo = (tCirculo) calloc(1, sizeof(struct circulo));
    tPonto ponto;
    ponto = Pto_Cria(x,y);
    Circulo_Atribui_Centro(circulo, ponto);
    Circulo_Atribui_Raio(circulo, r);
    return circulo;
}

void Circulo_Apaga (tCirculo c){
    Pto_Apaga(c->centro);
    free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c){
    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    if(Pto_Distancia(p, c->centro) <= c->raio){
        return 1;
    }else{
        return 0;
    }
}