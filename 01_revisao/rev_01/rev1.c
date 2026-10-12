//Codigo que calcula se dois tiros colidiram -- revisao de conceitos de prog 
#include <math.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
    float r;
} tTiro;

tTiro RecebeDados(){
    tTiro tiro;
    scanf("%f %f %f\n", &tiro.x, &tiro.y, &tiro.r);
    return tiro;
}

int CalculaDistanciaEntreOsCentros(tTiro tiro1,tTiro tiro2){
    //Calculo por pitagoras a distancia entre os centros do circulo considerando um triango 
    //um dos catetos eh a diferenca de x de um com x de outro e o outro a mesma coisa soh que com o y
    //eu tambem tiro o modulo e depois aplico a formula de pitagoras pra encontrar a distancia entre os centros de cada tiro
    float distancia_ao_quadrado=0, distancia=0, cateto2=0, cateto1=0;
    cateto1 = (tiro1.x - tiro2.x);
    if(cateto1 <0){
        cateto1 = (cateto1 * -1);
    }
    cateto2 = (tiro1.y - tiro2.y);
    if(cateto2 <0){
        cateto2 = (cateto2 * -1);
    }

    distancia_ao_quadrado = (cateto1 * cateto1) + (cateto2*cateto2);
    distancia = sqrt(distancia_ao_quadrado);
    return distancia;
}

int main (){
    tTiro tiro1, tiro2;
    float distancia=0;

    tiro1 = RecebeDados();
    tiro2 = RecebeDados();

    distancia = CalculaDistanciaEntreOsCentros(tiro1, tiro2);

    //se a distancia, do centro de um tiro ateh o outro eh maior que a soma entre o raio de um tiro e do outro entao eles nao colidiram
    //se a distancia eh menor siginifica que colodiram
    if(distancia <= (tiro1.r + tiro2.r)){
        printf("ACERTOU");    
    }else{
        printf("ERROU");  
    }
return 0;
}