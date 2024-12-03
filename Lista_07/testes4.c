#include <stdio.h>
#include <stdlib.h>

int main (){
    int aux, cont=0, vet[200] = {0};
    FILE *arq;
    arq = fopen("binario.txt", "rb");
    if (arq){
        for(int i =0; ; i++){
            if (fread (&vet[i] ,sizeof (int), 1, arq) != 1){
                break;
            }
            cont++;
        }
        int aux = fclose (arq);
        if (aux){
            printf("erro ao fechar arquivo binario.\n\n");
        }
    }
    else{
        printf("erro ao abrir arquivo binario.\n\n");
    }

    FILE *arq;
    arq = fopen();









    for (int i=0; i<cont; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}


