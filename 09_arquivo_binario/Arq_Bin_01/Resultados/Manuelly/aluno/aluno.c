#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aluno.h"

struct aluno{
    char * nome;
    char * dtNasc;
    char * cursoUfes;
    char * periodoIngresso;
    int percConclusao;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno ** alunos = (Aluno**) calloc(numeroAlunos, sizeof(Aluno*));
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno * estudante = (Aluno*) calloc(1, sizeof(Aluno));
    estudante->nome = (char*) calloc(100, sizeof(char));
    estudante->dtNasc = (char*) calloc(100, sizeof(char));
    estudante->cursoUfes = (char*) calloc(100, sizeof(char));
    estudante->periodoIngresso = (char*) calloc(100, sizeof(char));

    strcpy(estudante->nome, nome);
    strcpy(estudante->dtNasc, dtNasc);
    strcpy(estudante->cursoUfes, cursoUfes);
    strcpy(estudante->periodoIngresso, periodoIngresso);
    estudante->percConclusao = percConclusao;
    estudante->CRA = CRA;

    return estudante;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[100];
    char dtNasc[100];
    char cursoUfes[100];
    char periodoIngresso[100];
    int percConclusao=0;
    float CRA=0;

    for(int i=0; i<numeroAlunos; i++){
        scanf(" %[^\n]\n", nome);
        scanf(" %[^\n]\n", dtNasc);
        scanf(" %[^\n]\n", cursoUfes);
        scanf(" %[^\n]\n", periodoIngresso);
        scanf(" %d", &percConclusao);
        scanf(" %f", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i=0; i<numeroAlunos; i++){
        free(alunos[i]->nome);
        free(alunos[i]->dtNasc);
        free(alunos[i]->cursoUfes);
        free(alunos[i]->periodoIngresso);
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE *file = fopen(fileName, "wb"); // "wb" = write binary
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fwrite(&numeroAlunos, sizeof(int), 1, file);

    for(int i = 0; i < numeroAlunos; i++) {
        int tam;

        tam = strlen(alunos[i]->nome);
        fwrite(&tam, sizeof(int), 1, file);
        fwrite(alunos[i]->nome, sizeof(char), tam, file);

        tam = strlen(alunos[i]->dtNasc);
        fwrite(&tam, sizeof(int), 1, file);
        fwrite(alunos[i]->dtNasc, sizeof(char), tam, file);

        tam = strlen(alunos[i]->cursoUfes);
        fwrite(&tam, sizeof(int), 1, file);
        fwrite(alunos[i]->cursoUfes, sizeof(char), tam, file);

        tam = strlen(alunos[i]->periodoIngresso);
        fwrite(&tam, sizeof(int), 1, file);
        fwrite(alunos[i]->periodoIngresso, sizeof(char), tam, file);

        fwrite(&alunos[i]->percConclusao, sizeof(int), 1, file);
        fwrite(&alunos[i]->CRA, sizeof(float), 1, file);
    }

    fseek(file, 0, SEEK_END); //move o cursos do leitor do arquivo binario para o final do arquivo
    long bytesSalvos = ftell(file); //retorna o tamanho do arquivo
    printf("Numero de bytes salvos: %ld\n", bytesSalvos);
    fclose(file);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
FILE *file = fopen(fileName, "rb"); 
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    int numeroAlunos;
    fread(&numeroAlunos, sizeof(int), 1, file);

    for(int i = 0; i < numeroAlunos; i++) {
        int tam;

        // 1. Lê o nome
        fread(&tam, sizeof(int), 1, file);
        char *nome = (char*) malloc((tam + 1) * sizeof(char)); // +1 para o '\0'
        fread(nome, sizeof(char), tam, file);
        nome[tam] = '\0';

        // 2. Lê a data de nascimento
        fread(&tam, sizeof(int), 1, file);
        char *dtNasc = (char*) malloc((tam + 1) * sizeof(char));
        fread(dtNasc, sizeof(char), tam, file);
        dtNasc[tam] = '\0';

        // 3. Lê o curso
        fread(&tam, sizeof(int), 1, file);
        char *cursoUfes = (char*) malloc((tam + 1) * sizeof(char));
        fread(cursoUfes, sizeof(char), tam, file);
        cursoUfes[tam] = '\0';

        // 4. Lê o período de ingresso
        fread(&tam, sizeof(int), 1, file);
        char *periodoIngresso = (char*) malloc((tam + 1) * sizeof(char));
        fread(periodoIngresso, sizeof(char), tam, file);
        periodoIngresso[tam] = '\0';

        // 5. Lê os dados numéricos
        int percConclusao;
        float CRA;
        fread(&percConclusao, sizeof(int), 1, file);
        fread(&CRA, sizeof(float), 1, file);

        // --- EM VEZ DE CHAMAR CriaAluno (que usa strcpy e causa o erro), ---
        // --- alocamos o aluno diretamente e atribuímos os ponteiros: ---
        
        alunos[i] = (Aluno*) malloc(sizeof(Aluno));
        alunos[i]->nome = nome;             // Já está alocado e com '\0'
        alunos[i]->dtNasc = dtNasc;         // Já está alocado e com '\0'
        alunos[i]->cursoUfes = cursoUfes;   // Já está alocado e com '\0'
        alunos[i]->periodoIngresso = periodoIngresso; // Já está alocado e com '\0'
        alunos[i]->percConclusao = percConclusao;
        alunos[i]->CRA = CRA;
    }

    fclose(file);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i=0; i<numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percConclusao);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}