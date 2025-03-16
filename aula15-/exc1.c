
# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    system("cls");

    int *p;
    p = (int*) malloc(4*sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        printf("Digite um numero para N%d: ",i);
        scanf("%d",p+i);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("O valor é N%d é %d\n",i+1, *(p+i));
    }
    

    // printf("Digite um numero: ");
    // scanf("%d",p);
    // printf("Digite um numero: ");
    // scanf("%d",p+1);
    // printf("Digite um numero: ");
    // scanf("%d",p+2);

    // printf("O valor é %d\n",*p);
    // printf("O valor é %d\n",*(p+1));
    // printf("O valor é %d\n",*(p+2));


    return 0;
}
