#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main (){

    srand(time(NULL));

    unsigned char **v;

    v = geraArray2D (5, 10);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%4u", v[i][j]);
        }
        printf("\n");
    }

    geraImgGreyFull_D(v, 5, 10, 230);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%4u", v[i][j]);
        }
        printf("\n");
    }

    geraImgGreyB_D (v, 5, 10);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%4u", v[i][j]);
        }
        printf("\n");
    }

    geraImgGrey_D (v, 5, 10, 1);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%4u", v[i][j]);
        }
        printf("\n");
    }
    
    printf ("\n%d\n\n", pixelMax_D(v, 5, 10));

    printf ("%d\n\n", pixelMin_D(v, 5, 10));

    unsigned char *somaLin = somaPorLinhas_D(v, 5, 10);

    for (int i = 0; i<5; i++){
        printf ("%u\n", somaLin[i]);
    }

    printf("\n");

    unsigned char *somaCol = somaPorColunas_D(v, 5, 10);

    for (int i = 0; i<10; i++){
        printf ("%u\n", somaCol[i]);
    }

    printf("\n\n\n");
    

    printf("%d\n\n", somaTotal_R(v, 5, 10));

    printf ("%d\n\n", quantosPixelsNaInt_D(v, 5, 10, 50));

    printf ("%d\n\n", quantosPixelsAbaixoDeInt_D(v, 5, 10, 50));

    printf ("%d\n\n", quantosPixelsAcimaDeInt_D(v, 5, 10, 50));





    free (somaCol);

    free (somaLin);

    for (int i=0; i < 5; i++){
        free (v[i]);
    }
    free(v);

    return 0;
}

