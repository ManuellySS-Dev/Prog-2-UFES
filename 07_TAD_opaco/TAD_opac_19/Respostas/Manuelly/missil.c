#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "missil.h"
#include "cidade.h"
#include "defesa.h"

struct missil{
    char id[5];
    float x, y, poder, dano_causado;
};

tMissil LeMissil(){
    tMissil missil = (tMissil) calloc(1, sizeof(struct missil));
    scanf(" %[^ ] ", missil->id);
    scanf(" %f", &missil->x);
    scanf(" %f", &missil->y);
    scanf(" %f\n", &missil->poder);
    return missil;
}

void ImprimeMissil(tMissil missil){
    printf("M-%s: %.2f\n", missil->id, missil->poder);
}

void LiberaMissil(tMissil missil){
    free(missil);
}

float GetMissilY(tMissil missil){
    return missil->y;
}

float GetMissilX(tMissil missil){
    return missil->x;
}

float GetMissilPoder(tMissil missil){
    return missil->poder;
}

void ReduzPoder(tMissil missil, float valor){
    missil->poder -= valor;
    if(missil->poder <0){
        missil->poder =0;
    }
}