# include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_tabuleiro(char tabuleiro[3][3]) {
    printf("\n  1 2 3\n");
    printf(" -------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c|", tabuleiro[i][j]);
        }
        printf("\n -------\n");
    }
    printf("\n");
}

char verificar_vencedor(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }
    
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    return ' '; 
}

void jogada_computador(char tabuleiro[3][3], char letra_computador) {
    int linha, coluna;
    do {
        linha = rand() % 3;
        coluna = rand() % 3;
    } while (tabuleiro[linha][coluna] != ' '); 

    tabuleiro[linha][coluna] = letra_computador;
}

int main() {
    char tabuleiro[3][3]; 
    char jogador1, jogador2, letra_jogador_atual, letra_computador;
    int jogador_atual;
    char vencedor = ' ';

    srand(time(NULL)); 

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Escolha X ou O para jogar: ");
    scanf(" %c", &jogador1);
    jogador2 = (jogador1 == 'X') ? 'O' : 'X';

    
    jogador_atual = rand() % 2; 

    
    if (jogador_atual == 0) {
        letra_jogador_atual = jogador1;
        letra_computador = jogador2;
        printf("Voce comeca jogando.\n");
    } else {
        letra_jogador_atual = jogador2;
        letra_computador = jogador1;
        printf("O computador comeca jogando.\n");
    }

    
    while (vencedor == ' ') {
        imprimir_tabuleiro(tabuleiro);

        if (jogador_atual == 0 || (jogador_atual == 1 && letra_computador == 'X')) {
            
            int linha, coluna;
            printf("Jogador %c, sua vez (linha coluna): ", letra_jogador_atual);
            scanf("%d %d", &linha, &coluna);
            linha--; 
            coluna--;

           
            if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = letra_jogador_atual;
                jogador_atual = 1; 
            } else {
                printf("Jogada invalida. Tente novamente.\n");
                continue; 
            }
        } else {
            
            printf("Computador esta pensando...\n");
            jogada_computador(tabuleiro, letra_computador);
            jogador_atual = 0; 
        }

        
        vencedor = verificar_vencedor(tabuleiro);

        
        int tabuleiro_cheio = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == ' ') {
                    tabuleiro_cheio = 0;
                    break;
                }
            }
            if (!tabuleiro_cheio) {
                break;
            }
        }

        if (tabuleiro_cheio && vencedor == ' ') {
            vencedor = 'E'; 
        }
    }

    
    imprimir_tabuleiro(tabuleiro);
    if (vencedor == jogador1 || vencedor == jogador2) {
        printf("Jogador %c venceu!\n", vencedor);
    } else if (vencedor == 'E') {
        printf("Empate!\n");
    } else {
        printf("Computador venceu!\n");
    }

    return 0;
}