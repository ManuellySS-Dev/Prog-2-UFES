#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ponto.h"
#include "circulo.h"

int main(){
    tPonto ponto;
    tCirculo circulo;
    float x=0, y=0, r=0;
    scanf("%f %f %f ", &x,&y, &r);
    circulo = Circulo_Cria(x,y,r);
    scanf("%f %f", &x,&y);
    ponto = Pto_Cria(x,y);
    if(Circulo_Interior(circulo, ponto)){
        printf("1");
    }else{
        printf("0");
    }
    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);
    return 0;
}
