#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char str1[50];
    char str2[50];
    char cat[100];

    strcpy(str1,"texto da string1"); // insere o texto em str
    strcpy(str2," | nova parte do texto");

    bzero(cat, 100); // limpa a variavel cat

    strcat(cat, str2); // concatena valores em cat
    strcat(cat, str2);

    puts(cat);
}