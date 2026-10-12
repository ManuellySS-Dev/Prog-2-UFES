#include <stdio.h>
#include "ponto.h"

int main(){
    Ponto ponto1, ponto2;
    float x1=0, x2=0, y1=0, y2=0;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    ponto1 = pto_cria(x1,y1);
    ponto2 = pto_cria(x2,y2);

    printf("%g", pto_distancia(ponto1, ponto2));
    return 0;
}
