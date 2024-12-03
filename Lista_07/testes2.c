#include <stdio.h>
#include <stdlib.h>

int guardaImagem (unsigned char** img, int lin, int col, char* fileName);

unsigned char** carregaImagem (int *lin, int *col, char *fileName);

int main (){
    //unsigned char** img;
    //img = (unsigned char**) calloc(10, sizeof(unsigned char*));
    //for (int i=0; i<10; i++){
    //    img[i] = (unsigned char*) calloc (10, sizeof(char));
    //}
    unsigned char** img;
    int lin, col;
    char nome[40];
    printf("Nome do arquivo: ");
    scanf("%s", nome);

    img = carregaImagem(&lin, &col, nome);
    if (img == NULL){
        printf("Erro.\n\n");
        return 0;
    }

    for (int i=0;i<10;i++){
        for(int j=0; j<10;j++){
            printf("%3u ", img[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<10; i++){
        free(img[i]);
    }
    free(img);
    return 0;
}

int guardaImagem (unsigned char** img, int lin, int col, char* fileName){
    FILE *arq;
    arq = fopen(fileName, "w");
    if (arq){
        fprintf(arq, "%d %d\n", lin, col);
        for (int i=0; i<lin; i++){
            for (int j=0; j<col; j++){
                fprintf (arq, "%3u ", img[i][j]);
            }
            fprintf(arq, "\n");
        }
        int aux = fclose(arq);
        if (aux){
            return 0;
        }
        return 1;
    }
    else{
        return 0;
    }
}

unsigned char** carregaImagem (int *lin, int *col, char *fileName){
    FILE *arq;
    arq = fopen (fileName, "r");
    if (arq){
        fscanf (arq, "%u ", lin);
        fscanf (arq, "%u\n", col);
        unsigned char** pic;
        pic = (unsigned char**) calloc (*lin, sizeof(unsigned char*));
        for (int i=0; i<*lin; i++){
            pic[i] = (unsigned char*) calloc(*col, sizeof(unsigned char));
        }

        for (int i=0; i<*lin; i++){
            for (int j=0; j<*col; j++){
                fscanf(arq, "%3u ", &pic[i][j]);
            }
        }

        int aux = fclose(arq);
        if (aux){
            pic = NULL;
            for (int i=0; i<*lin; i++){
                pic[i] = NULL;
            }
            return pic;
        }
        else{
            return pic;
        }
    }
    else{
        return NULL;
    }
}
