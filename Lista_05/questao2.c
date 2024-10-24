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

    printf("Primeira data:\n\n");
    printf("Dia do aniversario: ");
    scanf("%d", &aniversario1.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &aniversario1.mes);
    
    printf("Ano do aniversario: ");
    scanf("%d", &aniversario1.ano);


    printf("Segunda data:\n\n");
    printf("Dia do aniversario: ");
    scanf("%d", &aniversario2.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &aniversario2.mes);
    
    printf("Ano do aniversario: ");
    scanf("%d", &aniversario2.ano);

    int valor = comparaDatas(aniversario1, aniversario2);

    printf("%d\n\n", valor);

    return 0;
}

int comparaDatas(data d1, data d2){
    if (d1.ano == d2.ano){
        if (d1.mes > d2.mes){
            return 1;
        }
        else if (d1.mes < d2.mes){
            return -1;
        }
        else{
            if (d1.dia > d2.dia){
                return 1;
            }
            else if (d1.dia == d2.dia){
                return 0;
            }
            else{
                return -1;
            }
        }
    }
    else if(d1.ano > d2.ano){
        return 1;
    }
    else{
        return -1;
    }
}