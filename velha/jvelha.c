// Jogo da Velha.
// https://sites.icmc.usp.br/andretta/ensino/aulas/sme0230-1-20/jogodavelha.c

#include <stdio.h>
#include <stdlib.h>

// Funcao que limpa a tela e imprime o tabuleiro.

void imprime_tabuleiro(char tabuleiro[3][3]) {
  system("clear"); // para windows: system("cls");
  printf(" %c | %c | %c\n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);

  return;
}

// Funcao principal

int main() {
  char tabuleiro[3][3],jogador;
  int i,j,linha,coluna,rodada,ganhou;

  // Deixa o tabuleiro inicial vazio.
  
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' ';
    }
  }

  // Imprime o tabuleiro
  
  imprime_tabuleiro(tabuleiro);
  
  // O valor de ganhou eh:
  // 0, se ninguem ganhou;
  // 1, se alguem ganhou.
  // Define que ninguem ganhou ainda.

  ganhou = 0;

  // Laco para fazer jogadas enquanto nenhum jogador ganha e
  // o tabuleiro nao foi completamente preenchido.
  
  for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {

    // Define o jogador da rodada.
    
    if (rodada % 2 == 1) {
      jogador = 'X';
    }
    else {
      jogador = 'O';
    }
    
    // Le a jogada de um jogador.
    // Soh permite linha entre 1 e 3, coluna entre 1 e 3 e
    // posicao do tabuleiro vazia.
    
    do {
      printf("Digite as coordenadas (de 1 a 3) em que quer colocar o '%c': ", jogador);
      scanf("%d %d", &linha, &coluna);
    } while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ');
    
    // Faz a jogada do jogador.
    
    tabuleiro[linha-1][coluna-1] = jogador;
    
    // Imprime o tabuleiro
    
    imprime_tabuleiro(tabuleiro);

    // Verifica se o jogador ganhou.
    // Verifica se a linha onde jogou esta toda com o mesmo marcador.
    
    if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2]) {
      ganhou = 1;
    }
    else {

      // Verifica se a coluna onde jogou esta toda com o mesmo marcador.

      if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1]) {
	ganhou = 1;
      }

      else {

	// Verifica se jogou na diagonal principal e se todos os marcadores dela sao iguais.
	
	if (linha == coluna && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro [1][1] == tabuleiro[2][2]) {
	  ganhou = 1;
	}
	else {
	  // Verifica se jogou na diagonal secundaria e se todos os marcadores dela sao iguais.
	  if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
	    ganhou = 1;
	  }
	}
      }
    }

  }

  // Imprime mensagem final, dizendo se houve empate ou
  // se alguem (quem) ganhou.
  
  if (ganhou == 0) {
    printf("\nDeu velha!\n");
  }
  else {
    printf("\nO jogador '%c' ganhou!\n", jogador);
  }
  
  return(0);
}