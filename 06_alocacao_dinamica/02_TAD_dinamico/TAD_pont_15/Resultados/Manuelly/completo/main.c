#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

int main(){
    tDracomania dracomania;
    dracomania = CriaDracomania();
    dracomania = RodaDracomania(dracomania);
    ImprimeRelatorioDracomania(dracomania);
    LiberaDracomania(dracomania);
    return 0;
}