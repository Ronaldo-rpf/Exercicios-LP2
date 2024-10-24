#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

int comparaDatas(data d1, data d2);

void criaDatas (data *dia, int tam);

int main (){
    srand (time(NULL));
    data *vet = (data*) calloc (10, sizeof(data));
    if (vet == NULL){
        printf("erro");
    }

    criaDatas(vet, 10);
 
    int aux, flag=1;
    data temp;

    while(flag){
        flag=0;
        for (int i = 0; i<9; i++){
            aux = comparaDatas(vet[i], vet[i+1]);
            if(aux == 1){
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                flag=1;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%02d/%02d/%d\n", vet[i].dia, vet[i].mes, vet[i].ano);
    }
    
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


void criaDatas (data *dia, int tam){
    for (int i = 0; i < tam; i++){
        dia[i].mes = 1 + rand() % 12;
        if (dia[i].mes == 1 || dia[i].mes==3 || dia[i].mes==5 || dia[i].mes==7 || dia[i].mes==8 || dia[i].mes==10 || dia[i].mes==12){
            dia[i].dia = 1 + rand() % 31;
        }
        else if(dia[i].mes == 2){
            dia[i].dia = 1 + rand() % 28;
        }
        else{
            dia[i].dia = 1 + rand() % 30;
        }
        dia[i].ano = 1960 + rand() % 65;
    }
    return;
}