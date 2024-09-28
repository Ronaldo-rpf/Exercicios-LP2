#include <stdio.h>
#include <stdlib.h>

unsigned char* geraArray1D(int tam);

int main (){
    unsigned char *v;

    v = geraArray1D (10);

    for (int i=0; i < 10; i++){
        printf("%u", v[i]);
    }

    free (v);
    return 0;
}

unsigned char* geraArray1D(int tam){
    return calloc(tam, sizeof(unsigned char));
 }


 #include <stdio.h>
#include <stdlib.h>

unsigned char** geraArray2D(int nLin, int nCol);

int main (){
    unsigned char **v;

    v = geraArray2D (5, 10);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%u", v[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i < 5; i++){
        free (v[i]);
    }
    free(v);

    return 0;
}

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **aux;
    aux = (unsigned char**) calloc (nLin, sizeof(unsigned char*));
    for(int i=0; i < nLin; i++){
        aux[i] = (unsigned char*) calloc (nCol, sizeof(unsigned char));
    }
    return aux;
}



#include <stdio.h>
#include <stdlib.h>

unsigned char** geraArray2D(int nLin, int nCol);
void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel);

int main (){
    unsigned char **v;

    v = geraArray2D (5, 10);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            printf("%u", v[i][j]);
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

    for (int i=0; i < 5; i++){
        free (v[i]);
    }
    free(v);

    return 0;
}

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **aux;
    aux = (unsigned char**) calloc (nLin, sizeof(unsigned char*));
    for(int i=0; i < nLin; i++){
        aux[i] = (unsigned char*) calloc (nCol, sizeof(unsigned char));
    }
    return aux;
}

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel){
    for (int i=0; i < nLin; i++){
        for(int j=0; j < nCol; j++){
            img[i][j] = pixel;
        }
    }
    return;
}


#include <stdio.h>
#include <stdlib.h>

unsigned char** geraArray2D(int nLin, int nCol);
int pixelMax_D(unsigned char** img, int nLin, int nCol);

int main (){
    unsigned char **v, maior;

    v = geraArray2D (5, 10);

    for (int i=0; i < 5; i++){
        for(int j=0; j < 10; j++){
            if (i=0){
                v[i][j] = 4;
            }
            if (i=1){
                v[i][j] = 5;
            }
            if (i=2){
                v[i][j] = 6;
            }
            if (i=3){
                v[i][j] = 7;
            }
            if (i=4){
                v[i][j] = 8;
            }
        }
    }
    v[4][9] = 230;

    maior = pixelMax_D(v, 5, 10);

    printf ("%u\n\n", maior);

    for (int i=0; i < 5; i++){
        free (v[i]);
    }
    free(v);

    return 0;
}

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **aux;
    aux = (unsigned char**) calloc (nLin, sizeof(unsigned char*));
    for(int i=0; i < nLin; i++){
        aux[i] = (unsigned char*) calloc (nCol, sizeof(unsigned char));
    }
    return aux;
}

int pixelMax_D(unsigned char** img, int nLin, int nCol){
    unsigned char maior = img[0][0];
    for (int i=0; i < nLin; i++){
        for(int j=0; j < nCol; j++){
            if (img[i][j] > maior){
                maior = img[i][j];
            }
        }
    }
    return maior;
}
