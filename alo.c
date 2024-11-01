#include <stdio.h>
#include <stdlib.h>

int** geraImagem(int lin, int col);

int main (){
    int** img;
    img = geraImagem(5,10);

    for (int i=0; i<5; i++){
        for (int j=0; j<10; j++){
            printf("%3d ", img[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<5;i++){
        free(img[i]);
    }
    free(img);
    return 0;
}

int** geraImagem(int lin, int col){
    int** img = (int**) calloc (lin, sizeof(int*));
    for (int i=0; i<lin;i++){
        img[i] = (int*) calloc (col, sizeof(int));
    }
    for (int i=0; i<lin; i++){
        for (int j=0; j<col; j++){
            img[i][j] = rand() % 256;
        }
    }
    return img;
}