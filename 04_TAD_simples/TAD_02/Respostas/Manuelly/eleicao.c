#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"
#include "candidato.h"
#include "eleicao.h"

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    tCandidato candidato;
    int qtd_candidatos = 0, i=0;
    scanf("%d\n", &qtd_candidatos);
    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosGovernador=0;
    eleicao.votosBrancosPresidente=0;
    eleicao.votosNulosGovernador=0;
    eleicao.votosNulosPresidente=0;
    eleicao.totalEleitores=0;
    for(i=0; i<qtd_candidatos; i++){
        candidato = LeCandidato();
        if(ObtemCargo(candidato) == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
        if(ObtemCargo(candidato) == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int i=0, qtd_eleitores=0, p=0, g=0, flag =0, j=0;
    tEleitor eleitor;
    scanf("%d\n", &qtd_eleitores);
    if(qtd_eleitores >10){
                printf("ELEICAO ANULADA\n");
                exit(0);
                }
    eleicao.totalEleitores = qtd_eleitores;
    for(i=0; i<qtd_eleitores; i++){

        eleitor = LeEleitor();
        for(j=0; j<i; j++){
            if(eleicao.eleitores[j].id == eleitor.id){
                printf("ELEICAO ANULADA\n");
                exit(0);
            } 
        }
        eleicao.eleitores[i] = eleitor;

        //presidente
        if(eleicao.eleitores[i].votoP == 0){
            eleicao.votosBrancosPresidente++;
        }else{
            for(p=0; p<eleicao.totalPresidentes; p++){
                //printf("%d %d\n\n", eleicao.presidentes[p].id, eleicao.eleitores[i].votoP);
                if(eleicao.presidentes[p].id == eleicao.eleitores[i].votoP){
                    eleicao.presidentes[p] = IncrementaVotoCandidato(eleicao.presidentes[p]);
                    flag =1;
                    break;
                }else{
                    flag=0;
                }
            }
            //se o voto nao for pra um candidato valido esse voto eh anulado
            if(flag ==0){
                eleicao.votosNulosPresidente++;
            }
        }
        //governador
        if(eleicao.eleitores[i].votoG == 0){
            eleicao.votosBrancosGovernador++;
        }else{
            for(g=0; g<eleicao.totalGovernadores; g++){
                if(eleicao.governadores[g].id == eleicao.eleitores[i].votoG){
                    eleicao.governadores[g] = IncrementaVotoCandidato(eleicao.governadores[g]);
                    flag =1;
                    break;
                }else{
                    flag=0;
                }
            }
            //se o voto nao for pra um candidato valido esse voto eh anulado
            if(flag ==0){
                eleicao.votosNulosGovernador++;
            }
        }
    }
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    //apuracao de presidente
    int presidente_vencedor =0, i=0, maior = -300, total_votos_p=0, empate=0;
    total_votos_p = eleicao.totalEleitores;
    
    for(i=0; i<eleicao.totalPresidentes; i++){
        if(eleicao.presidentes[i].votos > maior){
            presidente_vencedor = i;
            maior = eleicao.presidentes[i].votos;
        }
    }
    for(i=0; i<eleicao.totalPresidentes; i++){
        if(i != presidente_vencedor){
        if(eleicao.presidentes[i].votos == maior){
            empate =1;
        }
    }
    }
    if(eleicao.presidentes[presidente_vencedor].votos < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
            printf("- PRESIDENTE ELEITO: ");
            printf("SEM DECISAO\n");
    }else if(empate ==1){
            printf("- PRESIDENTE ELEITO: ");
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }else{
        printf("- PRESIDENTE ELEITO: ");
        ImprimeCandidato(eleicao.presidentes[presidente_vencedor], CalculaPercentualVotos(eleicao.presidentes[presidente_vencedor], total_votos_p));
    }
    //apuracao de governador (preciso terminar essa)
    int governador_vencedor =0, total_votos_g=0;
    total_votos_g = eleicao.totalEleitores;
    maior = -300; empate=0;
    for(i=0; i<eleicao.totalGovernadores; i++){
        if(eleicao.governadores[i].votos > maior){
            governador_vencedor = i;
            maior = eleicao.governadores[i].votos;
        }
    }
    for(i=0; i<eleicao.totalGovernadores; i++){
        if(i != governador_vencedor){
            if(eleicao.governadores[i].votos == maior){
                empate =1;
            }
        }
    }
    if(empate==1){
            printf("- GOVERNADOR ELEITO: ");
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }else if(eleicao.governadores[governador_vencedor].votos < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
            printf("- GOVERNADOR ELEITO: ");
            printf("SEM DECISAO\n");
    }else{
        printf("- GOVERNADOR ELEITO: ");
        ImprimeCandidato(eleicao.governadores[governador_vencedor], CalculaPercentualVotos(eleicao.governadores[governador_vencedor], total_votos_g));

    }
    //apuracao de votos nulos e brancos
        printf("- NULOS E BRANCOS: %d, %d", (eleicao.votosNulosGovernador+eleicao.votosNulosPresidente),(eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente));
    
}