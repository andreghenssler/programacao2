
// André Gustavo Henssler
// Jogo da Velha
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
char tabela[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int linha,coluna, sorteio, jogador, escolha;
char jogadorUm, jogadorDois, opc;
 
//  Imprime o Jogo
void imprimirJogo(){
    // system("cls");
    int l,c;
    printf("Jogo da Velha\n");
    for(l=0;l<3;l++){
        for(c=0;c<3;c++){
            if(c == 0)
                printf("\t");
            printf(" %c ", tabela[l][c]);
            if(c<2){ // Adiciona a | na coluna 0 e 1
                printf("|");
            }
        }
        printf("\n");
        if(l<2)
            printf("\t----------\n");
    }
}

// Jogadores
void jogadores() {
    system("cls");
    srand(time(NULL));
    int sort = rand()%2+1; // Sorteio para ver quem escolhe X ou O
    printf("Jogador %d - Escolha entre X ou O: ", sort); // No sorteio o jogador escolhe qual é o seu
    scanf(" %c", &jogadorUm);
    setbuf(stdin,NULL);
    if(jogadorUm == 'X' || jogadorUm == 'x'){
        jogadorUm = 'X';
    }else{
        jogadorUm = 'O';
    }
    // Caso outro jogador, não escolhe X ou O o jogador ficar com a letra que sobrar
    jogadorDois = (jogadorUm == 'X' || jogadorUm == 'x') ? 'O' : 'X'; 
    printf("Jogador 1: %c\nJogador 2: %c\n", jogadorUm, jogadorDois);
    // Mostra qual jogador ficou x e O
}

int atualiza_jogador(){ // Atualiza o jogador
    srand(time(NULL));
    int sorteio = rand()%2+1;
    if(sorteio == 1){
        jogador = 2;
    }else{
        jogador = 1;
    }
}

// Verificará se o jogador ganhou por linha e retornará 1
int ganhou_linha(){
    int glinha = 0;
    for(linha = 0; linha<3;linha++){
        if((tabela[linha][0]=='X') &&  (tabela[linha][1]=='X') &&  (tabela[linha][2]=='X') ||
            (tabela[linha][0]=='O') &&  (tabela[linha][1]=='O') &&  (tabela[linha][2]=='O')){
                glinha = 1 ;
        }
    }
    return glinha;
}
// Verificará se o jogador ganhou por coluna e retornará 1
int ganhou_coluna(){
    int gcoluna = 0;
    if(
        (tabela[0][0]=='X') &&  (tabela[1][0]=='X') &&  (tabela[2][0]=='X') ||
        (tabela[1][0]=='X') &&  (tabela[1][1]=='X') &&  (tabela[2][1]=='X') ||
        (tabela[2][0]=='X') &&  (tabela[2][1]=='X') &&  (tabela[2][2]=='X') || 

        (tabela[0][0]=='O') &&  (tabela[1][0]=='O') &&  (tabela[2][0]=='O') ||
        (tabela[1][0]=='O') &&  (tabela[1][1]=='O') &&  (tabela[1][2]=='O') ||
        (tabela[2][0]=='O') &&  (tabela[2][1]=='O') &&  (tabela[2][2]=='O')    
    ){
        gcoluna = 1 ;
    }
    return gcoluna;
}
// Verificará se o jogador ganhou por diaconal principal e retornará 1
int ganhou_diacona_principal(){
    int gprincipal = 0;
    if(
        (tabela[0][0]== 'X') && (tabela[1][1]== 'X') && (tabela[2][2]== 'X') ||
        (tabela[0][0]== 'O') && (tabela[1][1]== 'O') && (tabela[2][2]== 'O')
    ){
        gprincipal = 1 ;
    }
    return gprincipal;
}
// Verificará se o jogador ganhou por diaconal segundario e retornará 1
int ganhou_diacona_segundario(){
    int gsegundario = 0;
    if(
        (tabela[0][2]== 'X') && (tabela[1][1]== 'X') && (tabela[2][0]== 'X') ||
        (tabela[0][2]== 'O') && (tabela[1][1]== 'O') && (tabela[2][0]== 'O')
    ){
        gsegundario = 1 ;
    }
    return gsegundario;
}

char jogarEm(char escolhas){
    printf("Jogador %c:\nDigite a posicao que deseja Jogar: ",escolhas);
    scanf("%c",&opc);
    setbuf(stdin,NULL);
    if (opc>0 && opc==9) {
        printf("Jogador %c:\nDigite novamente: ",escolhas);
        scanf("%c",&opc);
        setbuf(stdin,NULL);       
    }    
    return opc;
}

void posicao(){
    int mudarJogador;
    int rodada = 0;
    char escolhas ;
    mudarJogador = atualiza_jogador();
    imprimirJogo();
    do {
        if(mudarJogador == 1){
            escolhas = jogadorUm;
        }else{
            escolhas = jogadorDois;
        }
        opc = jogarEm(escolhas);
        switch (opc) {
            case '1':
                tabela[0][0] = escolhas;
                rodada+=1;
                break;
            case '2':
                tabela[0][1] = escolhas;
                rodada+=1;
                break;
            case '3':
                tabela[0][2] = escolhas;
                rodada+=1;
                break;
            case '4':
                tabela[1][0] = escolhas;
                rodada+=1;
                break;
            case '5':
                tabela[1][1] = escolhas;
                rodada+=1;
                break;
            case '6':
                tabela[1][2] = escolhas;
                rodada+=1;
                break;
            case '7':
                tabela[2][0] = escolhas;
                rodada+=1;
                break;
            case '8':
                tabela[2][1] = escolhas;
                rodada+=1;
                break;
            case '9':
                tabela[2][2] = escolhas;
                rodada+=1;
                break;
            default:
                printf("Numero invalido\n");
                break;  
        }
        
        imprimirJogo();
        if (ganhou_linha() || ganhou_coluna() || ganhou_diacona_principal() || ganhou_diacona_segundario()) {
            printf("Jogador %c venceu!\n", escolhas);
            break;
        }
        if(rodada == 9){
            printf("Empate\n");
            break;
        }
        if(mudarJogador == 1){
            mudarJogador +=1;
        }else{
            mudarJogador -=1;
        }
    } while (1);
    // resultado(escolhas);
}


int main(){
    SetConsoleOutputCP(65001);
    system("cls");
    srand(time(NULL));
    jogadores();
    posicao();

    return 0;
}
