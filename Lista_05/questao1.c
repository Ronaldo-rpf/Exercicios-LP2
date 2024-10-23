#include <stdio.h>
#include <stdlib.h>

int main (){
    struct data{
        int dia;
        int mes;
        int ano;
    }aniversario;

    printf("Dia do aniversario: ");
    scanf("%d", &aniversario.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &aniversario.mes);
    
    printf("Ano do aniversario: ");
    scanf("%d", &aniversario.ano);

    printf("\n");
    if (aniversario.mes / 10 == 0){
        if (aniversario.dia / 10 == 0){
            printf("Data do seu aniversario: \n0%d/0%d/%d\n\n", aniversario.dia, aniversario.mes, aniversario.ano);
        }
        else{
            printf("Data do seu aniversario: \n%d/0%d/%d", aniversario.dia, aniversario.mes, aniversario.ano);
        }
    }
    else{
        if (aniversario.dia / 10 == 0){
            printf("Data do seu aniversario: \n0%d/%d/%d\n\n", aniversario.dia, aniversario.mes, aniversario.ano);
        }
        else{
            printf("Data do seu aniversario: \n%d/%d/%d", aniversario.dia, aniversario.mes, aniversario.ano);
        }
    }
    
    return 0;
}    