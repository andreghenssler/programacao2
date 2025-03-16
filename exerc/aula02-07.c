#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h> 

#define MAX_ALUNOS 10
#define ARQUIVO "alunos.bin"

// Estrutura para armazenar informações de cada aluno
typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
    float media;
} Aluno;

Aluno adicionAluno(){
    Aluno a1;
    printf("Nome do Aluno");
    setbuf(stdin,NULL);
    getc(a1.nome);
    printf("Matricula do Aluno ");
}

// Função para adicionar um novo aluno à turma

// Função para listar todos os alunos cadastrados
void listarAlunos(Aluno turma[], int numAlunos) {
    printf("\nLista de Alunos:\n");

    if (numAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", turma[i].nome);
        setbuf(stdin,NULL);       

        printf("Matrícula: %d\n", turma[i].matricula);
        setbuf(stdin,NULL);       

        printf("Notas: %.2f, %.2f, %.2f\n", turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);
        printf("Média: %.2f\n", turma[i].media);
    }
}

// Função para salvar os dados da turma em um arquivo binário
void salvarDados(Aluno turma[], int numAlunos) {
    FILE *arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fwrite(turma, sizeof(Aluno), numAlunos, arquivo);

    fclose(arquivo);

    printf("Dados salvos com sucesso no arquivo '%s'.\n", ARQUIVO);
}

// Função principal
int main() {
    SetConsoleOutputCP(65001); // Ajuste para exibição correta de caracteres UTF-8 no Windows
    
    Aluno turma[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {
        printf("\n### MENU ###\n");
        printf("1. Adicionar novo aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Salvar dados em arquivo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(turma, &numAlunos);
                break;
            case 2:
                listarAlunos(turma, numAlunos);
                break;
            case 3:
                salvarDados(turma, numAlunos);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
