#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int TrocaInterios(int * n1, int * n2){
    int p;
    if(*n1 > *n2){
        p = *n1;
        *n1 = *n2;
        *n2 = p;
        return 1;
    }else if(*n1 <= *n2){
        return 0;
    }
}