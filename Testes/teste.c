#include <stdio.h>
#include <stdlib.h>

int lenstr (char str[]);

int main (){
    char str[40];
    int qntd;
    printf("Escreve ai: ");
    gets(str);

    qntd = lenstr(str);

    printf("%d", qntd);



    return 0;
}

int lenstr (char str[]){
    int cont = 0;
    for (int i=0; str[i] != '\0'; i++){
        cont++;
    }
    return cont;
}