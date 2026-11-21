#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"


int main(){
    tDatabase * data;
    int n_bytes=0;
    
    char caminho[50];

    data = CriaDatabase();

    LeDatabase(data);

    scanf(" %[^\n]\n", caminho);
    FILE * data_arq = fopen(caminho, "wb");
    n_bytes = SalvarDatabase(data, data_arq);
    printf("Numero de bytes salvos: %d\n", n_bytes);

    fclose(data_arq);

    printf("Numero de bytes lidos: %d\n\n", n_bytes);
    
    OrdenaDatabase(data);

    ImprimeDatabase(data);

    DestroiDatabase(data);
    return 0;
}