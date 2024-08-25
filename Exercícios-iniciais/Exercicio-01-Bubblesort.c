#include <stdio.h>
#include <stdlib.h>

int main (){
    int num, aux, qntd=0, i, flag;
    int d[10];

    printf("Digite o numero a ser ordenado (ate 10 digitos): ");
    scanf("%d", &num);
    aux = num;

    while (aux!=0){
        aux /= 10;
        qntd++;
    }
    
    for (i=qntd-1; i>=0; i--){
        d[i] = num%10;
        num /= 10;
    }

    printf("Numero sem ordenacao: \n");
    for (i=0; i<qntd; i++){
        printf("%d", d[i]);
    }

    flag = 1;
    while (flag){
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
    
    printf("\n\n");
    printf("Numero com ordenacao: \n");
    for (i=0; i<qntd; i++){
        printf("%d", d[i]);
    }


    return 0;
}
