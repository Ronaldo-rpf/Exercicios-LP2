#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

int comparaDatas(data d1, data d2);

int main (){
    data aniversario1, aniversario2;

    printf("Primeira data:");
    printf("Dia do aniversario: ");
    scanf("%d", &aniversario1.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &aniversario1.mes);
    
    printf("Ano do aniversario: ");
    scanf("%d", &aniversario1.ano);


    printf("Segunda data:");
    printf("Dia do aniversario: ");
    scanf("%d", &aniversario2.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &aniversario2.mes);
    
    printf("Ano do aniversario: ");
    scanf("%d", &aniversario2.ano);






    
    return 0;
}