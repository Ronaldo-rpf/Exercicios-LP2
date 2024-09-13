#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcmp(char str1 [], char str2 []);
int strcmpaux (char str1[], char str2[], int n);

int main (){
    char str1[20], str2[20];
    printf("Escreva: ");
    gets(str1);
    printf("De novo: ");
    gets(str2);

    int aux = strcmp(str1, str2);

    printf("%d", aux);



    return 0;
}

int strcmp (char str1 [], char str2 []){
   return strcmpaux(str1, str2, 20);
}

int strcmpaux (char str1[], char str2[], int n){
    
    if (str1[n] == str2[n]){
        return 0;
    }
    if (str1[n] = '\0' && )
}

