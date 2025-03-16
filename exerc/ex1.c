/*
Escreva um trecho de código para fazer a criação dos novos tipos de dados conforme solicitado abaixo: 
Horário: composto de hora, minutos e segundos.
Data: composto de dia, mês e ano.
Compromisso: composto de uma data, horário e texto que descreve o compromisso.

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct horario{
    int hora;
    int min;
    int seg;
} hor1;
struct data{
   int dia;
   int mes;
   int ano;
} data1;


int main(){
    SetConsoleOutputCP(65001);
    system("cls");
    struct horario hor1;
    printf("Horario:\n");
    printf("Hora:\n");
    scanf("%d", &hor1.hora);
    setbuf(NULL);
    printf("Min:\n");
    scanf("%d", &hor1.min);
    setbuf(NULL);
    printf("Seg:\n");
    scanf("%d", &hor1.seg);
    setbuf(NULL);

    return 0;
}
