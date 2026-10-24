#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "franquia.h"
#include "nba.h"
#include "partida.h"

int main(){
    tNBA nba;
    nba = CriaNBA();
    nba = RodaNBA(nba);
    ImprimeRelatorioNBA(nba);
    LiberaNBA(nba);
    return 0;
}