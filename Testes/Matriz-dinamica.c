#include <stdio.h>
#include <stdlib.h>

int main (){
    int **matriz;
    int i = 5, j = 5;
    
    //um vetor que armazena ponteiros.

    matriz = (int **) calloc (i, sizeof(int *));
    for (int aux=0; aux<i; aux++){
        matriz[aux] = (int *) calloc (j, sizeof(int));
    }

    for (int aux=0; aux < i; aux++){
        for (int aux2 =0; aux2 < j; aux2++){
            printf ("%d  ", matriz[aux][aux2]);
        }
        printf ("\n");
    }




    for (int aux =0; aux<i; aux++){
        free(matriz[aux]);
    }
    free(matriz);

    system("PAUSE");
    return 0;
}
