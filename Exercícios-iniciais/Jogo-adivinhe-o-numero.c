#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int humano, maquina, min, max, tentativas=1;
    srand(time(NULL));

    printf("Diga o minimo valor do intervalo: ");
    scanf("%d", &min);
    printf("Diga o maximo valor do intervalo: ");
    scanf("%d", &max);
    maquina = min + (rand()%(max-min+1));


    printf("Escolhi um numero dentre esse intervalo.\n");
    printf("Diga um numero nesse intervalo: ");
    scanf("%d", &humano);
    while (humano != maquina){
        if (humano > maquina){
            printf("Esse valor e maior do que o numero sorteado.\n");
        }
        else {
            printf("Esse valor e menor do que o numero sorteado.\n");
        }
        printf("Diga outro numero nesse intervalo: ");
        scanf("%d", &humano);
        tentativas++;
    }

    printf ("Parabens! Voce acertou o numero depois de %d tentativas!!!\n\n", tentativas);

    return 0;
}
