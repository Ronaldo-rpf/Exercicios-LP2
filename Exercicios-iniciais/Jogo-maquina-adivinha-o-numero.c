#include <stdio.h>
#include <stdlib.h>

int main (){
    int humano, maquina=0, min=0, max=100;

    printf("Qual valor entre 0 e 100 voce escolhe: ");
    scanf("%d", &humano);

    maquina = min + (max-min)/2;
    printf("Eu acho que e %d.\n", maquina);

    while (maquina != humano){
        if (maquina > humano){
            max = maquina-1;
        }
        else{
            min = maquina+1;
        }
        maquina = min + (max-min)/2;
        printf("Eu acho que e %d.\n", maquina);
    }


    printf("Acertei!!! o numero que voce escolheu foi %d\n\n", humano);


    return 0;
}
