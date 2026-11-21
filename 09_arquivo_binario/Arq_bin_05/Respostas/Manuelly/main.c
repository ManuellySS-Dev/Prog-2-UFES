#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "produto.h"
#include "estabelecimento.h"

int main(){
    tEstabelecimento * estab;

    estab = CriaEstabelecimento();
    LeEstabelecimento(estab);
    ImprimeProdutosEmFaltaEstabelecimento(estab);
    DestroiEstabelecimento(estab);
    
    return 0;
}
