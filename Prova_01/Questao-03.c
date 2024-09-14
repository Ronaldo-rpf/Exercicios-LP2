#include <stdio.h>
#include <stdlib.h>

int quantCh (char str[], char ch);

int main (){
    char str[40] = "Atividade Avaliativa", ch = 't';
    int qntd;

    qntd = quantCh (str, ch);

    printf("O caractere %c aparece %d vezes na string.\n\n", ch, qntd);

    return 0;
}

int quantCh (char str[], char ch){
    int i, cont = 0;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == ch){
            cont++;
        }
    }
    return cont;
}