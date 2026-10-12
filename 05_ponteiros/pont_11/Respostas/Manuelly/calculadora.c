#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

typedef float (*CalculatoraCallback)(float, float);

float Calcular(float num1, float num2, CalculatoraCallback operacao){
    return operacao(num1,num2);
}