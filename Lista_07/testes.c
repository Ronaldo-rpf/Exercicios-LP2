#include <stdio.h>
#include <stdlib.h>

int guardaImagem (unsigned char** img, int lin, int col, char* fileName);

int main (){
    unsigned char** img;
    img = (unsigned char**) calloc(10, sizeof(unsigned char*));
    for (int i=0; i<10; i++){
        img[i] = (unsigned char*) calloc (10, sizeof(char));
    }


    for (int i=0;i<10;i++){
        for(int j=0; j<10;j++){
            img[i][j] = rand()%256;
        }
    }
    char nome[40];
    printf("Nome do arquivo: ");
    scanf("%s", nome);
    int aux = guardaImagem(img, 10, 10, nome);
    if (aux){
        printf ("Arquivo criado com sucesso.\n\n");
    }
    else{
        printf("Arquivo error.\n\n");
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
