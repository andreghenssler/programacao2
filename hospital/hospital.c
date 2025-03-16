#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h> 

int opcao;
int MAX_CONSULTAS = 50;
int MAX_PACIENTES = 100;

typedef struct {
    char data[11];
    char descricao[100];
} Consulta;

typedef struct {
    char nome[50];
    char dataNascimento[11];
    int contConsulta;
    bool ativo;
    Consulta consultas[50];
} Paciente;

Paciente pacientes[100]; // array de pacientes
int numPacientes = 0; // contador de pacientes cadastrados

// Função para incluir um novo paciente no sistema
void incluirPaciente() {
    if (numPacientes < 100) {
        Paciente novoPaciente;
        printf("Digite o nome do paciente: ");
        scanf(" %[^\n]", novoPaciente.nome);
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %s", novoPaciente.dataNascimento);
        novoPaciente.contConsulta = 0;
        novoPaciente.ativo = true;

        pacientes[numPacientes++] = novoPaciente;  // Adiciona o novo paciente ao array de pacientes
        printf("Paciente incluído com sucesso!\n");
    } else {
        printf("Não é possível adicionar mais pacientes. Limite máximo atingido.\n");
    }
}

// Função para alterar os dados de um paciente existente
void alterarPaciente(char *nome) {
    int i;
    for (i = 0; i < numPacientes; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0) { // Compara o nome fornecido com os nomes dos pacientes no sistema
            printf("Digite a nova data de nascimento para %s (DD/MM/AAAA): ", pacientes[i].nome);
            scanf(" %s", pacientes[i].dataNascimento); // Atualiza a data de nascimento do paciente encontrado
            printf("Paciente alterado com sucesso!\n");
            return;
        }
    }
    printf("Paciente não encontrado.\n");
}

// Função para realizar uma nova consulta para um paciente específico
void realizarConsulta(char *nome) {
    int i;
    for (i = 0; i < numPacientes; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0) { // Procura pelo paciente com o nome fornecido
            if (pacientes[i].contConsulta < 50) { // Verifica se o paciente ainda pode realizar mais consultas
                printf("Digite a data da consulta (DD/MM/AAAA): ");
                scanf(" %s", pacientes[i].consultas[pacientes[i].contConsulta].data); // Captura a data da consulta
                printf("Digite a descrição da consulta: ");
                scanf(" %[^\n]", pacientes[i].consultas[pacientes[i].contConsulta].descricao); // Captura a descrição da consulta
                pacientes[i].contConsulta++; // Incrementa o contador de consultas do paciente
                printf("Consulta registrada com sucesso para %s.\n", pacientes[i].nome);
            } else {
                printf("Limite de consultas alcançado para %s.\n", pacientes[i].nome);
            }
            return;
        }
    }
    printf("Paciente não encontrado.\n");
}

// Função para listar todos os pacientes ativos no sistema
void listarPacientes() {
    printf("Lista de Pacientes Ativos:\n");
    for (int i = 0; i < numPacientes; i++) {
        if (pacientes[i].ativo) {
            printf("- Nome: %s, Data de Nascimento: %s\n", pacientes[i].nome, pacientes[i].dataNascimento);
        }
    }
}
// Função para mostrar os detalhes de um paciente, incluindo suas consultas
void mostrarPaciente(char *nome) {
    int i;
    for (i = 0; i < numPacientes; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0) {
            printf("Nome: %s, Data de Nascimento: %s\n", pacientes[i].nome, pacientes[i].dataNascimento);
            printf("Consultas:\n");
            for (int j = 0; j < pacientes[i].contConsulta; j++) {
                printf("  %d. Data: %s, Descrição: %s\n", j + 1, pacientes[i].consultas[j].data, pacientes[i].consultas[j].descricao);
            }
            return;
        }
    }
    printf("Paciente não encontrado.\n");
}

void apagarPaciente(char *nome) {
    int i;
    for (i = 0; i < numPacientes; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0) { // Procura pelo paciente com o nome fornecido
            pacientes[i].ativo = false;
            printf("Paciente %s foi apagado (marcado como inativo).\n", pacientes[i].nome);
            return;
        }
    }
    printf("Paciente não encontrado.\n");
}

// Função para restaurar um paciente previamente marcado como inativo

void restaurarPaciente(char *nome) {
    int i;
    for (i = 0; i < numPacientes; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0) { // Procura pelo paciente com o nome fornecido
            pacientes[i].ativo = true; // Marca o paciente como ativo novamente
            printf("Paciente %s foi restaurado.\n", pacientes[i].nome);
            return;
        }
    }
    printf("Paciente não encontrado.\n");
}

int main() {
    SetConsoleOutputCP(65001); // Ajuste para exibição correta de caracteres UTF-8 no Windows

    char nome[50];

    do {
        // Menu de opções para o usuário interagir com o sistema
        printf("\nSistema de Consulta Médica\n");
        printf("1. Incluir Paciente\n");
        printf("2. Alterar Paciente\n");
        printf("3. Realizar Consulta\n");
        printf("4. Listar Pacientes Ativos\n");
        printf("5. Mostrar Paciente\n");
        printf("6. Apagar Paciente\n");
        printf("7. Restaurar Paciente\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                incluirPaciente();
                break;
            case 2:
                printf("Digite o nome do paciente para alteração: ");
                scanf(" %[^\n]", nome);
                alterarPaciente(nome);
                break;
            case 3:
                printf("Digite o nome do paciente para realizar consulta: ");
                scanf(" %[^\n]", nome);
                realizarConsulta(nome);
                break;
            case 4:
                listarPacientes();
                break;
            case 5:
                printf("Digite o nome do paciente para mostrar detalhes: ");
                scanf(" %[^\n]", nome);
                mostrarPaciente(nome);
                break;
            case 6:
                printf("Digite o nome do paciente para apagar: ");
                scanf(" %[^\n]", nome);
                apagarPaciente(nome);
                break;
            case 7:
                printf("Digite o nome do paciente para restaurar: ");
                scanf(" %[^\n]", nome);
                restaurarPaciente(nome);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
