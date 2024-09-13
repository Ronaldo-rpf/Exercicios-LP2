#include <stdio.h>
#include <stdlib.h>

int strcmpRec(char str1[], char str2 [], int n);

int main (){
    char str1[20], str2[20];
    int qntd;

    printf("1: ");
    gets(str1);
    printf("2: ");
    gets(str2);

    qntd = strcmpRec(str1, str2, 0);

    printf ("Resultado: %d", qntd);

    return 0;
}

int strcmpRec (char str1[], char str2[], int n){

    if (str1[n] == '\0' && str2[n] == '\0'){
        return 0;
    }
    if (str1[n] == str2[n]){
        return strcmpRec(str1, str2, n+1);
    }
    else if(str1[n] > str2[n]){
        return 1;
    }
    else{
        return -1;
    }
}
