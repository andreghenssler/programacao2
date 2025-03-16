#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char tabela[3][3] = {'1','2','3','4','5','6','7','8','9'};
int ganhou = 0;
int l,c,linha,coluna;
int lugar;

void imprimirJogo(){
    printf("Jogo da Velha\n");
    for(l=0;l<3;l++){
        for(c=0;c<3;c++){
            if(c == 0)
                printf("\t");
            printf(" %c ", tabela[l][c]);
            if(c<2){
                printf("|");
            }
        }
        printf("\n");
        if(l<2)
            printf("\t----------\n");
    }
}

// int ganhou_linha(int l, char c){
//     if(tabela[l][0] == c && tabela[l][1] == c && tabela[l][2] == c ){
//         return 1;
//     }else{
//         return 0;
//     }
// }
// int ganhou_plinha(char c){
//     int ganhou = 0;
//     if(tabela[l][0] == c && tabela[l][1] == c && tabela[l][2] == c ){
//         ganhou += ganhou_linha(l, c);
//     }
//     return ganhou;
// }

// int ganhou_coulna(char j, int c){
//     if(tabela[0][c] == j && tabela[1][c] == j && tabela[2][c] == j ){
//         ganhou = 1;
//     }else{
//         ganhou = 0;
//     }
// }
// int ganhou_pcoluna(char j){
//     int ganhou = 0;
//     for(c= 0; c<3;c++){
//         ganhou += ganhou_coulna(c, j);
//     }
//     return ganhou;
// }

// int ganhou_diagonal_principal( char c){
//     if(tabela[0][0] == c && tabela[1][1] == c && tabela[2][2] == c){
//         return 1;
//     }else
//         return 0;
// }

int valido(int c){
    if(c>0 && c<10){
        return 1;
    }else{
        return 0;
    }  
}
void lerPosicao(){
    int posicao;
    printf("Digite a posição para jogar: ");
    scanf("%d",&posicao);
    while (valido(posicao) == 0) {
        printf("Lugar errado, tente novamente");
        printf("Digite a posição para jogar: ");
        scanf("%d",&posicao);
    }
    
    
}

void jogar(){
    system("cls");
    imprimirJogo();
    lerPosicao();
}


int main(){
    SetConsoleOutputCP(65001);
    
    jogar();
    return 0;
}
