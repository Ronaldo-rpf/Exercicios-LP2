#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int geraValorInt (int, int);
float geraValorFloat (float, float);
float geraValor01 ();

int main (){
    int min, max, x;
    float minF, maxF, y;

    srand(time(NULL));

    printf ("Valor minimo para o intervalo inteiro: ");
    scanf("%d", &min);
    printf ("Valor maximo para o intervalo inteiro: ");
    scanf("%d", &max);
    printf("\n");

    x = geraValorInt (min, max);

    printf ("Valor aleatorio entre o intervalo %d e %d e: %d\n\n", min, max, x);

    printf ("Valor minimo para o intervalo flutuante: ");
    scanf("%f", &minF);
    printf ("Valor maximo para o intervalo flutuante: ");
    scanf("%f", &maxF);
    printf("\n");

    y = geraValorFloat (minF, maxF);

    printf("Valor aleatorio entre o intervalo %f e %f e: %f", minF, maxF, y);
    printf("\n\n");

    printf("Valor aleatorio entre 0 e 1: %f\n\n", geraValor01());


    return 0;
}

int geraValorInt (int min, int max){
    return min + (rand()%(max-min+1));
}

float geraValorFloat (float min, float max){
    return min + (((rand()%RAND_MAX)*1.0)/RAND_MAX) * (max-min);
}

float geraValor01 (){
    return (rand()*1.0)/RAND_MAX;
}
