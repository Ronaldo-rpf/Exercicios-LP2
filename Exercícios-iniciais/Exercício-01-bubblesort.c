#include <stdio.h>
#include <stdlib.h>

int main (){
    int num, qntd, aux, i, j, flag;
    int d[10];
    printf ("Digite um numero de ate 10 digitos: ");
    scanf ("%d", &num);

    aux = num;

    while (aux!=0){
        aux /= 10;
        qntd++;
    }
    for(i=qntd-1; i >= 0; i--){
        d[i] = num%10;
        num /= 10;
    }
    flag=1;
    while(flag){
        flag=0;
        for(i=0; i<qntd-1; i++){
            if(d[i] > d[i+1]){
                aux = d[i];
                d[i] = d[i+1];
                d[i+1] = aux;
                flag=1;
            }
        }
    }


    for(i=0; i<qntd; i++){
        printf("%d", d[i]);
    }





    return 0;
}
