unsigned char geraGreyPixel (int tipo){
    int i = rand() % 101;
    if (tipo == 0){
        return rand() % 257;
    }
    else if (tipo > 0){
        if (i <= 75){
            return 128 + (rand() % 129); 
        }
        else{
            return rand() % 129;
        }
    }
    else{
        if (i <= 75){
            return rand() % 129;
        }
        else{
            return 128 + (rand() % 129);
        }
    }
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

unsigned char* geraArray1D(int tam){
    return calloc(tam, sizeof(unsigned char));
}