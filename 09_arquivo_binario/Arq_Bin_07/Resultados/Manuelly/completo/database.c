#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"
#include "professor.h"
#include "database.h"

struct Database{
    Vector * professores;
    Vector * alunos;
    int qtd_alunos, qtd_professores;
};

tDatabase *CriaDatabase(){
    tDatabase * db = (tDatabase*) calloc(1, sizeof(tDatabase));
    db->professores = VectorConstruct();
    db->alunos = VectorConstruct();
    return db;
}

void DestroiAlunoGenerico(DataType dado){
    tAluno * aluno = (tAluno*) dado;
    DestroiAluno(aluno);
}

void DestroiProfessorGenerico(DataType dado){
    tProfessor * prof = (tProfessor*) dado;
    DestroiProfessor(prof);
}

void DestroiDatabase(tDatabase *db){
    VectorDestroy(db->professores, DestroiProfessorGenerico);
    VectorDestroy(db->alunos, DestroiAlunoGenerico);
    free(db);
}

void LeDatabase(tDatabase *db){

    scanf("%d\n", &db->qtd_alunos);

    for(int i=0; i<db->qtd_alunos; i++){
        VectorPushBack(db->alunos, LeAluno());
    }

    scanf("%d\n", &db->qtd_professores);

    for(int i=0; i<db->qtd_professores; i++){
        VectorPushBack(db->professores, LeProfessor());
    }
}

void OrdenaDatabase(tDatabase *db){

    for(int i=0; i<db->qtd_alunos-1; i++){
        for(int j=0; j<db->qtd_alunos-i-1; j++){
            if(ComparaNomeAluno(VectorGet(db->alunos, j),VectorGet(db->alunos, j+1))>0){
                VectorSwap(db->alunos, j+1, j);
            }
        }
    }

    for(int i=0; i<db->qtd_professores-1; i++){
        for(int j=0; j<db->qtd_professores-i-1; j++){
            if(ComparaNomeProfessor(VectorGet(db->professores, j),VectorGet(db->professores, j+1))>0){
                VectorSwap(db->professores, j+1, j);
            }
        }
    }
}

int SalvarDatabase(tDatabase *db, FILE *file){
    int n_bytes=0;
    OrdenaDatabase(db);
    n_bytes+=fwrite(&db->qtd_alunos, sizeof(int), 1, file);

    for(int i=0; i<db->qtd_alunos; i++){
        n_bytes += SalvaAluno(VectorGet(db->alunos, i), file);
    }
    n_bytes+=fwrite(&db->qtd_professores, sizeof(int), 1, file);

    for(int i=0; i<db->qtd_professores; i++){
        n_bytes += SalvaProfessor(VectorGet(db->professores, i), file);
    }

    return n_bytes;

    }

int CarregaDatabase(tDatabase *db, FILE *file){
int n_bytes = 0;

    fread(&db->qtd_alunos, sizeof(int), 1, file) * sizeof(int);
    for(int i = 0; i < db->qtd_alunos; i++){
        tAluno *aluno = CriaAluno("", "", "", 0.00, 0.00);
        VectorPushBack(db->alunos, aluno);
        n_bytes += CarregaAluno(aluno, file);
    }

    n_bytes += fread(&db->qtd_professores, sizeof(int), 1, file) * sizeof(int) /2;
    for(int i = 0; i < db->qtd_professores; i++){
        tProfessor *prof = CriaProfessor("", "", ""); //cria um ponteiro com vazio pra poder adicionar no vetor
        VectorPushBack(db->professores, prof); //adiciona o ponteiro no vetor
        n_bytes += CarregaProfessor(prof, file);//le as informacoes do ponteiro a partir do arquivo file
    }
    OrdenaDatabase(db);

    return n_bytes;
}

void ImprimeDatabase(tDatabase *db){
    OrdenaDatabase(db);

    printf("Alunos:\n");
    for(int i=0; i<db->qtd_alunos; i++){
        ImprimeNomeAluno(VectorGet(db->alunos, i));
    }

    printf("\nProfessores:\n");
    for(int i=0; i<db->qtd_professores; i++){
        ImprimeNomeProfessor(VectorGet(db->professores, i));
    }
}

