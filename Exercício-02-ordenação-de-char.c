#include <stdio.h>
#include <stdlib.h>

int main (){
    char str[30];
    int i=0, qntdTotal=0, espaco=0, letras=0, aux, flag=1;
    printf("Digite algumas letras com espacos ou nao: ");
    gets(str);
    printf("Letras digitadas: ");
    puts(str);

    while (str[i] != '\0'){
        qntdTotal++;
        i++;
    }
    i=0;
    while (str[i] != '\0'){
        if(str[i] == ' '){
            espaco++;
        }
        else{
            letras++;
        }
        i++;
    }

    printf ("Quantidade de caracteres totais: %d\nQuantidade de espacos: %d\nQuantidade de letras: %d\n\n", qntdTotal, espaco, letras);

    i=0;

    while(flag){
        flag=0;
        for(i=0; str[i+1] != '\0'; i++){
            if(str[i] > str[i+1]){
                aux = str[i];
                str[i] = str[i+1];
                str[i+1] = aux;
                flag=1;
            }
        }
    }

    printf("Letras ordenadas: ");
    for (i=0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }

    printf("\n\n");

    return 0;
}
